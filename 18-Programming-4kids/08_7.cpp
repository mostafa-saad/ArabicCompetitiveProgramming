#include<iostream>
using namespace std;

int main() {
	int end;
	cin >> end;

	int start = 1;

	while (start <= end) {
		if (start % 3 == 0)
			cout << start << "\n";
		start += 1;
	}
	return 0;
}
