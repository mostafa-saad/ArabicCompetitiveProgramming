#include <bits/stdc++.h>
using namespace std;

// Original Src: https://en.cppreference.com/w/cpp/language/operators

class Fraction {
private:
	int n, d;

public:
	Fraction(int n, int d = 1) :
			n(n / __gcd(n, d)), d(d / __gcd(n, d)) {
	}
	int num() const {
		return n;
	}
	int den() const {
		return d;
	}

	Fraction& operator*=(const Fraction& rhs) {
		// Some math to multiply and simplify
		int new_n = n * rhs.n / __gcd(n * rhs.n, d * rhs.d);
		d = d * rhs.d / __gcd(n * rhs.n, d * rhs.d);
		n = new_n;
		return *this;
	}
};
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
	return out << f.num() << '/' << f.den();
}

bool operator==(const Fraction& lhs, const Fraction& rhs) {
	return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}

bool operator!=(const Fraction& lhs, const Fraction& rhs) {
	return !(lhs == rhs);
}

Fraction operator*(Fraction lhs, const Fraction& rhs) {
	// Notice first param without const/ref
	return lhs *= rhs;	// Don;t duplicate
}

int main() {
	Fraction f1(3, 8);
	Fraction f2 = 2 * f1;
	Fraction f3 = f1 * f2;
	Fraction f4 = f3;
	f4 *= f4;

	cout << f1 << "\n" << f2 << "\n" << f3 << "\n" << f4;
}
