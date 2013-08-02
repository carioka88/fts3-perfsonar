/*
 * IInfoPointToPoint.cpp
 *
 *  Created on: Jul 31, 2013
 *      Author: rocio
 */

#include "INetworkLink.h"

INetworkLink::INetworkLink() {
	// Auto-generated constructor stub
}

INetworkLink::INetworkLink(const INetworkLink &newNetwork){
	this->myInfoBufferTCP = newNetwork.myInfoBufferTCP;

}
INetworkLink::~INetworkLink() {
	// Auto-generated destructor stub
}

//IInfoPointToPoint::IInfoPointToPoint(std::string source, std::string dest) {
//	this->myInfoBufferTCP.origin = source;
//	this->myInfoBufferTCP.destination = dest;
//}
