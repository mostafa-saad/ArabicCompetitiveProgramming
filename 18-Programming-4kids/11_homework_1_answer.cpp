#include<iostream>
using namespace std;

int main() {
	string big_str, small_str;

	cin >> big_str >> small_str;

	if (small_str.size() > big_str.size()) {
		cout << "NO\n";
		return 0;
	}

	// Compare the begin of the small with the large
	for (int i = 0; i < (int) small_str.size(); i++) {
		if (big_str[i] != small_str[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}
