#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	double width;
	double height;
	const int tmp1 = 10;	// initialized
	const int tmp2;

public:
	Rectangle(double width = 0.0, double height = 0.0) :
			width(width), height(height), tmp2(6) {
		// tmp2 = 6; can't. must use initializer list
	}
	double ComputeArea() const {
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

	return 0;
}
