#pragma once
#include "String.h"

class Resolution
{
private:
	int width;
	int height;
public:
	Resolution();
	Resolution(const int& width, const int& heigth);

	const String& GetResolution();
	void SetResolution(const int& width, const int& height);
};

