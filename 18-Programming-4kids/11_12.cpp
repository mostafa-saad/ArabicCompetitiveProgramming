#include <iostream>
using namespace std;

int main() {
	string first, second;

	cin >> first >> second;

	int mx_sz = first.size();

	if (mx_sz < second.size())
		mx_sz = second.size();

	for (int i = 0; i < mx_sz; ++i) {
		if (i < first.size())
			cout << first[i];

		if (i < second.size())
			cout << second[i];
	}

	cout << "\n";
	return 0;
}
