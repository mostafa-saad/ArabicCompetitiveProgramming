#include<iostream>
using namespace std;

int factorial1() {
	return 1;	// base case. No subproblems
}

int factorial2() {
	return factorial1() * 2;
}

int factorial3() {
	return factorial2() * 3;
}

int factorial4() {
	return factorial3() * 4;
}

int factorial5() {
	return factorial4() * 5;
}

int factorial6() {
	return factorial5() * 6;
}

int main() {
	cout << factorial6() << "\n";
	return 0;
}

