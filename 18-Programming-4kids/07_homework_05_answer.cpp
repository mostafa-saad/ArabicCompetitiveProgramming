#include<iostream>
using namespace std;

int main() {
	int result, num;

	cin>>result;	// First number

	// Read 9 times and maximize
	cin>>num;	if(result < num)	result = num;
	cin>>num;	if(result < num)	result = num;
	cin>>num;	if(result < num)	result = num;
	cin>>num;	if(result < num)	result = num;
	cin>>num;	if(result < num)	result = num;
	cin>>num;	if(result < num)	result = num;
	cin>>num;	if(result < num)	result = num;
	cin>>num;	if(result < num)	result = num;
	cin>>num;	if(result < num)	result = num;

	cout<<result;

	return 0;
}

