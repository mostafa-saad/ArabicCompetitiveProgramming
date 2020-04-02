#include<iostream>
using namespace std;

int main() {
	int a, b, c, tmp;
	cin >> a >> b >> c;

	if (b < a) { // Swap them

		tmp = a;
		a = b;
		b = tmp;
	}
	// Now a, b are correct

	if (c < b) { // Swap them

		tmp = b;
		b = c;
		c = tmp;

		// Now b, c are correct
		// But a, b may not be again

		if (b < a) {	// Swap them{
			tmp = a;
			a = b;
			b = tmp;
		}
	}
	cout<<a<<" "<<b<<" "<<c<<"\n";

	return 0;
}

