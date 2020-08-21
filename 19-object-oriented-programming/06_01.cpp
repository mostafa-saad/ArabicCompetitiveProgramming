#include <bits/stdc++.h>
using namespace std;

class MyNumber {
private:
	int *val1;
	int val2;

public:
	MyNumber(int x = 3, int y = 5) {
		val1 = new int;
		*val1 = x;
		val2 = y;
	}

	~MyNumber() {
		//delete val1;
	}
	void PrintValueAndAddress() {
		cout << "val1: " << *val1 << " " << val1 << "\n";
		cout << "val2: " << val2 << " " << &val2 << "\n\n";
	}
};

int main() {
	MyNumber a;
	MyNumber b(10, 20);

	a.PrintValueAndAddress();
	b.PrintValueAndAddress();
	b = a;
	b.PrintValueAndAddress();

	return 0;
}
