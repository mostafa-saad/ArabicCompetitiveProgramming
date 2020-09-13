#include <bits/stdc++.h>
using namespace std;

// https://users.cs.fiu.edu/~weiss/phc++/code/exceptionDemo.cpp

void div(int x) {
	100000/x;
}

void array_access(int pos) {
	vector<int> v(5);

	v.at(pos) = 1;	// out_of_range = logic_error
}

double mysqrt(double x) {
	if (x < 0)
		throw domain_error("sqrt of neg number");
	else
		return sqrt(x);
}

double myexp(double x) {
	double result = exp(x);
	if (result == HUGE_VAL)
		throw out_of_range("exp too large");
	else
		return result;
}



void test(double x) {
	try {
		mysqrt(x);
		myexp(x);
		array_access(x);
	} catch (domain_error & e) {
		cout << "Caught DOMAIN exception " << e.what() << endl; // invoke correct what
	} catch (logic_error & e) {
		cout << "Caught logical error exception " << e.what() << endl; // invoke correct what
	} catch (...) {
		cout << "Catching a lot\n";
		// you can't catch division by zero
		// "low-level events, such as arithmetic overflows and divide by zero,
		// are assumed to be handled by a dedicated lower-level mechanism rather than by exceptions "
	}
}

int main() {
	test(10);
	test(-4);
	test(10000000);
	test(0);	// program crach

	return 0;
}
