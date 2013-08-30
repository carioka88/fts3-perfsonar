/*
 * FileProcess.h
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#ifndef PARSERINFOPERFSONAR_H_
#define PARSERINFOPERFSONAR_H_

#include "PerfSonarJson.h"
#include "INetworkLink.h"
#include <curl/curl.h>

class ParserInfoPerfSonar: public INetworkLink {

private:
	static const char *sourceURL;
	static const char *destinationURL;
	std::list<PerfSonarJson> fileData;

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
	ParserInfoPerfSonar();
	virtual ~ParserInfoPerfSonar();

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
	friend std::ostream& operator<<(std::ostream &out, ParserInfoPerfSonar& fp);

	void setPush(float n);
};

#endif /* PARSERINFOPERFSONAR_H_ */
