/*
 * manageJson.h
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#ifndef MANAGEJSON_H_
#define MANAGEJSON_H_

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <string.h>
#include <exception>
#include <boost/array.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#ifdef _MSC_VER
#include <boost/config/compiler/visualc.hpp>
#endif
#include <boost/foreach.hpp>

using boost::property_tree::ptree;
class manageJson {

public:
	struct parameters{
		std::string unit;
		std::string description;
		float value;

/*
		std::string getUnit(){return unit;}
		void setUnic(std::string ss){ unit = ss;}
		std::string getDescription(){return description;}
		void setDescription(std::string ss){ description = ss;}
		float getValue(){return value;}
		void setValue(float v){value = v;}*/

	};
	struct summaryJson{
		std::string summary_File;		// summary file
		int id_File;					// id file
		std::string monitor_File;		// monitor file
		std::string source_File;		// source file
		int status;						// status
		std::string lastCheckTime_File;	// last check time file
		std::string destination;		// destination
		parameters avg_File;
		parameters max_File;
		parameters min_File;
		parameters sigma_File;
/*
		std::string getSummary(){return summary_File;}
		void setSummary(std::string ss){ summary_File = ss;}
		float getId(){return id_File;}
		void setId(float v){id_File = v;}
		std::string getMonitor(){return monitor_File;}
		void setMonitor(std::string ss){ monitor_File = ss;}
		std::string getSource(){return source_File;}
		void setSource(std::string ss){ source_File = ss;}
		float getStatus(){return status;}
		void setStatus(float v){status = v;}
		std::string getLastCheckTime(){return lastCheckTime_File;}
		void setLastCheckTime(std::string ss){ lastCheckTime_File = ss;}
		std::string getDestination(){return destination;}
		void setDestination(std::string ss){ destination = ss;}*/
	};

	summaryJson myInfo;

	/**
	 @brief Default constructor
	 */
	manageJson();

	/**
	 @brief Default destructor
	 */
	virtual ~manageJson();

	/**
	 @brief Constructor with parameters
	 @param newInfo: SummaryJson information
	 */
	manageJson(summaryJson newInfo);

	/**
	 @brief Modifies a summaryJson
	 @param newInfo: SummaryJson information
	 */
	void setStructure(summaryJson newInfo);

	/**
	 @brief Print all the values of a manageJson
	 */
	void printInfo();

	/**
	 @brief Check if the summary of a manageJson is "PS_CHECK_THROUGHPUT OK"
	 @return true if the Summary is "PS_CHECK_THROUGHPUT OK", false if it is not
	 */
	bool checkSummary();

	/**
	 @brief Check if the source and monitor are the same, is pushing or pulling data.
	 @return true if the source and monitor are the same(pushing data), false if they are not (pulling data)
	 */
	bool checkPushPull();

	/**
	 @brief Get the average throughput value of a manageJson
	 @return a float, the average
	 */
	float getAvg();

};

#endif /* MANAGEJSON_H_ */