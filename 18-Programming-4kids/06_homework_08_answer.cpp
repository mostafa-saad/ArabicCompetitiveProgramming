#include<iostream>
using namespace std;

int main() {

	int days;
	
	cin >> days;

	int years = days / 360;
	days = days % 360;	// now we remove # of complete years

	int months = days / 30;
	days = days % 30;

	cout<<years<<" "<<months<<" "<<days<<"\n";
	

	return 0;
}

