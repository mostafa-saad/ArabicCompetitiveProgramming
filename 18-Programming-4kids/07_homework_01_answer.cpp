#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	bool is_a_even = (a % 2 == 0);
	bool is_b_even = (b % 2 == 0);

	if (!is_a_even && !is_b_even)
		cout << a * b << "\n";
	else if (is_a_even && is_b_even)
		cout << a / b << "\n";
	else if (!is_a_even && is_b_even)
		cout << a + b << "\n";
	else
		cout << a - b << "\n";

	return 0;
}

