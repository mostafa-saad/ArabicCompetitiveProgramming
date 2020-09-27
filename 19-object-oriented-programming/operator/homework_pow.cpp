#include <bits/stdc++.h>
using namespace std;

class MyNumber {
public:
	int num;
	MyNumber(int num) : num(num) {	}
};

MyNumber operator ^(const MyNumber &c1, int pow) {
	int res = 1;
	while (pow--)		res *= c1.num;
	return MyNumber(res);
}

MyNumber operator +(const MyNumber &c1, const MyNumber &c2) {
	return MyNumber(c1.num + c2.num);
}

int main() {
	MyNumber x(2);
	MyNumber res1 = x^3;
	MyNumber res2 = 1 + x^3;
	cout<<res1.num <<" "<<res2.num;

	return 0;
}



/*
8 27  NOT 8 9 as a user will expect!


In basic mathematics, exponentiation is resolved before basic arithmetic, so 4 + 3 ^ 2 resolves as 4 + (3 ^ 2) => 4 + 9 => 13.
However, in C++, the arithmetic operators have higher precedence than operator^, so 4 + 3 ^ 2 resolves as (4 + 3) ^ 2 => 7 ^ 2 => 49.

You’d need to explicitly parenthesize the exponent portion (e.g. 4 + (3 ^ 2)) every time you used it for this to work properly, which isn’t intuitive, and is potentially error-prone.

Because of this precedence issue, it’s generally a good idea to use operators only in an analogous way to their original intent.

Rule: When overloading operators, it’s best to keep the function of the operators as close to the original intent of the operators as possible.

https://www.learncpp.com/cpp-tutorial/91-introduction-to-operator-overloading/

 */
