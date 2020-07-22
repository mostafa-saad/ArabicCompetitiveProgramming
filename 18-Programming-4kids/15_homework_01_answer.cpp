#include<iostream>
using namespace std;

int length_3n_plus_1(int n) {
	if (n == 1)
		return 1;

	if (n % 2 == 0)
		return 1 + length_3n_plus_1(n / 2);

	return 1 + length_3n_plus_1(3 * n + 1);
}

int main() {
	cout<<length_3n_plus_1(6);

	return 0;
}

