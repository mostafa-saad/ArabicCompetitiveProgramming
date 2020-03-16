#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int last1 = n % 10;
	n /= 10;

	int last2 = n % 10;
	n /= 10;

	int last3 = n % 10;
	n /= 10;

	cout << last1 + last2 + last3 << "\n";

	return 0;
}

