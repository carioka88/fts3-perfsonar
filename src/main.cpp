#include "UtilsJson.h"
#include "UtilsPerfSonar.h"
#include "TransferServiceClientData.h"

using namespace std;

int main(int argc, char** argv){
	if(argc == 2){
		ifstream file(argv[1]);

		if(!file)
		{
			cout << "File open error: " << argv[1] << endl;
	                return 1;
		}
		string line, stringFile;
		while(getline(file, line))
			stringFile += line + "\n";

		string url = "http://perfsonar.racf.bnl.gov:8080/exda";
		TransferServiceClientData infoPerfSonar;
		UtilsPerfSonar fileData = infoPerfSonar.getInfoPerfSonar("lhcmon.bnl.gov", "psmsu02.aglt2.org", url);

		try{

	        cout << "The average throughput for pushing is: " << fileData.getThroughputPushing() << endl;
	        cout << "The average throughput for pulling is: " << fileData.getThroughputPulling() << endl;

		}
		catch(exception &e){
			cout << "Error" << e.what() << endl;
		}
	}
	else{
		cout << "Need the file json to read" << endl;
		return 0;
	}
	return 0;
}

