#include<iostream>
using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	bool is_removed[200] = { 0 };

	if (k > n)		// be careful from k = n with the mode trick below
		k = k % n;	// remove useless cycles. Like clock, every 12 hours are same
	int last_pos = 0;

	for (int t = 0; t < n; ++t) {
		int step = 0;
		int last_person = -10;
		while (step < k) {
			if (is_removed[last_pos] == 0)
				last_person = last_pos, step++;
			last_pos = (last_pos + 1) % n;	// loop back to array if needed
		}
		is_removed[last_person] = 1;
		cout << last_person+1 << "\n";
		last_person = -10;
	}

	return 0;
}
