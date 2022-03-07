#include <bits/stdc++.h>
using namespace std;

class LuckyNum {
private:
	int num = 13;
public:

	void PrintAddress() {
		printf("Function address :%p\n", &LuckyNum::PrintAddress);
		printf("Data address :%p\n", &num);
	}
};

int main() {
	LuckyNum r1;
	r1.PrintAddress();


	LuckyNum r2;
	r2.PrintAddress();

	/*
	 * Each object variables will have different address in memory!
	 *
	 * However, function are common procedures
	 * So only one function is loaded in memory with common address
	 */

	return 0;
}
