#pragma once
#include "ProductType.h"
#include "String.h"

class Product
{
private:

	String name;

	String description;

	String brand;

	double price;

	int quantity;

	double discountInPercentige;

	ProductType productType;

public:
	Product();
	~Product();

	bool Set_Name(String* name);
	String Get_Name();

	bool Set_Brand(String* brand);
	String Get_Brand();

	bool Set_Description(String* description);
	String Get_Description();

	bool Set_Price(double price);
	double Get_Price();

	bool Set_Quantity(int quantity);
	int Get_Quantity(int quantity);

	bool Set_DiscountInPercentige(double discount);
	double Get_DiscountInPercentige();

	bool Set_ProductType(ProductType type);
	ProductType Get_ProductType();
};

