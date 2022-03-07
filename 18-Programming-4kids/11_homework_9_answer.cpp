#include <iostream>
using namespace std;

int main() {
	string num;

	// Guarantee input: must be 6 digits or more
	cin >> num;

	int sz = num.size();

	int carry = 0;
	for (int i = 0; i < sz; ++i) {
		int digit = num[sz - 1 - i] - '0';

		if (i < 4)
			digit += 5;			// add 5 in first 4 times
		digit += carry;		// add any carry

		if (digit >= 10)
			digit -= 10, carry = 1;
		else
			carry = 0;

		num[sz - 1 - i] = digit + '0';
	}
	if(carry)
		cout<<1;
	cout << num;

	return 0;
}
