#include "Point.h"

//By default x and y will be 0
Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& obj)
{

	this->x = obj.x;
	this->y = obj.y;

}

Point::~Point()
{
}

void Point::SetPoint(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point Point::operator=(const Point& obj)
{
	if (this != &obj)
	{
		this->x = obj.x;
		this->y = obj.y;
	}

	return *this;
}
