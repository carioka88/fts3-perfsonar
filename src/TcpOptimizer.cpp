/*
 * TcpOptimizer.cpp
 *
 *  Created on: Aug 2, 2013
 *      Author: rocio
 */

#include "TcpOptimizer.h"

TcpOptimizer::TcpOptimizer() {
	// Auto-generated constructor stub
}

TcpOptimizer::~TcpOptimizer() {
	//Auto-generated destructor stub
}

void TcpOptimizer::saveNetInfo(INetworkLink::NetworkLinkInfo net){
	this->listNetworks.push_back(net);
}
float TcpOptimizer::optimizeTCP(bool isPush){
	float finalTCP = 0;
	float bandwidth = 0;
	float rtt = 0;

	std::list<INetworkLink::NetworkLinkInfo>::iterator tmpIterator;

	if(isPush){
		for ( tmpIterator = this->listNetworks.begin(); tmpIterator != this->listNetworks.end(); tmpIterator++){
			bandwidth += (*tmpIterator).throughPushing;
			rtt += (*tmpIterator).RTT;
		}
	}
	else{
		for ( tmpIterator = this->listNetworks.begin(); tmpIterator != this->listNetworks.end(); tmpIterator++){
			bandwidth += (*tmpIterator).throughPulling;
			rtt += (*tmpIterator).RTT;
		}
	}

	finalTCP = (bandwidth/this->listNetworks.size())*(rtt/this->listNetworks.size())/8;

	return finalTCP;
}

