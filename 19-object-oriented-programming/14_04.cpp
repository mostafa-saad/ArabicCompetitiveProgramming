#include <bits/stdc++.h>
using namespace std;

class MyPair {
private:
	int first, second;

public:
	MyPair(int first, int second) :
			first(first), second(second) {
	}

	MyPair Add(const MyPair &c2) {
		MyPair &c1 = *this;
		return MyPair(c1.GetFirst() + c2.GetFirst(), c1.GetSecond() + c2.GetSecond());
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
};

MyPair operator +(const MyPair &c1, const MyPair &c2) {
	return MyPair(c1.GetFirst() + c2.GetFirst(),
			      c1.GetSecond() + c2.GetSecond());
}
MyPair operator +(const MyPair &c1, int x) {
	return MyPair(c1.GetFirst() + x,
			      c1.GetSecond() + x);
}
MyPair operator *(int x, const MyPair &c1) {
	return MyPair(c1.GetFirst() * x,
			      c1.GetSecond() * x);
}
MyPair operator -(const MyPair &c1, pair<int, int> p) {
	return MyPair(c1.GetFirst() - p.first,
			      c1.GetSecond() - p.second);
}

int main() {
	pair<int, int> p = make_pair(1, 3);
	MyPair x(1, 2);
	MyPair z1 = x + 5;	// CE: 5+x
	MyPair z2 = 3 * x;	// CE: x * 3
	MyPair z3 = x - p;	// CE: p - x
	z1.print();	// (6,7)
	z2.print();	// (3,6)
	z3.print();	// (0,-1)

	MyPair z4 = 3 * x + 5 + x;
	z4.print();	// (9,13)

	return 0;
}
