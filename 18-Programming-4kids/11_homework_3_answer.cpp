#include<iostream>
using namespace std;

int main() {
	string big_str, small_str;
	cin >> big_str >> small_str;

	if (small_str.size() > big_str.size()) {
		cout << "NO\n";
		return 0;
	}

	// For every possible position in big_str, try to match with the small
	for (int i = 0; i < (int) big_str.size() - (int) small_str.size() + 1; ++i) {
		bool is_match = true;

		for (int j = 0; j < (int) small_str.size() && is_match; ++j) {
			if (small_str[j] != big_str[i + j])
				is_match = false;
		}
		if (is_match) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";

	return 0;
}
