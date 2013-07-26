/*
 * manageJson.h
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#ifndef UTILSJSON_H_
#define UTILSJSON_H_

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

class UtilsJson {

public:
	struct parameters{
		std::string unit;
		std::string description;
		float value;


	};
	struct summaryJson{
		std::string summary_Json;		// summary file
		int id_Json;					// id file
		std::string monitor_Json;		// monitor file
		std::string source_Json;		// source file
		int status_Json;						// status
		std::string lastCheckTime_Json;	// last check time file
		std::string destination_Json;		// destination
		parameters avg_Json;
		parameters max_Json;
		parameters min_Json;
		parameters sigma_Json;
	};

private:
	summaryJson myInfo;

public:
	/**
	 @brief Default constructor
	 */
	UtilsJson();

	/**
	 @brief Default destructor
	 */
	virtual ~UtilsJson();

	/**
	 @brief Constructor with parameters
	 @param newInfo: SummaryJson information
	 */
	UtilsJson(summaryJson newInfo);

	UtilsJson::summaryJson getStructure();

	/**
	 @brief Modifies a summaryJson
	 @param newInfo: SummaryJson information
	 */
	void setStructure(summaryJson newInfo);

	/**
	 @brief Print all the values of a manageJson
	 */
	friend std::ostream& operator<<(std::ostream& out, UtilsJson& fp);

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

#endif /* UTILSJSON_H_ */
