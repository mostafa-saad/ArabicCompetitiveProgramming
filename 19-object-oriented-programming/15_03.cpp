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

	friend istream & operator >>(istream &input, MyPair &pair);
};

istream & operator >>(istream &input, MyPair &pair) {
	input >> pair.first >> pair.second;
	return input;
}

int main() {
	MyPair x, y;

	cin >> x >> y;

	x.print();
	y.print();



	return 0;
}
