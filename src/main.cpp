#include "INetworkLink.h"
#include "TcpOptimizer.h"
#include "PerfSonarJson.h"
#include "ParserInfoPerfSonar.h"
#include <list>
using namespace std;

int main(int argc, char** argv){


	//list<IInfoPointToPoint> ListTCP;

    struct INetworkLink::NetworkLinkInfo infoBandRTT;
    infoBandRTT.throughPushing = 100;
    infoBandRTT.RTT = 100;


	TcpOptimizer* tcpBuffer;
	tcpBuffer = TcpOptimizer::getInstance();

	ParserInfoPerfSonar *fileData = new ParserInfoPerfSonar();
	struct INetworkLink::NetworkLinkInfo info = fileData->getInfo("lhcmon.bnl.gov", "psmsu02.aglt2.org");
	tcpBuffer->registerNetInfo(fileData);

	//tcpBuffer->registerNetInfo(infoBandRTT);


	try{
		cout << "The TCP buffer size is: " << tcpBuffer->optimizeTCP(false) << endl;
		cout << "The throughput pushing is: " << fileData->getThroughputPushing() << endl;
		tcpBuffer->printListNet();

	}
	catch(exception &e){
		cout << "Error" << e.what() << endl;
	}

	delete fileData;
	delete tcpBuffer;
}

