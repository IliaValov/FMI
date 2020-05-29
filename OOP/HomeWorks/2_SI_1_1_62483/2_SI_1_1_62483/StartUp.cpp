#include<iostream>
#include "IntCounter.h"

using namespace std;

int main() {

	double* some_number = new double(5);
	IntCounter<double> first(some_number);
	std::cout << first.get_count() << std::endl;
	IntCounter<double> second = first;
	std::cout << first.get_count() << std::endl;

	{
		IntCounter<double> third(second);
		std::cout << first.get_count() << std::endl;
	}
	
	std::cout << first.get_count() << std::endl;

}