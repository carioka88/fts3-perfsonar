/*
 * FileProcess.h
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#ifndef UTILSPERFSONAR_H_
#define UTILSPERFSONAR_H_

#include "UtilsJson.h"
#include "INetworkLink.h"
#include <curl/curl.h>

class UtilsPerfSonar: public INetworkLink {

private:
	std::list<UtilsJson> fileData;

	/**
	 @brief Read a JsonFile
	 @param ptFile: ptree to read all the Json tree
	 */
	void parserJson(std::string stringFile);

	/**
	 @brief To store the output of a Curl
	 */
	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
public:
	UtilsPerfSonar();
	virtual ~UtilsPerfSonar();

	/**
	 @brief Get the data of a perfsonar.
	 @param source: string that indicate the source
	 @param destination: string that indicate the destination
	 @param url: url given for the client
	 @return FileProcess: to extract some information
	 */
	 NetworkLinkInfo getInfo(std::string source, std::string dest);

	/**
	 @brief Calculate the throughput pushing
	 @return the throughput pushing
	 */
	float getThroughputPushing();

	/**
	 @brief Calculate the throughput pulling
	 @return the throughput pulling
	 */
	float getThroughputPulling();

	/**
	 @brief Get the Round Trip Time
	 @return the RTT
	 */
	float getRTT();

	/**
	 @brief Print the information of a list of manageJson that contains information of a Json's file
	 */
	friend std::ostream& operator<<(std::ostream &out, UtilsPerfSonar& fp);

};

#endif /* UTILSPERFSONAR_H_ */
