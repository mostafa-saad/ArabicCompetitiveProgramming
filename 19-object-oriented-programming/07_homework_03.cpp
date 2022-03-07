#include <bits/stdc++.h>
using namespace std;

class ConfigurationManger {
private:
	string configuration_path;
	vector<string> servers_ips;
	string aws_service_url;
	// Other heavy data
	bool is_loaded = false;
public:
	ConfigurationManger(string configuration_path) :
			configuration_path(configuration_path) {
	}
	void Load() {
		if (is_loaded)
			return;
		// some heavy load
		cout << "Lazy loading\n";
		servers_ips.push_back("10.20.30.40");
		servers_ips.push_back("10.20.30.41");
		servers_ips.push_back("10.20.30.42");
		aws_service_url = "https://dynamodb.us-west-2.amazonaws.com";
		is_loaded = true;
	}
	string GetAwsServiceUrl() {	
		Load();
		return aws_service_url;
	}
};

void f1() {
	ConfigurationManger mgr("/home/moustafa/conf_info.txt");
	cout<<mgr.GetAwsServiceUrl()<<"\n";
}

void f2() {
	ConfigurationManger mgr("/home/moustafa/conf_info.txt");
	cout<<mgr.GetAwsServiceUrl()<<"\n";
}

int main() {
	f1();
	f2();

	return 0;
}
