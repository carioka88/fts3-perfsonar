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

INetworkLink::NetworkLinkInfo INetworkLink::getLinkStruct(){
	return this->myInfoBufferTCP;
}
