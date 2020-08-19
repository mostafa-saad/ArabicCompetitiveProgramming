#include <bits/stdc++.h>
using namespace std;

// Improperly declared function:  parameter should be const reference:
void print1(string& s) {
	cout << s << endl;
}

// Properly declared function: function has no intent to modify s:
void print2(const string& s) {
	cout << s << endl;
}

int main() {
	string hello("Hello");

	print1(hello);
	// Next 2 lines create temporary objects. Function must support const
	// Main rule: cannot be bound to a non-const reference
	print1(string("World"));
	print1("!");

	print2(hello);
	print2(string("World"));
	print2("!");

	return 0;
}
