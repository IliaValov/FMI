#include "Resolution.h"

Resolution::Resolution() : width(0), height(0)
{
}

Resolution::Resolution(const int& width, const int& height) : width(width), height(height)
{
}

const String& Resolution::GetResolution()
{
	return this->width + "/" + this->height;
}

void Resolution::SetResolution(const int& width, const int& height)
{
	this->width = width;
	this->height = height;
}
