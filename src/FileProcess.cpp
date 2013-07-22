/*
 * FileProcess.cpp
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#include "FileProcess.h"
#include "ManageJson.h"
using boost::property_tree::ptree;
using namespace std;


FileProcess::FileProcess() {
	// Auto-generated constructor stub

}

FileProcess::~FileProcess() {
	// Auto-generated destructor stub
}

void FileProcess::readFileJson(stringstream stringFile){

	boost::property_tree::ptree pt;
	boost::property_tree::read_json(stringFile,  pt);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("root")){
		manageJson::summaryJson arrayJson;

		arrayJson.summary_File = v.second.get<std::string>("summary");
		arrayJson.id_File = v.second.get("id",0);
		arrayJson.monitor_File = v.second.get<std::string>("monitor");
		arrayJson.source_File = v.second.get<std::string>("source");
		arrayJson.status = v.second.get("status",0);
		arrayJson.lastCheckTime_File = v.second.get<std::string>("lastCheckTime");
		arrayJson.destination = v.second.get<std::string>("destination");

		arrayJson.avg_File.unit = v.second.get<string>("parameters.Throughput Avg.unit");
		arrayJson.avg_File.description = v.second.get<string>("parameters.Throughput Avg.description");
		arrayJson.avg_File.value = v.second.get<float>("parameters.Throughput Avg.value");

		arrayJson.max_File.unit = v.second.get<string>("parameters.Throughput Max.unit");
		arrayJson.max_File.description = v.second.get<string>("parameters.Throughput Max.description");
		arrayJson.max_File.value = v.second.get<float>("parameters.Throughput Max.value");

		arrayJson.min_File.unit = v.second.get<string>("parameters.Throughput Min.unit");
		arrayJson.min_File.description = v.second.get<string>("parameters.Throughput Min.description");
		arrayJson.min_File.value = v.second.get<float>("parameters.Throughput Min.value");

		arrayJson.sigma_File.unit = v.second.get<string>("parameters.Sigma.unit");
		arrayJson.sigma_File.description = v.second.get<string>("parameters.Sigma.description");
		arrayJson.sigma_File.value = v.second.get<float>("parameters.Sigma.value");

		manageJson infoJson(arrayJson);
		this->fileData.push_back(infoJson);
	}
}

void FileProcess::print()
{
    list<manageJson>::iterator tmpIterator;
	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		tmpIterator->printInfo();
	}
	cout << endl;
}

float FileProcess::getThroughputPushing(){
	list<manageJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		if(tmpIterator->checkSummary() && tmpIterator->checkPushPull()){
			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}

float FileProcess::getThroughputPulling(){
	list<manageJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		if(tmpIterator->checkSummary() && !tmpIterator->checkPushPull()){
			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}
