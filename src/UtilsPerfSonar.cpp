/*
 * FileProcess.cpp
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#include "UtilsPerfSonar.h"
#include "UtilsJson.h"

using boost::property_tree::ptree;
using namespace std;


UtilsPerfSonar::UtilsPerfSonar() {
	// Auto-generated constructor stub

}
UtilsPerfSonar::~UtilsPerfSonar() {
	// Auto-generated destructor stub
}

void UtilsPerfSonar::parserJson(string stringFile){

	boost::property_tree::ptree pt;
	std::stringstream fileToRead;

	fileToRead << "{\"root\":" << stringFile << "}";

	boost::property_tree::read_json(fileToRead,  pt);

	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("root")){
		UtilsJson::summaryJson arrayJson;

		arrayJson.summary_Json = v.second.get<std::string>("summary");
		arrayJson.id_Json = v.second.get("id",0);
		arrayJson.monitor_Json = v.second.get<std::string>("monitor");
		arrayJson.source_Json = v.second.get<std::string>("source");
		arrayJson.status_Json = v.second.get("status",0);
		arrayJson.lastCheckTime_Json = v.second.get<std::string>("lastCheckTime");
		arrayJson.destination_Json = v.second.get<std::string>("destination");

		arrayJson.avg_Json.unit = v.second.get<string>("parameters.Throughput Avg.unit");
		arrayJson.avg_Json.description = v.second.get<string>("parameters.Throughput Avg.description");
		arrayJson.avg_Json.value = v.second.get<float>("parameters.Throughput Avg.value");

		arrayJson.max_Json.unit = v.second.get<string>("parameters.Throughput Max.unit");
		arrayJson.max_Json.description = v.second.get<string>("parameters.Throughput Max.description");
		arrayJson.max_Json.value = v.second.get<float>("parameters.Throughput Max.value");

		arrayJson.min_Json.unit = v.second.get<string>("parameters.Throughput Min.unit");
		arrayJson.min_Json.description = v.second.get<string>("parameters.Throughput Min.description");
		arrayJson.min_Json.value = v.second.get<float>("parameters.Throughput Min.value");

		arrayJson.sigma_Json.unit = v.second.get<string>("parameters.Sigma.unit");
		arrayJson.sigma_Json.description = v.second.get<string>("parameters.Sigma.description");
		arrayJson.sigma_Json.value = v.second.get<float>("parameters.Sigma.value");

		UtilsJson infoJson(arrayJson);
		this->fileData.push_back(infoJson);
	}
}

INetworkLink::NetworkLinkInfo UtilsPerfSonar::getInfo(std::string source, std::string dest){
	this->myInfoBufferTCP.origin = source.c_str();
	this->myInfoBufferTCP.destination = dest.c_str();

	string url = "http://perfsonar.racf.bnl.gov:8080/exda";
	string infoLink;
	CURL *curl;
	CURLcode res;
	string directionUrl;

	//Correct url where do you want to connect
	directionUrl = url + "/results?action=getServices&source="+this->myInfoBufferTCP.origin+"&destination="+this->myInfoBufferTCP.destination;

	curl = curl_easy_init();
	if(curl) {
	curl_easy_setopt(curl, CURLOPT_URL, directionUrl.c_str());
	/* Tell libcurl to follow directionUrl */
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); //To store the output
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &infoLink); //Data pointer to pass to the file write function
	/* Perform the request, res will get the return code */
	res = curl_easy_perform(curl);
	/* Check for errors */
	if(res != CURLE_OK)
	  fprintf(stderr, "curl_easy_perform() failed: %s\n",
			  curl_easy_strerror(res));

	/* always cleanup */
	curl_easy_cleanup(curl);
	}

	this->parserJson(infoLink);
	this->myInfoBufferTCP.RTT = this->getRTT();
	this->myInfoBufferTCP.throughPulling = this->getThroughputPulling();
	this->myInfoBufferTCP.throughPushing = this->getThroughputPushing();

	return this->myInfoBufferTCP;
}

size_t UtilsPerfSonar::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::ostream& operator<<(std::ostream &out, UtilsPerfSonar& fp){
	list<UtilsJson>::iterator tmpIterator;

	for ( tmpIterator = fp.fileData.begin(); tmpIterator != fp.fileData.end(); tmpIterator++){
		UtilsJson auxToPrint(tmpIterator->getStructure());
		out << auxToPrint;
	}
	return out;
}

float UtilsPerfSonar::getThroughputPushing(){
	list<UtilsJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		if(tmpIterator->isThroughput() && tmpIterator->isPushorPull()){
			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}

float UtilsPerfSonar::getThroughputPulling(){
	list<UtilsJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		if(tmpIterator->isThroughput() && !tmpIterator->isPushorPull()){
			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}

float UtilsPerfSonar::getRTT(){
	return 60; //Default 60ms until have the correct value
}
