#include <bits/stdc++.h>
using namespace std;

class ClassA {
public:
	ClassA() {
		cout << "ClassA Constructor\n";
	}
};

class ClassB {
private:
	ClassA aa;	// originally this line needs to call constructor to default in begin
	int x;
public:
	ClassB(int x) :
			aa(ClassA()), x(x) {
		// Originally the constructor of classA called twice
			// Once to be default Initialized
			// Once inside the constructor

		// Moving to Initializer list, then we Initialize it before construction only once

		// Tip: Always use Initializer list
	}
};

class ClassC {
private:
	int &y;
	ClassB bb;

public:
	ClassC(int &y, const ClassB &bb) :
			y(y), bb(bb) {
		// You must use initalizer list
	}
};

int main() {
	int hello = 10;
	ClassB b(5);
	ClassC cc(hello, b);
	return 0;
}
