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

void fun1(MyNumber x) {
}

MyNumber fun2() {
	MyNumber e(1, 2);
	return e;
}

int main() {
	MyNumber a;				// normal constructor
	MyNumber b(10, 20);		// normal constructor

	MyNumber c(b);			// copy constructor to build c
	MyNumber d = b;			// copy constructor to initialize in declaration
	fun1(c);				// copy constructor to pass object
	fun2();					// copy constructor to return object

	a = b;				// assignment NOT copy constructor

	a.PrintValueAndAddress();
	b.PrintValueAndAddress();
	c.PrintValueAndAddress();
	d.PrintValueAndAddress();

	return 0;
}
