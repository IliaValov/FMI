#include "SVG.h"

SVG::SVG()
{
}

SVG::~SVG()
{
}

void SVG::AddRectangle(const Rectangle& rectangle)
{
	this->rectangles.AddElement(rectangle);
}

void SVG::CreateAndAddRectangle(const Point point1, const Point point2)
{
	Rectangle rectangle(point1, point2);

	this->rectangles.AddElement(rectangle);
}

const int SVG::GetIndexByBiggestRectangleArea() const
{
	int indexWithTheBiggestRectangleArea = -1;
	double previousArea = -1;

	for (int i = 0; i < this->rectangles.GetLength(); i++)
	{
		double currentArea = this->rectangles[i].GetArea();

		if (currentArea > previousArea) {
			previousArea = currentArea;
			indexWithTheBiggestRectangleArea = i;
		}
	}

	return indexWithTheBiggestRectangleArea;
}
