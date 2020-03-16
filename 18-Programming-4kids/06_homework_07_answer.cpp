#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int is_even = n % 2 == 0;
	int is_odd = 1 - is_even;

	// formula of 2 parts: only one of them will be activated
	int result = is_even * 100 + is_odd * 7;

	cout<<result<<"\n";



	return 0;
}

