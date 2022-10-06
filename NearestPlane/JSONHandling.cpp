#include <cpprest/http_client.h>
#include <nlohmann/json.hpp>
#include "Plane.h"
#include <fstream>


using namespace web;
using namespace http;
using namespace client;
using namespace std;


nlohmann::json pullPlaneData()
{
	vector<wstring> credVector;
	string currentLine;
	ifstream credentialsFile("cred.txt");
	vector<Plane> planeVector;
	http_client_config config;
	nlohmann::json planeJson;
	pplx::task<web::json::value> jvalue;

	while (getline(credentialsFile, currentLine))
	{
		credVector.emplace_back(wstring(currentLine.begin(), currentLine.end()));
	}

	credentialsFile.close();

	// create credentials
	credentials cred(credVector[0], credVector[1]);
	config.set_credentials(cred);

	// create http client using credentials
	http_client client(U("https://opensky-network.org"), config);

	// create header
	http_request req(methods::GET);

	// Add base64 encoding of username:password to header
	req.headers().add(L"Authorization", credVector[2]);
	req.set_request_uri(L"/api/states/all?extended=1");

	// get response
	pplx::task<http_response> responses = client.request(req);

	// check if response is OK
	if (responses.get().status_code() == status_codes::OK)
	{
		jvalue = responses.get().extract_json();
		planeJson = nlohmann::json::parse(jvalue.get().serialize());
		std::ofstream o("backup.json");
		o << std::setw(4) << planeJson << std::endl;
		o.close();
	}

	// handle bad status code
	else
	{
		cout << "Error: " << responses.get().status_code() << "\nProceeding to attempt to pull from backup. Information may not be up to date." << endl;

		// Opensky does not send a retry-after header with their 429 errors, so the wait time is unknown.

		// pull from backup json, if it exists
		if (ifstream("backup.json"))
		{
			ifstream backupFile("backup.json");
			planeJson = nlohmann::json::parse(backupFile);
			backupFile.close();
		}
		else
		{
			// exit code if no backup exists
			cout << "Error: No backup file found. Exiting." << endl;
			exit(1);
		}
	}
	return planeJson;
}


vector<Plane> parsePlaneJson(nlohmann::json planeJson)
{
	vector<Plane> planeVector;

	// iterate over each plane, adding it to the vector
	for (const auto& element : planeJson["states"])
	{
		Plane plane;
		plane.setFromJSON(element);
		planeVector.emplace_back(plane);
	}
	return planeVector;
}