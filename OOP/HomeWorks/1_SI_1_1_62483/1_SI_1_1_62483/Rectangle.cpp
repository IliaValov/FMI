#include "Rectangle.h"

double Rectangle::CalculateWidthBetweenTwoPoints(const Point& point1, const Point& point2)
{
	int result = point1.x - point2.x;

	if (result < 0)
		result *= -1;

	return result;
}

double Rectangle::CalculateHeightBetweenTwoPoints(const Point& point1, const Point& point2)
{
	int result = point1.y - point2.y;

	if (result < 0)
		result *= -1;

	return result;
}

Rectangle::Rectangle()
{
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(const Point& point1, const Point& point2)
{
	this->width = this->CalculateWidthBetweenTwoPoints(point1, point2);
	this->height = this->CalculateHeightBetweenTwoPoints(point1, point2);
}

Rectangle::Rectangle(const Rectangle& obj)
{
	this->width = obj.width;
	this->height = obj.height;
}

Rectangle::~Rectangle()
{
}

void Rectangle::SetSides(const Point& point1, const Point& point2)
{
	this->width = this->CalculateWidthBetweenTwoPoints(point1, point2);
	this->height = this->CalculateHeightBetweenTwoPoints(point1, point2);
}

const double Rectangle::GetArea() const
{
	return this->width * this->height;
}
