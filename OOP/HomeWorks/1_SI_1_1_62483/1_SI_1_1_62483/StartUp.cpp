#include <iostream>
#include "IntCounter.h"
#include "SVG.h"
#include "String.h"

int main() {

	String temp("Hello world");
	temp.Print();
	temp.Append('!');
	temp.Print();

	/*int* some_number = new int(5);
	
	{
		IntCounter first(some_number);
		std::cout << first.GetCount() << std::endl;
		IntCounter second = first;
		std::cout << first.GetCount() << std::endl;

		{
			IntCounter third(second);
			std::cout << first.GetCount() << std::endl;
		}
		std::cout << first.GetCount() << std::endl;
	}

	std::cout << *some_number;*/
	
	/*SVG svg;

	Point point1(1, 2);
	Point point2(3, 1);

	Rectangle rec(point2, point1);

	Point point3(1, 4);
	Point point4(4, 1);

	

	svg.AddRectangle(rec);

	svg.CreateAndAddRectangle(point4, point3);

	std::cout << svg.GetIndexByBiggestRectangleArea();
	*/
	return 0;
}