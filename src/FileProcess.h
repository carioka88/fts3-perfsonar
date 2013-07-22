/*
 * FileProcess.h
 *
 *  Created on: Jul 22, 2013
 *      Author: rocio
 */

#ifndef FILEPROCESS_H_
#define FILEPROCESS_H_
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

#include "ManageJson.h"

using boost::property_tree::ptree;
using namespace std;

class FileProcess {
public:
	list<manageJson> fileData;

	FileProcess();
	virtual ~FileProcess();

	/**
	 @brief Read a JsonFile
	 @param ptFile: ptree to read all the Json tree
	 */
	void readFileJson(stringstream& stringFile);

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
	void print();
};

#endif /* FILEPROCESS_H_ */
