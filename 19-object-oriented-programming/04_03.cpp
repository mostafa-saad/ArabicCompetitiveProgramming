#include <bits/stdc++.h>
using namespace std;

class Rectangle {
private:
	double width;
	double height;

public:
	Rectangle();
	Rectangle(double width_, double height_);
	double ComputeArea();
	double ComputePerimeter();
	double GetHeight() ;
	void SetHeight(double height);
	double GetWidth() ;
	void SetWidth(double width);
};

Rectangle::Rectangle() {
	width = height = 0;
}
Rectangle::Rectangle(double width_, double height_) {
	width = width_, height = height_;
}
double Rectangle::ComputeArea() {
	return width * height;
}
double Rectangle::ComputePerimeter() {
	return 2 * (width + height);
}
// Setters & Getters
double Rectangle::GetHeight()  {
	return height;
}
void Rectangle::SetHeight(double height) {
	this->height = height;
}
double Rectangle::GetWidth()  {
	return width;
}
void Rectangle::SetWidth(double width) {
	this->width = width;
}

int main() {
	cout<<pow(2.0, 3.2);
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
