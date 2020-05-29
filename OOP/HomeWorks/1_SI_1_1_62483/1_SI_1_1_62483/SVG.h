#pragma once
#include "List.h"
#include "Rectangle.h"
class SVG
{
private:
	List<Rectangle> rectangles;


public:
	SVG();
	~SVG();

	void AddRectangle(const Rectangle& rectangle);

	void CreateAndAddRectangle(const Point point1, const Point point2);

	const int GetIndexByBiggestRectangleArea() const;
};

