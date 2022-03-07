#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v1;	// Array that can be expanded

	v1.push_back(30);
	v1.push_back(10);
	v1.push_back(20);
	// Now we have 3 elements only

	for (int i = 0; i < (int)v1.size(); ++i) {
		cout<<v1[i]<<" ";	// 30 10 20
	}
	cout<<"\n";

	vector<int> v2(5, 7);
	// Like an array with 5 numbers all initialized with 7

	v2.push_back(13);	// Now add extra num = 13

	for (int i = 0; i < (int)v2.size(); ++i) {
		cout<<v2[i]<<" ";	// 7 7 7 7 7 13
	}
	cout<<"\n";

	return 0;
}
