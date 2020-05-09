#include<iostream>
using namespace std;

int our_max(int a, int b) {
	if (a >= b)
		return a;
	return b;
}

int main() {
	cout << our_max(2, 5) << "\n";
	cout << our_max(2, -5) << "\n";

	return 0;
}

