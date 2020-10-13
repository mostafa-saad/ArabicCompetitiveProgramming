#include <bits/stdc++.h>
using namespace std;

vector<int> operator +(const vector<int> &c1, const vector<int> &c2) {
	if(c1.size() > c2.size())
		return c2 + c1;

	vector<int> c = c2;
	for (int i = 0; i < (int)c1.size(); ++i) {
		c[i] += c1[i];
	}
	return c;
}

int main() {
	vector<int> a = {1, 2, 3, 4};
	vector<int> b = {10, 20};

	vector<int> c = a + b;

	for (int i = 0; i < (int)c.size(); ++i)
		cout<<c[i]<<" ";	// 11 22 3 4


	return 0;
}

