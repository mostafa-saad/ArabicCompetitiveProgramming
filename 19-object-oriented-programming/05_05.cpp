#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	double width;
	double height;

public:
	Rectangle(int width, int height) : width(0), height(0) {
	}

	// This code won't compile.
	// You must provide default if have other ructors

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
	cout << r1.ComputeArea() << "\n";	// 50

	return 0;
}
