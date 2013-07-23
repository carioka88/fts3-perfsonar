/*
 * manageJson.cpp
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#include "ManageJson.h"


using boost::property_tree::ptree;
using namespace std;

ManageJson::ManageJson() {
	// Auto-generated constructor stub
}

ManageJson::~ManageJson() {
	// Auto-generated destructor stub
}
///Constructor with parameters
ManageJson::ManageJson(summaryJson newInfo): myInfo(newInfo){}

ManageJson::summaryJson ManageJson::getStructure(){
	summaryJson myStructInfo;

	myStructInfo.avg_File.description = this->myInfo.avg_File.description;
	myStructInfo.avg_File.unit = this->myInfo.avg_File.unit;
	myStructInfo.avg_File.value = this->myInfo.avg_File.value;

	myStructInfo.max_File.description = this->myInfo.max_File.description;
	myStructInfo.max_File.unit = this->myInfo.max_File.unit;
	myStructInfo.max_File.value = this->myInfo.max_File.value;

	myStructInfo.min_File.description = this->myInfo.min_File.description;
	myStructInfo.min_File.unit = this->myInfo.min_File.unit;
	myStructInfo.min_File.value = this->myInfo.min_File.value;

	myStructInfo.sigma_File.description = this->myInfo.sigma_File.description;
	myStructInfo.sigma_File.unit = this->myInfo.sigma_File.unit;
	myStructInfo.sigma_File.value = this->myInfo.sigma_File.value;

	myStructInfo.destination = this->myInfo.destination;
	myStructInfo.id_File = this->myInfo.id_File;
	myStructInfo.lastCheckTime_File = this->myInfo.lastCheckTime_File;
	myStructInfo.monitor_File = this->myInfo.monitor_File;
	myStructInfo.source_File = this->myInfo.source_File;
	myStructInfo.status = this->myInfo.status;
	myStructInfo.summary_File = this->myInfo.summary_File;

	return myStructInfo;
}

/*
 * @param summaryJson SummaryJson that modify the values of a manageJson's class
 * */
void ManageJson::setStructure(summaryJson newInfo){
	this->myInfo.avg_File.description = newInfo.avg_File.description;
	this->myInfo.avg_File.unit = newInfo.avg_File.unit;
	this->myInfo.avg_File.value = newInfo.avg_File.value;

	this->myInfo.max_File.description = newInfo.max_File.description;
	this->myInfo.max_File.unit = newInfo.max_File.unit;
	this->myInfo.max_File.value = newInfo.max_File.value;

	this->myInfo.min_File.description = newInfo.min_File.description;
	this->myInfo.min_File.unit = newInfo.min_File.unit;
	this->myInfo.min_File.value = newInfo.min_File.value;

	this->myInfo.sigma_File.description = newInfo.sigma_File.description;
	this->myInfo.sigma_File.unit = newInfo.sigma_File.unit;
	this->myInfo.sigma_File.value = newInfo.sigma_File.value;

	this->myInfo.destination = newInfo.destination;
	this->myInfo.id_File = newInfo.id_File;
	this->myInfo.lastCheckTime_File = newInfo.lastCheckTime_File;
	this->myInfo.monitor_File = newInfo.monitor_File;
	this->myInfo.source_File = newInfo.source_File;
	this->myInfo.status = newInfo.status;
	this->myInfo.summary_File = newInfo.summary_File;
}

std::ostream& operator<<(std::ostream &out, ManageJson& fp){

	out << fp.myInfo.summary_File << endl;
	out << fp.myInfo.id_File << endl;
	out << fp.myInfo.monitor_File << endl;
	out << fp.myInfo.source_File << endl;
	out << fp.myInfo.status << endl;
	out << fp.myInfo.lastCheckTime_File << endl;

	out << fp.myInfo.avg_File.description << endl;
	out << fp.myInfo.avg_File.unit << endl;
	out << fp.myInfo.avg_File.value << endl;

	out << fp.myInfo.max_File.description << endl;
	out << fp.myInfo.max_File.unit << endl;
	out << fp.myInfo.max_File.value << endl;

	out << fp.myInfo.min_File.description << endl;
	out << fp.myInfo.min_File.unit << endl;
	out << fp.myInfo.min_File.value << endl;

	out << fp.myInfo.sigma_File.description << endl;
	out << fp.myInfo.sigma_File.unit << endl;
	out << fp.myInfo.sigma_File.value << endl;

	out << fp.myInfo.destination << endl;
	out << endl;
	return out;
}

//Return true or false if find the string "PS_CHECK_THROUGHPUT OK"
bool ManageJson::isThroughput(){
	string throughput = "PS_CHECK_THROUGHPUT OK";

	return (this->myInfo.summary_File.find(throughput) != std::string::npos);
}

//Return true or false if source and monitor are the same
bool ManageJson::isPushorPull(){
	//cout << "Source: " << this->myInfo.source_File << endl;
	//cout << "Monitor: " << this->myInfo.monitor_File << endl;

	return (this->myInfo.source_File.compare(this->myInfo.monitor_File) == 0);
}

string ManageJson::getMonitor(){
	return this->myInfo.monitor_File;
}

string ManageJson::getSource(){
	return this->myInfo.source_File;
}

string ManageJson::getDestination(){
	return this->myInfo.destination;
}

float ManageJson::getAvg(){
	return this->myInfo.avg_File.value;
}

float ManageJson::getMax(){
	return this->myInfo.max_File.value;
}

float ManageJson::getMin(){
	return this->myInfo.max_File.value;
}
