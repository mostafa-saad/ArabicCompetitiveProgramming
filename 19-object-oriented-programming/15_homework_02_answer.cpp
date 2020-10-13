#include <bits/stdc++.h>
using namespace std;

class MyPair {
private:
	int first, second;

public:
	MyPair() :	// Empty constructor to allow using default
			first(-1), second(-1) {
	}

	MyPair(int first, int second) :
			first(first), second(second) {
	}

	void print() {
		cout << "(" << first << "," << second << ")\n";
	}
	int GetFirst() const {
		return first;
	}
	void SetFirst(int first) {
		this->first = first;
	}
	int GetSecond() const {
		return second;
	}
	void SetSecond(int second) {
		this->second = second;
	}

	void operator >>(istream &input) {
		input >> first >> second;
	}

	void operator >>(ostream &output) {
		output << first << second;
	}
};


int main() {
	MyPair x, y;

	// Very weird to the used style!
	x >> cin;
	y >> cin;

	x >> cout;
	y >> cout;

	// Tip 1: using non-member style allow us to extend normally to have cin >>
	// Using >> for both input/output is wrong. Use operators as people expect
	// E.g. don't overload + to do - operations! The code will be misused!

	return 0;
}
