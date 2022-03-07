#include "04_04_rectangle.h"

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
