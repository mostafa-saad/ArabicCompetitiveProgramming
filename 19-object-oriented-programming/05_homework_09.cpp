#include <bits/stdc++.h>
using namespace std;


class A {
private:
	int *x = nullptr;
public:
	A() {
		cout<<"A constructor\n";
		x = new int;
		*x = 10;
	}
	~A() {
		cout<<"A destructor\n";
	}

};

int main() {
	A *a = new A();

	return 0;
}
