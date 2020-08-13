#ifndef H02_06_RECTANGLE_H_
#define H02_06_RECTANGLE_H_

class Rectangle {
private:
	double width;
	double height;

public:
	Rectangle();
	Rectangle(double width_, double height_);
	double ComputeArea();
	double ComputePerimeter();
	double GetHeight() const;
	void SetHeight(double height);
	double GetWidth() const;
	void SetWidth(double width);
};

#endif /* H02_06_RECTANGLE_H_ */
