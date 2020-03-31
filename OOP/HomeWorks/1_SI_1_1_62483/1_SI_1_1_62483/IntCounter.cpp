#include "IntCounter.h"

IntCounter::IntCounter(const int* num)
{
	this->references = new int(1);
	this->number = num;
}

IntCounter::IntCounter(const IntCounter& obj)
{
	this->number = obj.number;
	this->references = obj.references;
	*this->references = *obj.references + 1;
}

IntCounter::~IntCounter()
{
	*this->references = *this->references - 1;

	if (*this->references == 0) {
		delete[] this->number;
		delete[] this->references;
	}
}

int IntCounter::GetCount()
{
	return *this->references;
}

int IntCounter::GetNumber()
{
	return *this->number;
}

IntCounter IntCounter::operator=(const IntCounter& obj)
{
	if (this != &obj) {

		this->number = obj.number;
		this->references = obj.references;

		*this->references = *obj.references + 1;

	}

	return *this;
}
