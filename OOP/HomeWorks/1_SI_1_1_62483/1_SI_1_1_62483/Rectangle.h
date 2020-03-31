#pragma once
#include "Point.h"
class Rectangle
{
private:
	friend class Point;

	double width;
	double height;

	double CalculateWidthBetweenTwoPoints(const Point& point1, const Point& point2);
	double CalculateHeightBetweenTwoPoints(const Point& point1, const Point& point2);
public:
	Rectangle();
	Rectangle(const Point& point1, const Point& point2);
	Rectangle(const Rectangle& obj);
	~Rectangle();

	void SetSides(const Point& point1, const Point& point2);

	double GetArea();
};

