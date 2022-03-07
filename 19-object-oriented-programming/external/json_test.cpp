#include <bits/stdc++.h>
using namespace std;

#include "json.hpp"
using namespace json;

int main() {
	json::JSON obj;
	// Create a new Array as a field of an Object.
	obj["array"] = json::Array(true, "Two", 3, 4.0);
	// Create a new Object as a field of another Object.
	obj["obj"] = Object();
	// Assign to one of the inner object's fields
	obj["obj"]["inner"] = "Inside";

	// We don't need to specify the type of the JSON object:
	obj["new"]["some"]["deep"]["key"] = "Value";
	obj["array2"].append(false, "three");

	// We can also parse a string into a JSON object:
	obj["parsed"] = JSON::Load("[ { \"Key\" : \"Value\" }, false ]");
	
	//////////////////////////////
	
	// We can directly print to screen
	cout<<obj<<"\n";

	// We can convert to string
	ostringstream oss;
	oss<<obj;
	string query = oss.str();

	// We can create object from string
	json::JSON obj2 = JSON::Load(query);
	cout<<obj2<<"\n";


	return 0;
}
