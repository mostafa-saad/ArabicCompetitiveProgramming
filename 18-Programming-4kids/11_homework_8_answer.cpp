#include <iostream>
using namespace std;

int main() {
	string a, b;

	cin >> a >> b;

	int sz = a.size();

	if (sz < b.size())
		sz = b.size();

	int smaller = -1;

	for (int i = 0; smaller == -1 && i < sz; ++i) {
		if (a[i] != b[i]) {
			if (a[i] < b[i])
				smaller = 0;
			else
				smaller = 1;
		}
	}
	if (smaller == -1) { // then the first letters are common. Small in length is smaller
		if (a.size() <= b.size())
			smaller = 0;
		else
			smaller = 1;
	}
	if (smaller == 0)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
