#pragma once
#include "Rectangle.h"
class Point
{
private:
	friend class Rectangle;

	double x;
	double y;

public:
	//By default x and y will be 0
	Point();
	Point(double x, double y);
	Point(const Point& obj);
	~Point();

	void SetPoint(double x, double y);

	Point operator=(const Point& obj);
};

