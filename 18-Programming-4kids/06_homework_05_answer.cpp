#include<iostream>
using namespace std;

int main() {

	double a, b;
	cin>>a>>b;

	double result = a/b;

	cout<<result - (int)result;

	return 0;
}

