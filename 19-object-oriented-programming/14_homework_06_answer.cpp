#include <bits/stdc++.h>
using namespace std;

class MyMap {
private:
	vector<string> vec_strs;
	vector<int> vec_ints;

	int pos = 0;
public:
	int& operator[](const string& s) {
		for (int i = 0; i < (int) vec_strs.size(); ++i) {
			if (vec_strs[i] == s)
				return vec_ints[i];
		}
		vec_strs.push_back(s);
		vec_ints.push_back(0);
		return vec_ints.back();
	}

	vector<string> operator[](int target) {
		vector<string> ret;
		for (int i = 0; i < (int) vec_ints.size(); ++i) {
			if (vec_ints[i] == target)
				ret.push_back(vec_strs[i]);
		}
		sort(ret.begin(), ret.end());
		return ret;
	}
	void Reset_iterator() {
		pos = 0;
	}

	void Clear() {
		vec_strs.clear();
		vec_ints.clear();
		pos = 0;
	}

	bool HasNext() {
		return pos < (int) vec_ints.size();
	}
	pair<string, int> GetNext() {
		assert(HasNext());
		auto p = make_pair(vec_strs[pos], vec_ints[pos]);
		pos++;
		return p;
	}

};

int main() {
	MyMap map;

	map["mostafa"] = 20;
	map["mostafa"] = 40;
	map["sayed"] = 20;
	map["ali"] = 20;

	cout << map["mostafa"] << "\n";	// 40

	vector<string> v = map[20];
	for (auto s : v)
		cout << s << "\n";	// ali sayed

	map.Reset_iterator();
	while (map.HasNext()) {
		auto p = map.GetNext();
		cout << p.first << " " << p.second << "\n";
	}
	map.Clear();

	return 0;
}
