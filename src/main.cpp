#include "INetworkLink.h"
#include "TcpOptimizer.h"
#include "UtilsJson.h"
#include "UtilsPerfSonar.h"
#include <list>
using namespace std;

int main(int argc, char** argv){


	//list<IInfoPointToPoint> ListTCP;
	TcpOptimizer tcpBuffer;

	UtilsPerfSonar fileData = UtilsPerfSonar();

	tcpBuffer.saveNetInfo(fileData.getInfo("lhcmon.bnl.gov", "psmsu02.aglt2.org"));



	//struct NetworkLinkInfo auxInfoLink = fileData.getInfo();
	//fileData.getInfo();

	try{
		cout << "The TCP buffer size is: " << tcpBuffer.optimizeTCP(true) << endl;
		cout << "The TCP buffer size is: " << tcpBuffer.optimizeTCP(false) << endl;
		cout << "The throughput pushing is: " << fileData.getThroughputPushing() << endl;
		cout << "The throughput pulling is: " << fileData.getThroughputPulling() << endl;

	}
	catch(exception &e){
		cout << "Error" << e.what() << endl;
	}
}

