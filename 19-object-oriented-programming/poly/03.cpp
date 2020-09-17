#include <bits/stdc++.h>
using namespace std;

class A {
public:
	virtual void f1() {	cout << "A::f1\n";	}	// virtual
	void f2() 		  { cout << "A::f2\n";	}
	void f3() 		  {	cout << "A::f3\n";	}
};

class B: public A {
public:
	void f1() 		 { cout << "B::f1\n";	}	// virtual
	virtual void f2(){ cout << "B::f2\n";	}	// virtual
	void f3() 		 { cout << "B::f3\n";	}
};

class C: public B {
public:
	void f1() 		  {	cout << "C::f1\n";	}	// virtual
	void f2() 		  { cout << "C::f2\n";	}	// virtual
	virtual void f3() {	cout << "C::f3\n";	}
};

class D: public C {
public:
	void f1() 		 { cout << "D::f1\n";	}	// virtual
	void f2() 		 { cout << "D::f2\n";	}	// virtual
	void f3() 		 { cout << "D::f3\n";	}	// virtual
};

// we should provide virtual destructors to avoid memory leaks

int main() {
	B* d1 = new D();
	d1->f1();
	d1->f2();
	d1->f3();
	cout<<"\n";

	A* d2 = new D();
	d2->f1();
	d2->f2();
	d2->f3();

	return 0;
}
