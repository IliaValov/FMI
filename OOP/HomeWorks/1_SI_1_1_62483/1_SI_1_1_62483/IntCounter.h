#pragma once
class IntCounter
{
private:
	const int* number;
	int* references;

public:
	//We don't need default constuctor because the value of the number field need to come from outside.
	IntCounter();
	IntCounter(const int* num);
	IntCounter(const IntCounter& obj);
	~IntCounter();

	const int GetCount() const;

	const int GetNumber() const;

	IntCounter operator =(const IntCounter& obj);
};

