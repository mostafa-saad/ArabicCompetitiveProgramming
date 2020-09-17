#include <bits/stdc++.h>
using namespace std;

class A {
public:
	void f1() 			  {		cout << "A::f1\n";	}
	void f1(int x) 		  { 	cout << "A::f1(x)\n";	}
	void f1(int x, int y) {		cout << "A::f1(x,y)\n";	}
};

class B: public A {
public:
	void f1() 			  {		cout << "B::f1\n";	}
	void f1(int x) 		  { 	cout << "B::f1(x)\n";	}
	void f1(int x, int y) {		cout << "B::f1(x,y)\n";	}
};

int main() {
	B* b1 = new B();
	b1->f1();
	b1->f1(1);
	b1->f1(1, 2);
	delete b1;
}
