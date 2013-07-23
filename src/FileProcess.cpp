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

void FileProcess::parserJson(string stringFile){

	boost::property_tree::ptree pt;
	std::stringstream fileToRead;

	fileToRead << "{\"root\":" << stringFile << "}";

	boost::property_tree::read_json(fileToRead,  pt);

	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("root")){
		ManageJson::summaryJson arrayJson;

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

		ManageJson infoJson(arrayJson);
		this->fileData.push_back(infoJson);
	}
}

std::ostream& operator<<(std::ostream &out, FileProcess& fp){
	list<ManageJson>::iterator tmpIterator;

	for ( tmpIterator = fp.fileData.begin(); tmpIterator != fp.fileData.end(); tmpIterator++){
		ManageJson auxToPrint(tmpIterator->getStructure());
		out << auxToPrint;
	}
	return out;
}

float FileProcess::getThroughputPushing(){
	list<ManageJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		if(tmpIterator->isThroughput() && tmpIterator->isPushorPull()){
			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}

float FileProcess::getThroughputPulling(){
	list<ManageJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		if(tmpIterator->isThroughput() && !tmpIterator->isPushorPull()){
			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}
