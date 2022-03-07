#include<iostream>
using namespace std;

int our_abs(int n) {
	if (n >= 0)
		return n;
	return -n;
}

int main() {
	cout << our_abs(5) << "\n";
	cout << our_abs(-5) << "\n";

	return 0;
}

