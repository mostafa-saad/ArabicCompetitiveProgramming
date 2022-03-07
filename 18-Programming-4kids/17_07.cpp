#include<iostream>
#include<sstream>	// istringstream
using namespace std;

int main() {
	string str = "Mostafa 23 years";
	istringstream iss(str);

	string name;
	int age;
	iss>>name>>age;

	cout<<age<<"\n";

	return 0;
}
