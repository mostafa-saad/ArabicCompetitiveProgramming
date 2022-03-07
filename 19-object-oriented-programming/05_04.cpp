#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	double width = 10;
	double height = 20;

public:

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
	cout << r1.ComputeArea() << "\n";	// 200

	return 0;
}
