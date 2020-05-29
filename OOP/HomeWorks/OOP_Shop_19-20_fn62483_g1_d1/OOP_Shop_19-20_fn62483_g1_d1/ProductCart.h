#pragma once
#include<iostream>
#include<string>

#include "Product.h"

class ProductCart
{
private:
	friend class Product;

	int id;

	std::string name;

	std::string categoryName;

	double price;

	int quantity;

	double discountInPercentige;
public:
	ProductCart();

	ProductCart(const Product& obj);

	ProductCart(const Product& product, const std::string& categoryName);

	~ProductCart();

	const int GetId() const;

	const std::string GetCategoryName()const;
	const bool SetCategoryName(const std::string& categoryName);

	const std::string GetProductName()const;

	const double GetPrice()const;

	const double GetDiscountInPercentige()const;

	const int GetQuantity() const;

	void PrintProduct();
	void PrintProductName() const;

	ProductCart& operator =(const Product& obj);
};

