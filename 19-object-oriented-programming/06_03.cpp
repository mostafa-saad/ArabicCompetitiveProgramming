#include <bits/stdc++.h>
using namespace std;

class MyNumber {
private:
	int *val1;
	int val2;

public:
	MyNumber(int x = 3, int y = 5) {
		cout << "Normal ructor\n";
		val1 = new int;
		*val1 = x;
		val2 = y;
	}

	MyNumber( MyNumber &another) {
		cout << "Copy ructor\n";
		val1 = new int;
		*val1 = *another.val1;
		val2 = another.val2;
	}
	~MyNumber() {
		delete val1;
	}
	void PrintValueAndAddress() {
		cout << "val1: " << *val1 << " " << val1 << "\n";
		cout << "val2: " << val2 << " " << &val2 << "\n\n";
	}
};


int main() {
	MyNumber a;				// normal ructor
	MyNumber b(a);			// copy ructor

	a.PrintValueAndAddress();
	b.PrintValueAndAddress();

	return 0;
}
