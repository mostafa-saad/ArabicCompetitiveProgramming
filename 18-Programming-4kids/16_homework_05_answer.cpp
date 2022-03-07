#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, set<string> > mp;

	int n;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;

		// add all prefixes to the map
		string cur = "";
		for (auto c : str)
			cur += c, mp[cur].insert(str);
	}

	cin >> n;

	while (n--) {
		string str;
		cin >> str;

		for (auto cur : mp[str])
			cout << cur << " ";
		cout << "\n";
	}

	return 0;
}
