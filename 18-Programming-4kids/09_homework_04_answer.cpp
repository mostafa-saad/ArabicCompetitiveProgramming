#include<iostream>
using namespace std;

int main() {
	int number;

	cin >> number;

	if (number == 1)
		cout << "NO\n";
	else {
		bool is_ok = true;

		for (int i = 2; i < number; ++i) {
			if (number % i == 0) {
				is_ok = false;
				break;
			}
		}

		if (is_ok)
			cout << "YES";
		else
			cout << "NO";
	}

	return 0;
}

