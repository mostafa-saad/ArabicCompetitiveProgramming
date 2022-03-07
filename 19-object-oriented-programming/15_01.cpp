#include <bits/stdc++.h>
using namespace std;

class MyPair {
private:
	int first, second;

public:
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

	// ++x prefix increment operator
	MyPair& operator++() {
		++first, ++second;	// increment first
		return *this;		// then return reference
	}

	// x++ postfix increment operator
	// DON'T return MyPair&: this is local var
	MyPair operator++(int) {
		MyPair cpy = *this;	// Copy first
		++first, ++second;	// Then increment
		return cpy;
	}
};


int main() {
	MyPair x1(1, 2);
	(++x1).print();	// (2,3)

	MyPair x2(1, 2);
	x2++.print();	// (1,2)
	x2.print();		// (2,3)


	return 0;
}
