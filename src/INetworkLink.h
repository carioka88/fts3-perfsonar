/*
 * IInfoPointToPoint.h
 *
 *  Created on: Jul 31, 2013
 *      Author: rocio
 */

#ifndef INETWORKLINK_H_
#define INETWORKLINK_H_

#include <iostream>

class INetworkLink {
public:
	struct NetworkLinkInfo{
		std::string origin;
		std::string destination;
		float throughPushing;
		float throughPulling;
		float RTT;
	};
protected:
	NetworkLinkInfo myInfoBufferTCP;

public:
	INetworkLink();
	INetworkLink(const INetworkLink &newNetwork);
	//IInfoPointToPoint(std::string source, std::string dest);

	virtual ~INetworkLink();

	virtual NetworkLinkInfo getInfo(std::string source, std::string dest){return this->myInfoBufferTCP;};

	/*float getTCPPushing(){
		return ((this->myInfoBufferTCP.throughPushing)*(this->myInfoBufferTCP.RTT)/8);
	}

	float getTCPPulling(){
		return ((this->myInfoBufferTCP.throughPulling)*(this->myInfoBufferTCP.RTT)/8);
	}*/
};

#endif /* INETWORKLINK_H_ */
