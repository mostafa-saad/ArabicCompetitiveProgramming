#include<iostream>
using namespace std;

int main() {
	string big_str, small_str;
	cin >> big_str >> small_str;

	if (small_str.size() > big_str.size()) {
		cout << "NO\n";
		return 0;
	}

	// Keep match letters in order from the big in the small
	int next_to_match = 0;
	for (int i = 0; i < (int) big_str.size(); ++i) {
		if (big_str[i] == small_str[next_to_match]) {
			++next_to_match;
			if (next_to_match == (int)small_str.size()) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";

	return 0;
}
