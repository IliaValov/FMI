#pragma once

#include "String.h"

class �angerine
{
private:
	String color;
	String size;
	String taste;

public:
	�angerine();
	�angerine(String color, String size, String taste);
	�angerine(�angerine& obj);
	~�angerine();

	String Get_Color();
	void Set_Color(String color);
	
	String Get_Size();
	void Set_Size(String size);

	String Get_Taste();
	void Set_Taste(String taste);


};

