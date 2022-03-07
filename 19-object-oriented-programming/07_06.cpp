#include <bits/stdc++.h>
using namespace std;

class Test {
public:
	int x;
	static int factorial(int n) {
		//x = 10;	// can't access member data

		int res = 1;
		for (int i = 1; i <= n; ++i)
			res *= i;
		return res;
	}
};

int main() {
	cout<<Test::factorial(5);

	return 0;
}
