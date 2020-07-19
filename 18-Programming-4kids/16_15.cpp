#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct employee {
	int num1, num2;
	string str;

	employee(int a, int b, string name) {
		num1 = a, num2 = b, str = name;
	}

	bool operator <(const employee& rhs) const {
		// compare as we did before
		if (false) {
			if (num1 != rhs.num1)
				return num1 < rhs.num1;

			if (str != rhs.str)
				return str < rhs.str;

			return num2 < rhs.num2;
		}

		if (false) {
			// Or use pair
			return make_pair(num1, make_pair(str, num2))
					< make_pair(rhs.num1, make_pair(rhs.str, rhs.num2));
		}

		// To use tie: must be variables
		return std::tie(num1, str, num2) <
				std::tie(rhs.num1, rhs.str, rhs.num2);
	}
};

int main() {
	set<employee> s;
	s.insert(employee(10, 35, "mostafa"));
	s.insert(employee(7, 15, "ali"));
	s.insert(employee(10, 17, "ziad"));
	s.insert(employee(10, 20, "mostafa"));

	for (auto emp : s)
		cout << emp.num1 << " " << emp.str << " " << emp.num2 << "\n";

	return 0;
}

