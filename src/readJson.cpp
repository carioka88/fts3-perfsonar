#include "manageJson.h"

using namespace std;

void readFileJson(ptree ptFile, list<manageJson>& data);
float getTimePushing(list<manageJson> jsonData);
float getTimePulling(list<manageJson> jsonData);
void print(list<manageJson> jsonToPrint);

int main(int argc, char** argv){
	ptree pt;

	if(argc == 2){
		std::stringstream fileToRead;

		ifstream file(argv[1]);
		if(!file)
		{
			cout << "File open error: " << argv[1] << endl;
	                return 1;
		}
		string line, stringFile;
		while(getline(file, line))
			stringFile += line + "\n";

		fileToRead << "{\"root\":" << stringFile << "}";

		list<manageJson> fileData;
		try{
	        boost::property_tree::ptree pt;
	        boost::property_tree::read_json(fileToRead,  pt);

	        readFileJson(pt, fileData);	//Read the file

	        cout << "The average time for pushing is: " << getTimePushing(fileData);
	        cout << "The average time for pulling is: " << getTimePulling(fileData);
	    	//print(fileData);

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

void readFileJson(ptree ptFile, list<manageJson>& data){

	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, ptFile.get_child("root")){
		manageJson::summaryJson arrayJson;

		arrayJson.summary_File = v.second.get<std::string>("summary");
		arrayJson.id_File = v.second.get("id",0);
		arrayJson.monitor_File = v.second.get<std::string>("monitor");
		arrayJson.source_File = v.second.get<std::string>("source");
		arrayJson.status = v.second.get("status",0);
		arrayJson.lastCheckTime_File = v.second.get<std::string>("lastCheckTime");
		arrayJson.destination = v.second.get<std::string>("destination");

		arrayJson.avg_File.unit = v.second.get<string>("parameters.Throughput Avg.unit");
		arrayJson.avg_File.description = v.second.get<string>("parameters.Throughput Avg.description");
		arrayJson.avg_File.value = v.second.get<float>("parameters.Throughput Avg.value");

		arrayJson.max_File.unit = v.second.get<string>("parameters.Throughput Max.unit");
		arrayJson.max_File.description = v.second.get<string>("parameters.Throughput Max.description");
		arrayJson.max_File.value = v.second.get<float>("parameters.Throughput Max.value");

		arrayJson.min_File.unit = v.second.get<string>("parameters.Throughput Min.unit");
		arrayJson.min_File.description = v.second.get<string>("parameters.Throughput Min.description");
		arrayJson.min_File.value = v.second.get<float>("parameters.Throughput Min.value");

		arrayJson.sigma_File.unit = v.second.get<string>("parameters.Sigma.unit");
		arrayJson.sigma_File.description = v.second.get<string>("parameters.Sigma.description");
		arrayJson.sigma_File.value = v.second.get<float>("parameters.Sigma.value");

		manageJson infoJson(arrayJson);
		data.push_back(infoJson);

		/*if(infoJson.checkSummary())
			cout << "Yeah!" << endl;
		else
			cout << "is not OK" << endl;*/
	}
}

void print(list<manageJson> jsonToPrint)
{
    list<manageJson>::iterator tmpIterator;
	for ( tmpIterator = jsonToPrint.begin(); tmpIterator != jsonToPrint.end(); tmpIterator++){
		tmpIterator->printInfo();
	}
	cout << endl;
}

float getTimePushing(list<manageJson> jsonData){
	list<manageJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = jsonData.begin(); tmpIterator != jsonData.end(); tmpIterator++){
		if(tmpIterator->checkSummary() && tmpIterator->checkPushing()){

			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}

float getTimePulling(list<manageJson> jsonData){
	list<manageJson>::iterator tmpIterator;
	float avg = -1;

	for ( tmpIterator = jsonData.begin(); tmpIterator != jsonData.end(); tmpIterator++){
		if(tmpIterator->checkSummary() && tmpIterator->checkPulling()){
			cout << "Yeah" << endl;

			avg = tmpIterator->getAvg();
		}
	}
	return avg;
}
