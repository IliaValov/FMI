#pragma once
#include "Product.h"
#include "List.h"
#include "String.h"

class Shop
{
private:
	String name;

	//List<Product> products;
	//List<Product> products;

public:
	Shop();
	~Shop();

	bool Set_Name(char* name);

	String Get_Name();

	Product Get_Product_By_Index(int i);

	Product Get_Product_By_Name(char* name);

	bool Add_Product(Product product);

	bool Any_Product_By_Name(char* name);
};

