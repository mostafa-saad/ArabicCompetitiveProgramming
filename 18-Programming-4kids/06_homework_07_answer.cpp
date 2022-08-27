#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int is_even = n % 2 == 0;
	int is_odd = 1 - is_even;

	// formula of 2 parts: only one of them will be activated
	int result = is_even * 100 + is_odd * 7;
	int result2 = n % 2 * -93 + 100; // Another solution

	cout<<result<<"\n";
	cout<<result2<<"\n";



	return 0;
}

