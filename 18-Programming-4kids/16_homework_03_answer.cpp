#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int reverse_num(int num) {
	if (num == 0)
		return 0;

	stack<int> s;
	while (num)
		s.push(num % 10), num /= 10;

	int tens = 1;
	while(!s.empty())
		num = s.top() * tens + num, tens *= 10, s.pop();

	return num;
}

int main() {

	cout<<reverse_num(123456);

	return 0;
}
