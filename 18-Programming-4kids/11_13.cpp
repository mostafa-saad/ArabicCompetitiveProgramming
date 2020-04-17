#include <iostream>
using namespace std;

int main() {
	string str;

	cin >> str;

	int frequency[150] = {0};	// initalize to zeros

	for (int i = 0; i < str.size(); ++i)
		frequency[str[i]]++;	// Use char as frequency

	for (int i = 'a'; i <= 'z'; ++i) {
		if (frequency[i])
			cout << (char) i << " " << frequency[i] << "\n";
	}

	return 0;
}
