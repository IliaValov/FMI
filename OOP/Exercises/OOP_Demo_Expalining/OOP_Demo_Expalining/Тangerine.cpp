#include "�angerine.h"

�angerine::�angerine()
{
}

�angerine::�angerine(String color, String size, String taste)
{
}

�angerine::�angerine(�angerine& obj)
{
}

�angerine::~�angerine()
{
}

String �angerine::Get_Color()
{
	return this->color;
}

void �angerine::Set_Color(String color)
{
	this->color = color;
}

String �angerine::Get_Size()
{
	return this->size;
}

void �angerine::Set_Size(String size)
{
	this->size = size;
}

String �angerine::Get_Taste()
{
	return this->taste;
}

void �angerine::Set_Taste(String taste)
{
	this->taste = taste;
}
