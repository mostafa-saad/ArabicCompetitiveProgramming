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

	bool operator <(const MyPair &c2) {
		MyPair &c1 = *this;

		if (c1.first == c2.first)
			return c1.second < c2.second;

		return c1.first < c2.first;
	}
};

int main() {
	vector<MyPair> vec;
	vec.push_back(MyPair(10, 20));
	vec.push_back(MyPair(10, 7));
	vec.push_back(MyPair(1, 200));

	sort(vec.begin(), vec.end());

	for (auto &pair : vec)
		pair.print();
	// (1,200)  (10,7)  (10,20)

	return 0;
}
