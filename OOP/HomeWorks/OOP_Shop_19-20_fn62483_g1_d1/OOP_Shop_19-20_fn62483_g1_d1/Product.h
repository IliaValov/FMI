#pragma once
#include "String.h"
#include "ProductCart.h"

class Product
{
private:
	friend class ProductCart;

	String name;

	String description;

	String brand;

	double price;

	int quantity;

	double discountInPercentige;

public:
	Product();
	Product(const String& name, const String& description, const String& brand, const double& price, const int& quantity, const double& discountInPercentige);
	Product(const Product& obj);
	~Product();

	bool Set_Name(const String& name);
	String Get_Name();

	bool Set_Brand(const String& brand);
	String Get_Brand();

	bool Set_Description(const String& description);
	String Get_Description();

	bool Set_Price(const double& price);
	double Get_Price();

	bool Set_Quantity(const int& quantity);
	int Get_Quantity();

	bool Set_DiscountInPercentige(const double& discount);
	double Get_DiscountInPercentige();

	void Print_Product();
	void Print_Product_Name();

	Product operator =(const Product& obj);
	bool operator ==(const Product& obj);
};

