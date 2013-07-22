/*
 * manageJson.cpp
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#include "ManageJson.h"


using boost::property_tree::ptree;
using namespace std;

manageJson::manageJson() {
	// Auto-generated constructor stub
}

manageJson::~manageJson() {
	// Auto-generated destructor stub
}
///Constructor with parameters
manageJson::manageJson(summaryJson newInfo){
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
/*
 * @param summaryJson SummaryJson that modify the values of a manageJson's class
 * */
void manageJson::setStructure(summaryJson newInfo){
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

void manageJson::printInfo(){
	 cout << "Summary: " << this->myInfo.summary_File << endl;
	 cout << "id: " << this->myInfo.id_File << endl;
	 cout << "monitor: " << this->myInfo.monitor_File << endl;
	 cout << "source: " << this->myInfo.source_File << endl;
	 cout << "status: " << this->myInfo.status << endl;
	 cout << "lastCheckTime: " << this->myInfo.lastCheckTime_File << endl;
	 cout << "destination: " << this->myInfo.destination << endl;
	 cout << endl;


	 cout << "AVG" << endl;
	 cout << "unit: " << this->myInfo.avg_File.unit << endl;
	 cout << "description: " << this->myInfo.avg_File.description << endl;
	 cout << "value: " << this->myInfo.avg_File.value << endl;

	 cout << "MAX" << endl;
	 cout << "unit: " << this->myInfo.max_File.unit << endl;
	 cout << "description: " << this->myInfo.max_File.description << endl;
	 cout << "value: " << this->myInfo.max_File.value << endl;

	 cout << "MIN" << endl;
	 cout << "unit: " << this->myInfo.min_File.unit << endl;
	 cout << "description: " << this->myInfo.min_File.description << endl;
	 cout << "value: " << this->myInfo.min_File.value << endl;

	 cout << "Sigma" << endl;
	 cout << "unit: " << this->myInfo.sigma_File.unit << endl;
	 cout << "description: " << this->myInfo.sigma_File.description << endl;
	 cout << "value: " << this->myInfo.sigma_File.value << endl;

	 cout << endl;
	 cout << endl;
}

//Return true or false if find the string "PS_CHECK_THROUGHPUT OK"
bool manageJson::checkSummary(){
	bool correct = false;
	std::string throughtput = "PS_CHECK_THROUGHPUT OK";

	if((this->myInfo.summary_File.find(throughtput)) < this->myInfo.summary_File.length()){
		correct = true;
	}

	return correct;
}

//Return true or false if source and monitor are the same
bool manageJson::checkPushPull(){
	bool correct = false;

	//cout << "Source: " << this->myInfo.source_File << endl;
	//cout << "Monitor: " << this->myInfo.monitor_File << endl;
	if(this->myInfo.source_File.compare(this->myInfo.monitor_File) == 0){
		correct = true;
	}

	return correct;
}

float manageJson::getAvg(){
	return this->myInfo.avg_File.value;
}
