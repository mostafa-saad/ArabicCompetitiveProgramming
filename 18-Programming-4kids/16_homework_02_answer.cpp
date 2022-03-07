#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/implement-a-stack-using-single-queue/

struct OurStack {
	queue<int> q;

	/**
	 * To work properly, we need q always represents a stack at its front
	 * E.g. for pushes {1, 2, 3}, q should be {3, 2, 1}
	 *
	 * Assume a new value is 7, so we need q to be: 7, 3, 2, 1?
	 * But how can we put 4 at its front without using extra data structures?
	 *
	 * Let's add 7 normally: so now we have 3, 2, 1, 7
	 * Now remove from the front 3 and add it to queue => 2, 1, 7, 3
	 * Do same for 2, 1
	 */
	void push(int val) {
		int s = q.size();
		q.push(val);

		while (s--)
			q.push(q.front()), q.pop();

	}
	void pop() {
		if (!q.empty())
			q.pop();
	}
	int top() {
		return q.front();
	}
	bool empty() {
		return q.empty();
	}
};

int main() {

	OurStack s;
	s.push(1);
	s.push(2);
	s.push(3);

	while (!s.empty())
		cout << s.top() << " ", s.pop();

	return 0;
}
