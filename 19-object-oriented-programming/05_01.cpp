#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	double width;
	double height;

public:
	Rectangle() {
		width = height = 0;
	}
	Rectangle(double width_, double height_) {
		width = width_;
		height = height_;
	}

	double ComputeArea() {
		return width * height;
	}
	double ComputePerimeter() {
		return 2 * (width + height);
	}
	// Setters & Getters
	double GetHeight()  {
		return height;
	}
	void SetHeight(double height) {
		this->height = height;
	}
	double GetWidth()  {
		return width;
	}
	void SetWidth(double width) {
		this->width = width;
	}
};

int main() {
	Rectangle r1;
	r1.SetWidth(5);
	r1.SetHeight(10);
	cout << r1.ComputeArea() << "\n";	// 50

	Rectangle r2(10, 3);
	cout << r2.ComputeArea() << "\n";	// 30
	r2.SetWidth(0);
	cout << r2.ComputeArea() << "\n";	// 0

	return 0;
}
