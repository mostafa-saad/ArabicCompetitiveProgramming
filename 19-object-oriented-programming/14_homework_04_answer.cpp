#include <bits/stdc++.h>
using namespace std;

class MyPair {
private:
	int first, second;

public:
	virtual ~MyPair() {}
	MyPair(int first, int second) :
			first(first), second(second) {
	}

	virtual void print() {
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

class NamedPair : public MyPair{
private:
	string name;
public:
	NamedPair(string name, int first, int second) : MyPair(first, second), name(name) {
	}

	bool operator <(const NamedPair &c2) {
		NamedPair &c1 = *this;

		if (c1.name == c2.name)
			return MyPair::operator <(c2);

		return c1.name < c2.name;
	}

	virtual void print() {
		cout << "(" << name<<": "<<GetFirst() << "," << GetSecond()<< ")\n";
	}
};

int main() {
	vector<NamedPair> vec;
	vec.push_back(NamedPair("A", 10, 20));
	vec.push_back(NamedPair("B", 10, 7));
	vec.push_back(NamedPair("B", 1, 200));

	sort(vec.begin(), vec.end());

	for (auto &pair : vec)
		pair.print();
	// ((A: 10,20) (B: 1,200) (B: 10,7)

	return 0;
}
