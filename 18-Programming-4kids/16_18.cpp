#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct last_k_numbers_sum_stream {
	int k;

	int sum = 0;
	queue<int> q;

	last_k_numbers_sum_stream(int _k) {
		k = _k;
	}

	int next(int new_num) {
		// Compute and return sum of last K numbers sent so far
		q.push(new_num);
		sum += new_num;

		if((int)q.size() > k) {
			sum -= q.front();
			q.pop();
		}

		return sum;
	}
};


int main() {
	last_k_numbers_sum_stream processor(4);

	int num;
	while(cin>>num)
		cout<<processor.next(num)<<"\n";

	return 0;
}
