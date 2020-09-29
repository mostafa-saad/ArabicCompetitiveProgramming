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

	int operator[]( int pos) const {
		if (pos == 0)
			return GetFirst();
		return GetSecond();
	}
};

int main() {
	MyPair x(10, 20);
	cout<<x[0]<<" "<<x[1]<<"\n";

	// error: lvalue required as left operand of assignment
	// x[0] = 7;
	// x[0] => just a function that return temp var, e.g. g
	// so u r doing g = 7 this has nothing with object x
	// we need g points in memory to first when [0]

	return 0;
}
