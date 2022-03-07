#include<iostream>
using namespace std;

int factorial(int n) {
	cout<<"Function Call: factorial: n="<<n<<"\n";

	if (n == 1)
		return 1;
	return factorial(n-1) * n;
}

int main() {
	cout << factorial(6) << "\n";
	return 0;
}

