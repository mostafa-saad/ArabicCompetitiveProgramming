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

	MyPair operator !() {
		cout<<"Here\n";
		MyPair &c1 = *this;
		return MyPair(-1 * c1.GetFirst(),
				      -1 * c1.GetSecond());
	}
};

int main() {
	MyPair x(1, 2);
	x = !x;
	x.print();	// (-1,-2)

	return 0;
}
