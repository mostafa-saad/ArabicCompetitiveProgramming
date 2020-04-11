// By Amr Fahim https://www.facebook.com/amrfahim2020
// Homework 8 solution

#include <iostream>
using namespace std;

int main() {
	int n, x, occurrence[10] = {0};

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;

		while (x) {
			int digit = x % 10;
			occurrence[digit]++;
			x /= 10;
		}

	}
	for (int i = 0; i <= 9; i++) {
		cout << i << " " << occurrence[i] << endl;
	}

}

