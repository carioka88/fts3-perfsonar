/*
 * TcpOptimizer.cpp
 *
 *  Created on: Aug 2, 2013
 *      Author: rocio
 */

#include "TcpOptimizer.h"

TcpOptimizer* TcpOptimizer::myInstance = 0;

TcpOptimizer::TcpOptimizer() {
	// Auto-generated constructor stub
}

TcpOptimizer::~TcpOptimizer() {
	delete [] myInstance;
}

TcpOptimizer* TcpOptimizer::getInstance(){
	if(myInstance == 0){
		myInstance = new TcpOptimizer;
	}
	return myInstance;
}

void TcpOptimizer::registerNetInfo(INetworkLink *net){
	this->listNetworks.push_back(net->getLinkStruct());
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

	finalTCP = 1024*1024*(bandwidth/this->listNetworks.size())*(rtt/this->listNetworks.size())/8;
	return finalTCP;
}

void TcpOptimizer::printListNet(){

	std::list<INetworkLink::NetworkLinkInfo>::iterator tmpIterator;

	for ( tmpIterator = this->listNetworks.begin(); tmpIterator != this->listNetworks.end(); tmpIterator++){
		std::cout << "pushing: " << tmpIterator->throughPushing << std::endl;
		std::cout << "RTT: " << tmpIterator->RTT << std::endl;
	}

}
