#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/

bool isValid(string string) {
    map<char, char> mp;	// mp the close of each
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';

    stack<char> parentheses;

    for (char ch: string) {
    	if (mp.count(ch)) {
    		// A close one. It must match open one
    		if (parentheses.empty())
    			return false;

    		char open = mp[ch];
    		char cur_open = parentheses.top();

    		if (open != cur_open)
    			return false;
    		parentheses.pop();
    	}
    	else
    		parentheses.push(ch);
    }
    return parentheses.empty();
}


int main() {
	cout<<isValid("()")<<"\n";
	cout<<isValid("()()")<<"\n";
	cout<<isValid("(()())")<<"\n";
	cout<<isValid("{}{}")<<"\n";
	cout<<isValid("(((())))")<<"\n";
	cout<<isValid("([])")<<"\n";
	cout<<isValid("()[]{}")<<"\n";
	cout<<isValid("{[]}")<<"\n";

	cout<<isValid("(]")<<"\n";
	cout<<isValid("())")<<"\n";
	cout<<isValid("(][)")<<"\n";
	cout<<isValid("(]")<<"\n";
	cout<<isValid(" ([)]")<<"\n";



	return 0;
}
