#include <bits/stdc++.h>
using namespace std;

class MyPair {
private:
	int first, second;
public:
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

	MyPair(int x) :	MyPair(x, x) {}

	MyPair(int first, int second) :
			first(first), second(second) {
	}
};

MyPair operator +(const MyPair &c1, const MyPair &c2) {
	return MyPair(c1.GetFirst() + c2.GetFirst(),
			      c1.GetSecond() + c2.GetSecond());
}

int main() {
	MyPair x(1, 2);
	MyPair y(3);
	MyPair w = 5;	// Converting constructor MyPair(int x)

	MyPair z1 = x + 5.3;
	MyPair z2 = 3 + x;
	MyPair z3 = 3 + x + 5;

	w.print();
	z1.print();
	z2.print();
	z3.print();


	return 0;
}
