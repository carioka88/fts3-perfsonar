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
		std::string origin;			//Network's source
		std::string destination;	//Network's destination
		float throughPushing;		//Network's throughput pushing
		float throughPulling;		//Network's throughput pulling
		float RTT;					//Network's RTT
	};
protected:
	NetworkLinkInfo myInfoBufferTCP;

public:
	//Constructor
	INetworkLink();
	INetworkLink(const INetworkLink &newNetwork);
	//IInfoPointToPoint(std::string source, std::string dest);

	virtual ~INetworkLink();

	/*
	 * @brief Get the information about the network,
	 * depending on the class that call this fuction, will implements a different method.
	 * @source: string that is the origin of the network
	 * @dest: string that is the destination of the network
	 * @return NetworkLinkInfo: NetworkLinkInfo that contains the information that we need (RTT, Throughput)
	 * */
	virtual NetworkLinkInfo getInfo(std::string source, std::string dest){return this->myInfoBufferTCP;};
	NetworkLinkInfo getLinkStruct();
};

#endif /* INETWORKLINK_H_ */
