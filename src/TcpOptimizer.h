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

private:
	TcpOptimizer();
	static TcpOptimizer* myInstance;

protected:
	std::list<INetworkLink::NetworkLinkInfo> listNetworks;

public:

	static TcpOptimizer* getInstance();

	virtual ~TcpOptimizer();

	/*
	 * @brief Get the TCP buffer optimized
	 * @isPush: Boolean that if is true take just the Throughput pushing, and if is false, throughput pulling.
	 * @return float of the TCP buffer optimized
	 * */
	float optimizeTCP(bool isPush);

	/*
	 * @brief Save the network's information
	 * @parameters net: is a NetworkLink that provides information (RTT, source. destination, Throughput) necessary to calculate the TCP buffer size
	 * */
	void registerNetInfo(INetworkLink *net);

	void printListNet();
};

#endif /* TCPOPTIMIZER_H_ */
