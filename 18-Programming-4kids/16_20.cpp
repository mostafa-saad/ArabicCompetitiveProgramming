#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int sum_vec(vector<int> &a) {
	int sum = 0;
	for (auto x : a)
		sum += x;
	return sum;
}

int max_3stack_sum(vector<int> &a, vector<int> &b, vector<int> &c) {
	int sa = sum_vec(a), sb = sum_vec(b), sc = sum_vec(c);

	while(!a.empty() && !b.empty() && !c.empty())
	{
		if(sa == sb && sb == sc)
			return sa;	// as all +ve, this is tha max possible

		// Remove top element from max-sum stack
		if (sa >= sb && sa >= sc)
			sa -= a.back(), a.pop_back();
		else if (sb >= sa && sb >= sc)
			sb -= b.back(), b.pop_back();
		else
			sc -= c.back(), c.pop_back();
	}
	return 0;
}

int main() {

	vector<int> a = {1, 2, 3, 4};
	vector<int> b = {2, 2, 2, 4, 0};
	vector<int> c = {0, 3, 3, 5};

	cout<<max_3stack_sum(a, b, c);

	return 0;
}
