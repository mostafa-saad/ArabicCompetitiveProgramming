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

	MyPair(int x) :
			MyPair(x, x) {
	}

	MyPair(int first, int second) :
			first(first), second(second) {
	}

	MyPair(pair<int, int> p) :	// Use explicit
			first(p.first), second(p.second) {
	}

	operator int() {
		return first * second;
	}

	operator pair<int, int>() {
		return make_pair(first, second);
	}
};

int main() {
	MyPair x(2, 3);

	int r = x;				// 6
	pair<int, int> p = x;	// operator pair<int, int>()
	x = p;					// MyPair(pair<int, int> p)

	cout<<p.first<<" " <<r<<"\n";

	return 0;
}
