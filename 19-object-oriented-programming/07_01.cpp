#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	double width;
	double height;

public:
	Rectangle(double width = 0.0, double height = 0.0) :
			width(width), height(height) {
	}
	double ComputeArea() const {
		// CE: function is cont, can't change member variables
		// width = 1;
		return width * height;
	}
	// Setters & Getters
	double GetHeight() const {
		return height;
	}
	void SetHeight(double height) {
		this->height = height;
	}
	double GetWidth() const {
		return width;
	}
	void SetWidth(double width) {
		this->width = width;
	}
};

int main() {
	Rectangle r1(2, 3);
	r1.ComputeArea();
	r1.SetWidth(10);

	const Rectangle r2(4, 5);
	r2.ComputeArea();
	// CE: const object can't call non-const member function
	// r2.SetWidth(10);

	return 0;
}
