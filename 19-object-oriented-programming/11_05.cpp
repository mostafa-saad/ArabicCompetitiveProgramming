#include <bits/stdc++.h>
using namespace std;

class A {
public:
	int x;
protected:
	int y;
private:
	// Always invisible for outsiders
	int z;
};

class B: public A {
	// x is public
	// y is protected
};

class C: protected A {
	// x is protected
	// y is protected
};

class D: private A {
	// Now invisible for outsiders
	// x is private
	// y is private
};

int main() {
	A a;
	a.x = 1;	// can't access y or z

	B b;
	b.x = 1;	// can't access y or z

	C c;		// can't access x or y or z
	return 0;
}
