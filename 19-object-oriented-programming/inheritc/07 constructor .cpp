#include <bits/stdc++.h>
using namespace std;

class Base {
protected:
	int b;
public:
	Base() {
		b = 7;
		cout << "Constructor Base Def\n";
	}
	Base(int b) :
			b(b) {
		cout << "Constructor Base Param\n";
	}

	~Base() {
		cout << "Destructor Base \n";
	}
};

class Derived: public Base {
protected:
	int d;
public:
	Derived() {
		d = 0;
		b = 0;
		cout << "Constructor Derived Def\n";
	}
	Derived(int d) :
			Base(5), d(d) {
		cout << "Constructor Derived Param\n";
	}
	~Derived() {
		cout << "Destructor Derived \n";
	}
};



class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
};

class B: public A
{
public:
    B(int a, double b)
    : A{ a }
    {
        std::cout << "B: " << b << '\n';
    }
};

class C: public B
{
public:
    C(int a , double b , char c)
    : B{ a, b }
    {
        std::cout << "C: " << c << '\n';
    }
};


int main() {
	Derived dd(10);
	return 0;
}
