/*
 * TcpOptimizer.h
 *
 *  Created on: Aug 2, 2013
 *      Author: rocio
 */

#ifndef TCPOPTIMIZER_H_
#define TCPOPTIMIZER_H_
#include "INetworkLink.h"
#include <list>

class TcpOptimizer {
protected:
	std::list<INetworkLink::NetworkLinkInfo> listNetworks;
public:
	TcpOptimizer();
	virtual ~TcpOptimizer();
	float optimizeTCP(bool isPush);
	void saveNetInfo(INetworkLink::NetworkLinkInfo net);
};

#endif /* TCPOPTIMIZER_H_ */
