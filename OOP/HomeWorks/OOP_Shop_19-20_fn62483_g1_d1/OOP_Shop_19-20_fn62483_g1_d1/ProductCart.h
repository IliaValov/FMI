#pragma once
#include "String.h"
#include "Product.h"

class ProductCart
{
private:
	friend class Product;

	String name;

	String description;

	String brand;

	String categoryName;

	double price;

	int quantity;

	double discountInPercentige;
public:
	ProductCart();

	ProductCart(const ProductCart& obj);

	ProductCart(const Product& obj);

	ProductCart(const Product& product, const String& categoryName);

	~ProductCart();

	String Get_Category_Name();
	bool Set_Category_Name(const String& categoryName);

	String Get_Product_Name();

	String Get_Description();

	String Get_Brand();

	double Get_Price();

	double Get_DiscountInPercentige();

	int Get_Quantity();

	void Print_Product();
	void Print_Product_Name();

	ProductCart operator =(const ProductCart& obj);

	//TODO make it with const ??
	ProductCart operator =(const Product& obj);
};

