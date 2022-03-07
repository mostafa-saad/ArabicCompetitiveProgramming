#include <bits/stdc++.h>
using namespace std;

class Point {
private:
	double x;
	double y;
public:
	Point(double x, double y) :
			x(x), y(y) {
	}
	double GetX() const {
		return x;
	}

	void SetX(double x) {
		this->x = x;
	}

	double GetY() const {
		return y;
	}

	void SetY(double y) {
		this->y = y;
	}

	string ToString() const {
		ostringstream oss;
		oss << "(" << x << ", " << y << ")";
		return oss.str();
	}
};

class Shape {
protected:
	int color;
public:
	Shape(int color) :
			color(color) {
	}

	virtual int ComputeArea() const {
		throw logic_error("Not implemented. Do override");
		return -1;
	}
	virtual void Draw() const {
		// Not implemented now
		cout << "Drawing shape of area " << ComputeArea() << "\n";
	}
	virtual Shape* Clone() const {	// virtual copy constructor
		throw logic_error("Not implemented. Do override");
		return nullptr;
	}
	virtual ~Shape() {
	}

	int GetColor() const {
		return color;
	}
	void SetColor(int color) {
		this->color = color;
	}
};

class Rectangle: public Shape {
private:
	Point top_left;
	Point bottom_right;
public:
	Rectangle(int color, const Point &top_left, const Point &bottom_right) :
			Shape(color), top_left(top_left), bottom_right(bottom_right) {
	}
	virtual int ComputeArea() const override {
		return 10;	// just compute
	}
	virtual void Draw() const override {
		Shape::Draw();
		cout << "Drawing rectangle TL " << top_left.ToString()
				<< " - BR " << bottom_right.ToString() << "\n";
	}

	virtual Shape* Clone() const {
		return new Rectangle(*this);
	}
};

class Circle: public Shape {
private:
	Point center;
	double radius;
public:
	Circle(int color, const Point &center, double radius) :
			Shape(color), center(center), radius(radius) {
	}
	virtual int ComputeArea() const override {
		return 20;	// just compute
	}
	virtual void Draw() const override {
		Shape::Draw();
		cout << "Drawing circle center " << center.ToString()
				<< " - radius " << radius << "\n";
	}
	virtual Shape* Clone() const {
		return new Circle(*this);
	}
};

class ImageEditor {
protected:
	vector<Shape*> shapes;

public:
	void AddShape(const Shape &shape) {
		shapes.push_back(shape.Clone());
	}
	virtual void Draw() const {
		cout << "ImageEditor::Draw\n";
		for (auto shapePtr : shapes)
			shapePtr->Draw();
	}
	virtual ~ImageEditor() {
		for (auto shapePtr : shapes) {
			delete shapePtr;
		}
		shapes.clear();
	}
};

class AdobeImageEditor: public ImageEditor {
public:
	void EnlargeShpaes(double percent) {
		for (auto shapePtr : shapes) {
			// Enlarge
		}
	}
};

void initalize(AdobeImageEditor* editor) {
	Rectangle r1(10, Point(3, 4), Point(5, 6));
	Circle c1(20, Point(8, 9), 3.5);

	editor->AddShape(r1);
	editor->AddShape(c1);
}

int main() {
	AdobeImageEditor* editor = new AdobeImageEditor();

	initalize(editor);
	editor->Draw();
	editor->EnlargeShpaes(0.5);

	delete editor;
	editor = nullptr;

	cout << "Bye";

	return 0;
}
