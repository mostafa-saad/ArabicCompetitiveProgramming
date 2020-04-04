#include<iostream>
using namespace std;

int main() {
	int target;
	bool first_print = true;

	cin >> target;

	for (int number = 2; number <= target; ++number) {
		bool is_ok = true;

		for (int i = 2; i < number; ++i) {
			if (number % i == 0) {
				is_ok = false;
				break;
			}
		}

		if (is_ok)
		{
			if(!first_print)
				cout<<",";

			cout << number;

			first_print = false;
		}
	}

	return 0;
}

