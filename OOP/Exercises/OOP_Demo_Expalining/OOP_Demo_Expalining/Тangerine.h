#pragma once

#include "String.h"

class Òangerine
{
private:
	String color;
	String size;
	String taste;

public:
	Òangerine();
	Òangerine(String color, String size, String taste);
	Òangerine(Òangerine& obj);
	~Òangerine();

	String Get_Color();
	void Set_Color(String color);
	
	String Get_Size();
	void Set_Size(String size);

	String Get_Taste();
	void Set_Taste(String taste);


};

