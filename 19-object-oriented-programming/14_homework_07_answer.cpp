#include <bits/stdc++.h>
using namespace std;

class Double {
private:
	double d;
	const double EPS = (1e-10);

	// return -1 if a < b, 0 if equal and 1 if a > b
	int dcmp(double a, double b) const {
		return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1;
	}
public:
	Double() : d(0) {
	}
	Double(double d) : d(d) {
	}
	bool operator <(const Double& D) const {
		return dcmp(d, D.d) < 0;
	}
	bool operator >(const Double& D) const {
		return dcmp(d, D.d) > 0;
	}
	bool operator ==(const Double& D) const {
		return dcmp(d, D.d) == 0;
	}
	bool operator <=(const Double& D) const {
		return !(*this > D);
	}
	bool operator >=(const Double& D) const {
		return !(*this < D);
	}
};

int main() {
	double d1 = 1 + 3.0 / 7.0 -1;
	double d2 = 3.0 / 7.0;

	// 0.428571 0.428571 0
	// If gave true, play with similar examples
	cout<<d1<<" "<<d2<<" "<<(d1 == d2)<<"\n";

	Double cd1(d1);
	Double cd2(d2);

	cout<<(cd1 == cd2)<<"\n";	// true

	map<Double, string> map;
	map[cd1] = 10;
	map[cd2] = 20;

	cout<<map.size();	// 1

	return 0;
}
