#include "Òangerine.h"

Òangerine::Òangerine()
{
}

Òangerine::Òangerine(String color, String size, String taste)
{
}

Òangerine::Òangerine(Òangerine& obj)
{
}

Òangerine::~Òangerine()
{
}

String Òangerine::Get_Color()
{
	return this->color;
}

void Òangerine::Set_Color(String color)
{
	this->color = color;
}

String Òangerine::Get_Size()
{
	return this->size;
}

void Òangerine::Set_Size(String size)
{
	this->size = size;
}

String Òangerine::Get_Taste()
{
	return this->taste;
}

void Òangerine::Set_Taste(String taste)
{
	this->taste = taste;
}
