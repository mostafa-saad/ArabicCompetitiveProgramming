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
	friend MyPair operator +(const MyPair &c1, const MyPair &c2);
};

MyPair operator +(const MyPair &c1, const MyPair &c2) {
	return MyPair(c1.first + c2.first,
			      c1.second + c2.second);
}

int main() {
	MyPair x(1, 2);
	MyPair y(10, 20);

	//MyPair z = x.Add(y);
	MyPair z = x + y;
	z.print();	// (11,22)

	return 0;
}
