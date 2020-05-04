#pragma once
#include "String.h"
#include "Product.h"

class ProductCart
{
private:
	friend class Product;

	int id;

	String name;

	String categoryName;

	double price;

	int quantity;

	double discountInPercentige;
public:
	ProductCart();

	ProductCart(const Product& obj);

	ProductCart(const Product& product, const String& categoryName);

	~ProductCart();

	const int GetId() const;

	const String GetCategoryName()const;
	const bool SetCategoryName(const String& categoryName);

	const String GetProductName()const;

	const double GetPrice()const;

	const double GetDiscountInPercentige()const;

	const int GetQuantity() const;

	void PrintProduct();
	void PrintProductName();

	ProductCart& operator =(const Product& obj);
};

