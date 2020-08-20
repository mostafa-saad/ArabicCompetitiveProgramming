#include <bits/stdc++.h>
using namespace std;

class ClassA {
public:
	ClassA() {
		cout<<"ClassA Constructor\n";
	}
};

class ClassB {
private:
	ClassA aa;	// In first time, ClassB will call ClassA with empty constructor
	int x;
public:
	ClassB(int x) {
		this->aa = ClassA();	// In second time, again call ClassA with empty constructor
		this->x = x;
	}
};
// ClassA constructor will be called twice, which is duplicate computations!
// The reason, the Class needs to intialize its variables before getting inside the constructor
// The only way to avoid that is to use again the intializer list

class ClassC {
private:
	int &y;
	ClassB bb;

public:
	ClassC(int &y, const ClassB &bb) : y(y), bb(bb){
		// 1- The only way to initialize a reference is intializer list
		// 1- The only way to initialize a class that doesn't have default constructor (e.g. Class B)  is intializer list
	}
};

// Tip: please use initalizer list as much as possible!

int main() {
	int hello = 10;
	ClassB b(5);
	ClassC cc(hello, b);
	return 0;
}
