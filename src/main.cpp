#include "ManageJson.h"
#include "FileProcess.h"

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

		FileProcess fileData;
		try{
	        fileData.parserJson(stringFile);	//Read the file

	        cout << "The average time for pushing is: " << fileData.getThroughputPushing();
	        cout << endl;
	        cout << "The average time for pulling is: " << fileData.getThroughputPulling();

	        cout << endl;

	        //print the Json info
	        //cout << fileData;
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

