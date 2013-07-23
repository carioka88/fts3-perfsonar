/*
 * FileProcess.h
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#ifndef FILEPROCESS_H_
#define FILEPROCESS_H_

#include "ManageJson.h"


class FileProcess {
private:
	std::list<ManageJson> fileData;

public:
	FileProcess();
	virtual ~FileProcess();

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
	friend std::ostream& operator<<(std::ostream &out, FileProcess& fp);
};

#endif /* FILEPROCESS_H_ */
