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

	const Rectangle* r2 = new Rectangle (4, 5);
	// r3->SetWidth(10.2);	// Can't, const data
	r2 = & r1;				// Ok, not const pointer

	Rectangle* const r3 = new Rectangle (1, 2);
	r3->SetWidth(10.2);		// Ok, non-const data
	// r3 = & r1;			// Can't, const pointer

	const Rectangle* const r4 = new Rectangle (1, 2);
	//r4->SetWidth(10.2);		// Can't, const data
	//r4 = & r1;				// Can't, const pointer

	const Rectangle* const r5 = &r1;	// The opposite is not ok

	return 0;
}
