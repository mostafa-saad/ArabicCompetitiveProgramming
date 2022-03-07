#include<iostream>
using namespace std;

int factorial(int n) {
	int res = 1;

	for (int i = 2; i <= n; ++i)
		res *= i;

	return res;
}

int main() {
	cout << factorial(3) << "\n";	// 1 * 2 * 3
	cout << factorial(4) << "\n";	// 1 * 2 * 3 * 4

	cout << factorial(5) << "\n";	// 1 * 2 * 3 * 4 * 5            = 120
									// factorial(4)  * 5			= 120

	cout << factorial(6) << "\n";	// 1 * 2 * 3 * 4 * 5 * 6 		= 720
									// factorial(5)      * 6 		= 720
									// factorial(4)  * 5 * 6 		= 720
									// factorial(3)*4* 5 * 6 		= 720

	return 0;
}

