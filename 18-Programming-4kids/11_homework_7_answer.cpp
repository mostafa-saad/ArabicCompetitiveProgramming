#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	str += "$";	// a small trick to avoid special handling for last group

	int group_sz = 1;	// for first letter
	bool is_first_group = true;	// easy mark to avoid early _

	for (int i = 1; i < (int) str.size(); i++) {	// start from 1
		if (str[i - 1] != str[i]) { // new group
			if (!is_first_group)
				cout << "_";	// split with previous group
			cout << str[i - 1] << group_sz;

			group_sz = 0;
			is_first_group = 0;
		}
		++group_sz;
	}
	return 0;
}
