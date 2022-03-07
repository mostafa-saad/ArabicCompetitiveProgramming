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
};

void operator >>(istream &input, MyPair &pair) {
	int a, b;
	cin >> a >> b;
	pair.SetFirst(a);
	pair.SetSecond(b);
}

int main() {
	MyPair x, y;
	cin >> x;
	x.print();

	// But we can't read several objects
	// Recall cin>>x is function that return void
	// What if it return cin object again!
	//cin >> x >> y;

	return 0;
}
