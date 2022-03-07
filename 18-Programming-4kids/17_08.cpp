#include<iostream>
#include<sstream>	// istringstream
using namespace std;

int main() {
	ostringstream oss;

	oss<<"Mostafa ";
	oss<<50;
	oss<<" years old\n";

	cout<<oss.str();

	return 0;
}
