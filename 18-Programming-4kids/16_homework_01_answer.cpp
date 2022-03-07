#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse_queue(queue<int>& q) {
	stack<int> s;

	while(!q.empty())
		s.push(q.front()), q.pop();

	while(!s.empty())
		q.push(s.top()), s.pop();
}

int main() {

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	reverse_queue(q);

	while(!q.empty())
		cout<<q.front()<<" ", q.pop();

	return 0;
}
