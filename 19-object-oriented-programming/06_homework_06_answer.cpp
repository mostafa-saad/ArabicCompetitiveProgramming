#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Improperly declared parameter:  sent parameter should be const reference:
void print1(string& s) {
}

// Properly declared function: function has no intent to modify s:
void print2(const string& s) {
}

string msg1() {
	string x = "aa";
	return x;
}

const string& msg2() {
	return "aa";
}

const string& msg3() {
	string x = "aa";
	return x;
}

int main() {
	string hello("Hello");

	print1(hello);
	// Next 2 lines create temporary objects. Sent parameter can't be temporary
		// Recall: cannot be bound to a non-const reference
	print1(string("World"));
	print1("!");

	// As parameter is const & for param: any style can be used
	print2(hello);
	print2(string("World"));
	print2("!");

	string a1 = msg1();
	// Returned param is temporary. Must receive with & or const &
	string &a2 = msg1();
	const string &a3 = msg1();

	// Run time error. Above function send reference to local variable that will be destroyed
	string a = msg2();
	string b = msg2();

	/*
	 * Here is a general guideline
	 * 1) Using no reference (in parameter, function return or receiving variable in the caller)
	 * 	A) No compile or run time error
	 * 	B) If the object is heavy: takes more time and memory
	 *
	 * 	2) Using & saves time and memory BUT
	 * 	A) As a function parameter: if used & without const: you can't send temporary object => Compile error
	 * 	B) As a return: Never return & (or const &) for a local variable as it will be destroyed. This will cause RTE. The is the most dangerous case, as others cause compile error.
	 * 	C) You can return & to data member as it won't be destroyed before the receiving variable. But better use const & to follow OO concepts as possible
	 * 	D) As a receiving variable: You can't receive & for temporary object. Compile error
	 * 	E)   As a receiving variable: You can always receive const &, even for temporary object. No problem.
	 */

	return 0;
}

