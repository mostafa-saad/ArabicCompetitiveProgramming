/*
Homework 9: Sum numbers from 1 to N


Write a program that reads integer N and Print the sum from 1 to N
	E.g. If input N = 5, then Output is: 15
	Why? As 1+2+3+4+5 = 15
	Below table of more values
	3 ⇒ 6 (1+2+3)
	4 ⇒ 10 (1+2+3+4)
	5 ⇒ 15 (1+2+3+4+5)
You need to find a simple 1 line formula to solve the problem :) 
	Hint: Let N = 8. Write numbers from 1 to 8
	What is the sum of 1st and 8th number? sum of 2nd and 7th? And so on
	Your formula should be good for even and odd N. Be careful programmer!
	What is the maximum N after it overflow occurs? Recall int max is 2147483647

*/

#include<iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	cout<< n * (n+1) / 2;

	/*
	 Why this equation?
	 Here is an intuition for N = 8
	 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8
	 Let's arrange as following
	 1 8   2 7    3 6     4 5       [first number and last number]   [2nd number, and 2nd from back] ...
	 What is the value of each pair? 9 = n+1
	 How many pairs? 4 = n/2

	 So n/2 pair, each has value n+1
	 So total sum is (n * (n+1))/2

	 Now, this works for even N
	 Your turn: why works for odd N
	 
	 More readings: http://mathcentral.uregina.ca/qq/database/qq.02.06/jo1.html
	 */

	return 0;
}

