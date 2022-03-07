#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	double width;
	double height;

public:
	Rectangle() : width(0), height(0) {
		// No arguments
	}

	Rectangle(int width = 0, int height = 0) : width(0), height(0) {
		// default values
	}

	// This code won't compile, as both are same overloaded

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
