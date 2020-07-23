#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string str) {
	// Each integer represents total sum added to this parent Parenthes
	stack<int> st;

	// temp value to help us
	st.push(0);

	for (auto c : str) {
		if (c == '(') {
			st.push(0);	// new parent: current sum = 0
		} else {
			int last = st.top();
			st.pop();

			if (last == 0)
				last = 1;		// case ()
			else
				last *= 2;		// case (A). Get current sum and multiply

			// accumulate to current PARENT Parenthes
			int parent_par = st.top() + last;	// new total sum
			st.pop();
			st.push(parent_par);
		}
	}
	return st.top();
}

int main() {
	cout<<scoreOfParentheses(  "(()(()))(()(()))"  );
	return 0;
}
