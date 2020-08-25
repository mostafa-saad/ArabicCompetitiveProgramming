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
		// We need to free x as we created it
		if (x != nullptr) {
			delete x;
			x = nullptr;
		}
		cout<<"A destructor\n";
	}

};

int main() {
	// Whoever creates a pointer is responsible for destructing it
	// If it is created as member variable, we destroy it in destructor

	// Now, we created this from outside, we must delete it from outside (e.g. delete a)
	// Now an interesting object, when this *a goes out of scope, what is destroyed?
	// The answer is the variable a itself that points to the pointer, NOT the pointer content (object of class a)
	A *a = new A();
	delete a;

	return 0;
}
