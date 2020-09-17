#include <bits/stdc++.h>
using namespace std;

class Shape {
private:
	string name;
public:
	Shape(string name) :
			name(name) {
	}

	virtual int Area() {
		throw logic_error("Not implemented. Do override");
		return -1;
	}

	string GetShapeName() {
		return name;
	}
	virtual ~Shape() {}
};

class Rectangle: public Shape {
	int wid;
	int height;
public:
	Rectangle(string name, int wid, int height) :
			Shape(name), wid(wid), height(height) {
	}
	int Area() {
		return wid * height;
	}
};

void process(Shape* shape) {
	// This function knows nothing about children!

	// Compile time determined
	cout << "This shape's name is: " << shape->GetShapeName() << ". ";

	// Run Time determined
	cout << "Its area: " << shape->Area() << "\n";
}

int main() {
	Rectangle r("Nice Rect", 4, 5);

	process(&r);

	return 0;
}
