/*
 * TransferServiceClientData.cpp
 *
 *  Created on: Jul 23, 2013
 *      Author: rocio
 */

#include "TransferServiceClientData.h"

using namespace std;

TransferServiceClientData::TransferServiceClientData() {
	this->dataServer="";
	this->destination="";
	this->origin="";
}

TransferServiceClientData::~TransferServiceClientData() {
	// Auto-generated destructor stub
}

UtilsPerfSonar TransferServiceClientData::getInfoPerfSonar(string source, string destination, string url){
	UtilsPerfSonar data;
	CURL *curl;
	CURLcode res;
	string directionUrl;

	this->destination = destination;
	this->origin = source;

	//Correct url where do you want to connect
	directionUrl = url + "/results?action=getServices&source="+source+"&destination="+destination;

	curl = curl_easy_init();
	if(curl) {
	curl_easy_setopt(curl, CURLOPT_URL, directionUrl.c_str());
	/* Tell libcurl to follow directionUrl */
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); //To store the output
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &this->dataServer); //Data pointer to pass to the file write function
	/* Perform the request, res will get the return code */
	res = curl_easy_perform(curl);
	/* Check for errors */
	if(res != CURLE_OK)
	  fprintf(stderr, "curl_easy_perform() failed: %s\n",
			  curl_easy_strerror(res));

	/* always cleanup */
	curl_easy_cleanup(curl);
	}

	data.parserJson(this->dataServer);
	return data;
}

size_t TransferServiceClientData::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
