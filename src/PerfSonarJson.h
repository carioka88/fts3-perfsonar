/*
 * PerfSonarJson.h
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#ifndef PERFSONARJSON_H_
#define PERFSONARJSON_H_

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

class PerfSonarJson {

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
	static const char* throughput;
	static const char* throughputWarning;
	summaryJson myInfo;

public:
	/**
	 @brief Default constructor
	 */
	PerfSonarJson();

	/**
	 @brief Default destructor
	 */
	virtual ~PerfSonarJson();

	/**
	 @brief Constructor with parameters
	 @param newInfo: SummaryJson information
	 */
	PerfSonarJson(summaryJson newInfo);

	PerfSonarJson::summaryJson getStructure();

	/**
	 @brief Modifies a summaryJson
	 @param newInfo: SummaryJson information
	 */
	void setStructure(summaryJson newInfo);

	/**
	 @brief Print all the values of a summaryJson
	 */
	friend std::ostream& operator<<(std::ostream& out, PerfSonarJson& fp);

	/**
	 @brief Check if the summary of a summaryJson is "PS_CHECK_THROUGHPUT OK"
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
	 @brief Get the average throughput value of a summaryJson
	 @return a float, the average
	 */
	float getAvg();

	/**
	 @brief Get the maximum throughput value of a summaryJson
	 @return a float, the maximum
	 */
	float getMax();

	/**
	 @brief Get the minimum throughput value of a summaryJson
	 @return a float, the minimum
	 */
	float getMin();

	/*
	 * @brief Set the average value of a summaryJson
	 * @param avg: float to set the average
	 * */
	void setAvg(float avg);

	void setAvgDescription(std::string avg_description);
	void setAvgUnit(std::string avg_unit);

	/*
	* @brief Set the maximum value of a summaryJson
	* @param max: float to set the maximum
	* */
	void setMax(float max);

	void setMaxDescription(std::string max_description);
	void setMaxUnit(std::string max_unit);

	/*
	* @brief Set the minimum value of a summaryJson
	* @param min: float to set the minimum
	* */
	void setMin(float min);
	/*
	* @brief Set the description of a minimum value of a summaryJson
	* @param min: float to set the minimum
	* */
	void setMinDescription(std::string min_description);

	/*
	* @brief Set the minimum value of a summaryJson
	* @param min: float to set the minimum
	* */
	void setMinUnit(std::string min_unit);

	/*
	* @brief Set the sigma value of a summaryJson
	* @param sigma: float to set the sigma
	* */
	void setSigma(float sigma);

	void setSigmaDescription(std::string sigma_description);
	void setSigmaUnit(std::string sigma_unit);

	void setId(int id_Json);
	void setMonitor(std::string monitor_Json);
	void setSource(std::string source_Json);
	void setStatus(int status_Json);
	void setCheckTime(std::string lastCheckTime_Json);
	void setDestination(std::string destination_Json);

	void setSummary(std::string summary);


};

#endif /* PERFSONARJSON_H_ */
