#include<iostream>
using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	// Let's code the 2 possible results
	int equ_is_1 = a * a;
	int equ_is_neg_1 = 2 * a + 1;

	// The trick: we want to make them in 1 equation
	// Where if input is: only 1 equation is computed and the second is zer0
	// To do so: convert -1 to 0 and 1 to 1
	// With simple math, we can convert [-1 1] to [0 1] range

	// value 1 for (b 1) and value 0 for (b -1)
	int is_1 = (b + 1) / 2;
	// value 1 for (b -1) and value 0 for (b 1)
	int is_neg_1 = 1 - is_1;

	// Either 1*something + 0*something for b = 1
	// Or     0*something + 1*something for b = -1
	cout<<is_1 * equ_is_1 + is_neg_1 * equ_is_neg_1;

	return 0;
}

