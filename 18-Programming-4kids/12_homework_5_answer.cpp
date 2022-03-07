#include<iostream>
using namespace std;

int main() {

	if (false) {
		int idx = 0;
		for (int dep = 0; dep < 3; ++dep)
			for (int row = 0; row < 4; ++row)
				for (int col = 0; col < 5; ++col)
					cout << idx++ << " = " << dep << " " << row << " " << col
							<< "\n";
	}

	int D, R, C, type;
	int d, r, c, idx;

	cin >> D >> R >> C >> type;

	int Db = R * C;
	int Rb = C;

	if (type == 1) {
		cin >> d >> r >> c;
		idx = d * Db + r * Rb + c * 1;
		cout << idx << "\n";
	} else {
		cin>>idx;

		// r * Rb + c * 1 < Db
		d = idx / Db;

		// Remove d part, then extract r
		r = (idx % Db) / Rb;

		c = (idx % Db) % Rb;

		cout << d << " " << r << " " << c << "\n";
	}

	return 0;
}

