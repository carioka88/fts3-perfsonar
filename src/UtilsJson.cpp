/*
 * manageJson.cpp
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#include "UtilsJson.h"


using boost::property_tree::ptree;
using namespace std;

UtilsJson::UtilsJson() {
	// Auto-generated constructor stub
}

UtilsJson::~UtilsJson() {
	// Auto-generated destructor stub
}
///Constructor with parameters
UtilsJson::UtilsJson(summaryJson newInfo): myInfo(newInfo){}

UtilsJson::summaryJson UtilsJson::getStructure(){
	return this->myInfo;
}

std::ostream& operator<<(std::ostream &out, UtilsJson& fp){

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
bool UtilsJson::isThroughput(){
	string throughput = "PS_CHECK_THROUGHPUT OK";

	return (this->myInfo.summary_Json.find(throughput) != std::string::npos);
}

//Return true or false if source and monitor are the same
bool UtilsJson::isPushorPull(){
	//cout << "Source: " << this->myInfo.sourceJson << endl;
	//cout << "Monitor: " << this->myInfo.monitorJson << endl;

	return (this->myInfo.source_Json.compare(this->myInfo.monitor_Json) == 0);
}

string UtilsJson::getMonitor(){
	return this->myInfo.monitor_Json;
}

string UtilsJson::getSource(){
	return this->myInfo.source_Json;
}

string UtilsJson::getDestination(){
	return this->myInfo.destination_Json;
}

float UtilsJson::getAvg(){
	return this->myInfo.avg_Json.value;
}

float UtilsJson::getMax(){
	return this->myInfo.max_Json.value;
}

float UtilsJson::getMin(){
	return this->myInfo.max_Json.value;
}
