#pragma once
#include "String.h"
#include "Product.h"

class ProductCart
{
private:
	String name;

	String description;

	String brand;

	String categoryName;

	double price;

	int quantity;

	double discountInPercentige;
public:
	ProductCart();
	ProductCart(Product& obj);
	ProductCart(const ProductCart& obj);
	ProductCart(Product product, const String categoryName);
	~ProductCart();

	String Get_Category_Name();
	bool Set_Category_Name(const String categoryName);

	String Get_Product_Name();

	String Get_Description();

	String Get_Brand();

	double Get_Price();

	double Get_DiscountInPercentige();

	int Get_Quantity();

	void Print_Product();
	void Print_Product_Name();

	ProductCart operator =(const ProductCart& obj);
	ProductCart operator =(Product& obj);
};

