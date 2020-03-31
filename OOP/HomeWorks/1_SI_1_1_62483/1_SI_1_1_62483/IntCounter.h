#pragma once
class IntCounter
{
private:
	const int* number;
	int* references;

public:
	//We don't need default constuctor because the value of the number field need to come from outside.
	IntCounter(const int* num);
	IntCounter(const IntCounter& obj);
	~IntCounter();

	int GetCount();

	int GetNumber();

	IntCounter operator =(const IntCounter& obj);
};

