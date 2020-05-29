#pragma once

#include<iostream>
#include<string>

#include "ProductCart.h"

class Product
{
private:
	friend class ProductCart;
	friend class Chocolate;
	friend class Monitor;

	static int counterId;

	int id;

	std::string name;

	std::string description;

	std::string brand;

	double price;

	int quantity;

	double discountInPercentige;

	int IncreaseIdCounter();

public:
	Product();
	Product(const std::string& name, const std::string& description, const std::string& brand, const double& price, const int& quantity, const double& discountInPercentige);
	Product(const Product& obj);
	~Product();

	virtual const int GetId() const;

	virtual const bool SetName(const std::string& name);
	virtual const std::string GetName() const;

	virtual const bool SetBrand(const std::string& brand);
	virtual const std::string GetBrand() const;

	virtual const bool SetDescription(const std::string& description);
	virtual const std::string GetDescription() const;

	virtual const bool SetPrice(const double& price);
	virtual const double GetPrice() const;

	virtual const bool IncreaseQuantity(const int& quantity);
	virtual const bool DecreaseQuantity(const int& quantity);
	virtual const int GetQuantity()const;

	virtual const bool SetDiscountInPercentige(const double& discount);
	virtual const double GetDiscountInPercentige() const;

	virtual void PrintProduct() const;
	virtual void PrintProductName() const;

	virtual Product& operator =(const Product& obj);
	virtual  const bool operator ==(const Product& obj) const;
};

