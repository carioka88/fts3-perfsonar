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

class ManageJson {

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

private:
	summaryJson myInfo;

public:
	/**
	 @brief Default constructor
	 */
	ManageJson();

	/**
	 @brief Default destructor
	 */
	virtual ~ManageJson();

	/**
	 @brief Constructor with parameters
	 @param newInfo: SummaryJson information
	 */
	ManageJson(summaryJson newInfo);

	ManageJson::summaryJson getStructure();

	/**
	 @brief Modifies a summaryJson
	 @param newInfo: SummaryJson information
	 */
	void setStructure(summaryJson newInfo);

	/**
	 @brief Print all the values of a manageJson
	 */
	friend std::ostream& operator<<(std::ostream& out, ManageJson& fp);

	/**
	 @brief Check if the summary of a manageJson is "PS_CHECK_THROUGHPUT OK"
	 @return true if the Summary is "PS_CHECK_THROUGHPUT OK", false if it is not
	 */
	bool isThroughput();

	/**
	 @brief Check if the source and monitor are the same, is pushing or pulling data.
	 @return true if the source and monitor are the same(pushing data), false if they are not (pulling data)
	 */
	bool isPushorPull();

	/**
	 @brief Get the monitor's summaryJson
	 @return the monitor's summaryJson
	 */
	std::string getMonitor();

	/**
	 @brief Get the source's summaryJson
	 @return the source's summaryJson
	 */
	std::string getSource();

	/**
	 @brief Get the destination's summaryJson
	 @return the destination's summaryJson
	 */
	std::string getDestination();

	/**
	 @brief Get the average throughput value of a manageJson
	 @return a float, the average
	 */
	float getAvg();

	/**
	 @brief Get the maximum throughput value of a manageJson
	 @return a float, the maximum
	 */
	float getMax();

	/**
	 @brief Get the minimum throughput value of a manageJson
	 @return a float, the minimum
	 */
	float getMin();
};

#endif /* MANAGEJSON_H_ */
