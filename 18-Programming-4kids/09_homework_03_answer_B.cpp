#include<iostream>
using namespace std;

int main() {
	int count = 0;

	for (int a = 1; a <= 200; ++a) {
		for (int b = 1; b <= 200; ++b) {
			for (int c = 1; c <= 200; ++c) {
				int d = a + b - c;

				if(1 <= d && d <= 200)
					count++;
			}
		}
	}

	cout << count << "\n";

	return 0;
}

