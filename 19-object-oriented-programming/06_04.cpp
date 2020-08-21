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


void play1(MyNumber a) {}
void play2(MyNumber &a) {}
void play3( MyNumber &a) {}

MyNumber play4() {
	MyNumber x(1, 1);
	return x;	// Returned object is temporary
}

int main() {
	play1(MyNumber());
	// play2(MyNumber());		// cannot be bound to a non- reference
	play3(MyNumber());
	// play2(play4());			// cannot be bound to a non- reference

	// Notice: Sometimes the copy ructor won't be called!
	// Due to C++ return value optimization (RVO)
	// 	It eliminates the temporary object created to hold a function's return value

	return 0;
}
