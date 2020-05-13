// By Amr Fahim https://www.facebook.com/amrfahim2020
// Homework 9 solution
#include <iostream>
using namespace std;

int main() {
	const int N = 201;	// Be careful. We need 201 values NOT 200
	int sequence[N], indx;

	int occurrence[N * 10] = { 0 };	// possibly i-th value is much less than 10 * i

	cin >> indx;
	sequence[0] = 0;
	occurrence[0] = 1;	// use a value as an index in the array

	for (int i = 1; i <= indx; i++) {
		int cur = sequence[i - 1] - (i - 1) - 1;

		if (cur < 0 || occurrence[cur])
			cur = sequence[i - 1] + (i - 1) + 1;

		sequence[i] = cur;
		occurrence[cur] = 1;
	}

	cout << sequence[indx];

}

