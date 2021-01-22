#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < (int) str.size(); i++) {
		if (i != 0 && str[i - 1] != str[i]) // new group, split by space
			cout <<" ";
		cout << str[i];
	}
	return 0;
}
