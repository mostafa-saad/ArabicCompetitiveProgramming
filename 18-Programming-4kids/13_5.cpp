#include<iostream>
using namespace std;

int our_abs(int n) {
	if (n >= 0)
		return n;
	return -n;
}

int our_max2(int a, int b) {
	a = our_abs(a);
	b = our_abs(b);

	if (a >= b)
		return a;
	return b;
}

int main() {
	cout << our_max2(2, 5) << "\n";
	cout << our_max2(2, -5) << "\n";

	return 0;
}

