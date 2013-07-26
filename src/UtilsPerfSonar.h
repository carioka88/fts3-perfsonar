/*
 * FileProcess.h
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#ifndef FILEPROCESS_H_
#define FILEPROCESS_H_

#include "UtilsJson.h"


class UtilsPerfSonar {
private:
	std::list<UtilsJson> fileData;

public:
	UtilsPerfSonar();
	virtual ~UtilsPerfSonar();

	/**
	 @brief Read a JsonFile
	 @param ptFile: ptree to read all the Json tree
	 */
	void parserJson(std::string stringFile);

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
	 @brief Print the information of a list of manageJson that contains information of a Json's file
	 */
	friend std::ostream& operator<<(std::ostream &out, UtilsPerfSonar& fp);
};

#endif /* FILEPROCESS_H_ */
