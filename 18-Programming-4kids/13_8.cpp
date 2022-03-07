#include<iostream>
using namespace std;

int our_pow(int n, int p = 3) {
	int result = 1;

	while (p--)
		result *= n;

	return result;
}

int main() {
	cout << our_pow(2) << "\n";
	cout << our_pow(2, 3) << "\n";
	cout << our_pow(2, 4) << "\n";

	return 0;
}

