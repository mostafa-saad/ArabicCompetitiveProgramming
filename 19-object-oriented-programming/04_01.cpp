#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
	double width;
	double height;

	Rectangle() {
		width = height = 0;
	}

	Rectangle(double width_, double height_) {
		width = width_, height = height_;
	}

	double ComputeArea() {
		return width * height;
	}
	double ComputePerimeter() {
		return 2 * (width + height);
	}
};

int main() {
	Rectangle r1;
	r1.width = 5;
	r1.height = 10;
	cout << r1.ComputeArea() << "\n";	// 50

	Rectangle r2(10, 3);
	cout << r2.ComputeArea() << "\n";	// 30
	r2.width = 0;
	cout << r2.ComputeArea() << "\n";	// 0

	return 0;
}
