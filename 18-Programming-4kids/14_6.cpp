#include<iostream>
using namespace std;

struct full_name {
	string first, middle, last;

	full_name(string _first, string _last = "") {	// constructor
		first = _first;
		last = _last;
		middle = "";
	}
};


int main() {
	full_name my_name("ali");
	cout<<my_name.first<<"\n";

	full_name his_name = full_name("mostafa", "ibrahim");
	cout<<his_name.last;

	return 0;
}
