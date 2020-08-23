#include <bits/stdc++.h>
using namespace std;

class Test {
public:
	static int x;	// Declare: shared among all objects
};

int Test::x = 0;	// Define outside

void f() {
	Test::x += 10;	// Same x
}

int main() {
	Test::x += 1;	// Access

	f();

	cout << Test::x << "\n";

	return 0;
}
