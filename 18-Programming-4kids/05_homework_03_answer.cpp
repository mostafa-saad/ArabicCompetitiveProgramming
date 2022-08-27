/*
 Homework 3: Simplify expressions
*/

#include<iostream>
using namespace std;

int main() {
	cout << (true && true && false && true); // 0
	cout << (true && true && false && true || true && false); // 0
	cout << (true && true && true && true || true && (true || false)); // 1
	cout << (true && true && true || true && (false || (true && (true && true)))); // 1
	cout << (true && true || true && false && true || true && true && false || (true && (true || false))); // 1
	cout << (true && true || true && false && true || (true && true && false || (true && (true || false)))); // 1
	cout << ((true && true || true && false && true || true)&& true && false || (true && (true || false))); // 1
	cout << (true && true || true && (false && true || true && true) && false || (true && (true || false))); // 1
	return 0;
}

