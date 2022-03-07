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
		return MyPair(c1.GetFirst() + c2.GetFirst(),
				      c1.GetSecond() + c2.GetSecond());
	}

	MyPair operator +(const MyPair &c2) {
		MyPair &c1 = *this;
		return MyPair(c1.GetFirst() + c2.GetFirst(),
				      c1.GetSecond() + c2.GetSecond());
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

int main() {
	MyPair x(1, 2);
	MyPair y(10, 20);

	//MyPair z = x.Add(y);
	MyPair z = x + y;
	z.print();	// (11,22)

	return 0;
}
