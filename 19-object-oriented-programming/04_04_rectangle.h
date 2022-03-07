#ifndef NUMBER_04_04_RECTANGLE_H_
#define NUMBER_04_04_RECTANGLE_H_

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

#endif /* NUMBER_04_04_RECTANGLE_H_ */
