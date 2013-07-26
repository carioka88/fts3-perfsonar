/*
 * TransferServiceClientData.h
 *
 *  Created on: Jul 23, 2013
 *      Author: rocio
 */

#include "UtilsPerfSonar.h"
#include <curl/curl.h>

#ifndef TRANSFERSERVICECLIENTDATA_H_
#define TRANSFERSERVICECLIENTDATA_H_

class TransferServiceClientData {
private:
	std::string dataServer;
	std::string origin;
	std::string destination;

public:
	TransferServiceClientData();
	virtual ~TransferServiceClientData();

	/**
	 @brief Get the data of a perfsonar.
	 @param source: string that indicate the source
	 @param destination: string that indicate the destination
	 @param url: url given for the client
	 @return FileProcess: to extract some information
	 */
	UtilsPerfSonar getInfoPerfSonar(std::string source, std::string destination, std::string url);

	/**
		 @brief To store the output of a Curl
		 */
	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif /* TRANSFERSERVICECLIENTDATA_H_ */
