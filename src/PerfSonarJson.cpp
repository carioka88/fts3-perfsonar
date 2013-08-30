/*
 * PerfSonarJson.cpp
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */


#include "PerfSonarJson.h"


using boost::property_tree::ptree;
using namespace std;

const char* PerfSonarJson::throughput = "PS_CHECK_THROUGHPUT OK";

PerfSonarJson::PerfSonarJson() {
}

PerfSonarJson::~PerfSonarJson() {
}
///Constructor with parameters
PerfSonarJson::PerfSonarJson(summaryJson newInfo): myInfo(newInfo){}

PerfSonarJson::summaryJson PerfSonarJson::getStructure(){
	return this->myInfo;
}

std::ostream& operator<<(std::ostream &out, PerfSonarJson& fp){

	out << fp.myInfo.summary_Json << endl;
	out << fp.myInfo.id_Json << endl;
	out << fp.myInfo.monitor_Json << endl;
	out << fp.myInfo.source_Json << endl;
	out << fp.myInfo.status_Json << endl;
	out << fp.myInfo.lastCheckTime_Json << endl;

	out << fp.myInfo.avg_Json.description << endl;
	out << fp.myInfo.avg_Json.unit << endl;
	out << fp.myInfo.avg_Json.value << endl;

	out << fp.myInfo.max_Json.description << endl;
	out << fp.myInfo.max_Json.unit << endl;
	out << fp.myInfo.max_Json.value << endl;

	out << fp.myInfo.min_Json.description << endl;
	out << fp.myInfo.min_Json.unit << endl;
	out << fp.myInfo.min_Json.value << endl;

	out << fp.myInfo.sigma_Json.description << endl;
	out << fp.myInfo.sigma_Json.unit << endl;
	out << fp.myInfo.sigma_Json.value << endl;

	out << fp.myInfo.destination_Json << endl;
	out << endl;
	return out;
}

//Return true or false if find the string "PS_CHECK_THROUGHPUT OK"
bool PerfSonarJson::isThroughput(){
	return (this->myInfo.summary_Json.find(throughput) != std::string::npos);
}

//Return true or false if source and monitor are the same
bool PerfSonarJson::isPushorPull(){
	return (this->myInfo.source_Json.compare(this->myInfo.monitor_Json) == 0);
}

string PerfSonarJson::getMonitor(){
	return this->myInfo.monitor_Json;
}

string PerfSonarJson::getSource(){
	return this->myInfo.source_Json;
}

string PerfSonarJson::getDestination(){
	return this->myInfo.destination_Json;
}

float PerfSonarJson::getAvg(){
	return this->myInfo.avg_Json.value;
}

float PerfSonarJson::getMax(){
	return this->myInfo.max_Json.value;
}

float PerfSonarJson::getMin(){
	return this->myInfo.max_Json.value;
}

void PerfSonarJson::setAvg(float avg){
	this->myInfo.avg_Json.value = avg;
}

void PerfSonarJson::setAvgDescription(std::string avg_description){
	this->myInfo.avg_Json.description = avg_description;
}

void PerfSonarJson::setAvgUnit(std::string avg_unit){
	this->myInfo.avg_Json.unit = avg_unit;
}

void PerfSonarJson::setMax(float max){
	this->myInfo.max_Json.value = max;
}

void PerfSonarJson::setMaxDescription(std::string max_description){
	this->myInfo.max_Json.description = max_description;
}

void PerfSonarJson::setMaxUnit(std::string max_unit){
	this->myInfo.max_Json.unit = max_unit;
}

void PerfSonarJson::setMin(float min){
	this->myInfo.min_Json.value = min;
}

void PerfSonarJson::setMinDescription(std::string min_description){
	this->myInfo.min_Json.description = min_description;
}

void PerfSonarJson::setMinUnit(std::string min_unit){
	this->myInfo.min_Json.unit = min_unit;
}

void PerfSonarJson::setSigma(float sigma){
	this->myInfo.sigma_Json.value = sigma;
}

void PerfSonarJson::setSigmaDescription(std::string sigma_description){
	this->myInfo.sigma_Json.description = sigma_description;
}

void PerfSonarJson::setSigmaUnit(std::string sigma_unit){
	this->myInfo.sigma_Json.unit = sigma_unit;
}

void PerfSonarJson::setId(int id_Json){
	this->myInfo.id_Json = id_Json;
}
void PerfSonarJson::setMonitor(std::string monitor_Json){
	this->myInfo.monitor_Json = monitor_Json;
}
void PerfSonarJson::setSource(std::string source_Json){
	this->myInfo.source_Json = source_Json;
}
void PerfSonarJson::setStatus(int status_Json){
	this->myInfo.status_Json = status_Json;
}
void PerfSonarJson::setCheckTime(std::string lastCheckTime_Json){
	this->myInfo.lastCheckTime_Json = lastCheckTime_Json;
}
void PerfSonarJson::setDestination(std::string destination_Json){
	this->myInfo.destination_Json = destination_Json;
}

void PerfSonarJson::setSummary(std::string summary){
	this->myInfo.summary_Json = summary;
}
