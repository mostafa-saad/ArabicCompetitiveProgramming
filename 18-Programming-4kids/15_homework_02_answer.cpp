#include<iostream>
using namespace std;

int my_pow(int value, int p = 2) {
	if (p == 0)
		return 1;

	return value * my_pow(value, p - 1);
}

int main() {
	cout << my_pow(7) << "\n";
	cout << my_pow(7, 0) << "\n";
	cout << my_pow(7, 3) << "\n";

	return 0;
}

