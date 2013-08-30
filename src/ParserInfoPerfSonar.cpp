/*
 * FileProcess.cpp
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#include "ParserInfoPerfSonar.h"

using boost::property_tree::ptree;
using namespace std;

const char *ParserInfoPerfSonar::sourceURL = "/results?action=getServices&source=";
const char *ParserInfoPerfSonar::destinationURL = "&destination=";

ParserInfoPerfSonar::ParserInfoPerfSonar() {
	// Auto-generated constructor stub

}
ParserInfoPerfSonar::~ParserInfoPerfSonar() {
	// Auto-generated destructor stub
}

void ParserInfoPerfSonar::parserJson(string stringFile){

	boost::property_tree::ptree pt;
	std::stringstream fileToRead;

	//Is needed to can read correctly the json's file
	fileToRead << "{\"root\":" << stringFile << "}";

	boost::property_tree::read_json(fileToRead,  pt);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("root")){
		//UtilsJson::summaryJson arrayJson;

		PerfSonarJson arrayJson;
		arrayJson.setSummary(v.second.get<std::string>("summary"));
		arrayJson.setId((int)v.second.get("id",0));
		arrayJson.setMonitor(v.second.get<std::string>("monitor"));
		arrayJson.setSource(v.second.get<std::string>("source"));
		arrayJson.setStatus((int)v.second.get("status",0));
		arrayJson.setCheckTime(v.second.get<std::string>("lastCheckTime"));
		arrayJson.setDestination(v.second.get<std::string>("destination"));

		arrayJson.setAvgUnit(v.second.get<string>("parameters.Throughput Avg.unit"));
		arrayJson.setAvgDescription(v.second.get<string>("parameters.Throughput Avg.description"));
		arrayJson.setAvg(v.second.get<float>("parameters.Throughput Avg.value"));

		arrayJson.setMaxUnit(v.second.get<string>("parameters.Throughput Max.unit"));
		arrayJson.setMaxDescription(v.second.get<string>("parameters.Throughput Max.description"));
		arrayJson.setMax(v.second.get<float>("parameters.Throughput Max.value"));

		arrayJson.setMinUnit(v.second.get<string>("parameters.Throughput Min.unit"));
		arrayJson.setMinDescription(v.second.get<string>("parameters.Throughput Min.description"));
		arrayJson.setMin(v.second.get<float>("parameters.Throughput Min.value"));

		arrayJson.setSigmaUnit(v.second.get<string>("parameters.Sigma.unit"));
		arrayJson.setSigmaDescription(v.second.get<string>("parameters.Sigma.description"));
		arrayJson.setSigma(v.second.get<float>("parameters.Sigma.value"));

		//UtilsJson infoJson(arrayJson);
		this->fileData.push_back(arrayJson);
	}
}

INetworkLink::NetworkLinkInfo ParserInfoPerfSonar::getInfo(std::string source, std::string dest){
	this->myInfoBufferTCP.origin = source.c_str();
	this->myInfoBufferTCP.destination = dest.c_str();

	string url = "http://perfsonar.racf.bnl.gov:8080/exda";
	string infoLink;
	CURL *curl;
	CURLcode res;
	string directionUrl;

	//Correct url where do you want to connect
	directionUrl = url + sourceURL + this->myInfoBufferTCP.origin + destinationURL + this->myInfoBufferTCP.destination;
	//directionUrl = url + "/results?action=getServices&source=" + this->myInfoBufferTCP.origin + "&destination=" + this->myInfoBufferTCP.destination;

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

size_t ParserInfoPerfSonar::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::ostream& operator<<(std::ostream &out, ParserInfoPerfSonar& fp){
	list<PerfSonarJson>::iterator tmpIterator;

	for ( tmpIterator = fp.fileData.begin(); tmpIterator != fp.fileData.end(); tmpIterator++){
		PerfSonarJson auxToPrint(tmpIterator->getStructure());
		out << auxToPrint;
	}
	return out;
}

float ParserInfoPerfSonar::getThroughputPushing(){
	list<PerfSonarJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		if(tmpIterator->isThroughput() && tmpIterator->isPushorPull()){
			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}

float ParserInfoPerfSonar::getThroughputPulling(){
	list<PerfSonarJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = this->fileData.begin(); tmpIterator != this->fileData.end(); tmpIterator++){
		if(tmpIterator->isThroughput() && !tmpIterator->isPushorPull()){
			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}

float ParserInfoPerfSonar::getRTT(){
	return 60; //Default 60ms until have the correct value
}

void ParserInfoPerfSonar::setPush(float n){
	std::cout << this->myInfoBufferTCP.throughPushing << std::endl;
	this->myInfoBufferTCP.throughPushing = n;

	std::cout << this->myInfoBufferTCP.throughPushing << std::endl;
}
