#include<iostream>
using namespace std;

int main() {
	int n, m, k, r = 0, c = 0;

	cin >> n >> m >> k;

	// Direction from 1 to 4: up, right, down, left
	int rd[4] = { -1, 0, 1, 0 };
	int cd[4] = { 0, 1, 0, -1 };

	while (k--) {
		int dir, steps;
		cin >> dir >> steps;
		--dir;

		r = (r + rd[dir] * steps) % n;
		c = (c + cd[dir] * steps) % m;

		if (r < 0)
			r += n;
		if (c < 0)
			c += m;

		cout << r << " " << c << "\n";
	}

	return 0;
}

