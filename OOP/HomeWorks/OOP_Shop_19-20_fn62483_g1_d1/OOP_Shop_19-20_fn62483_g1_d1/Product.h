#pragma once
#include "String.h"
#include "ProductCart.h"

class Product
{
private:
	friend class ProductCart;
	friend class Chocolate;
	friend class Monitor;

	static int counterId;

	int id;

	String name;

	String description;

	String brand;

	double price;

	int quantity;

	double discountInPercentige;

	int IncreaseIdCounter();
public:
	Product();
	Product(const String& name, const String& description, const String& brand, const double& price, const int& quantity, const double& discountInPercentige);
	Product(const Product& obj);
	~Product();

	virtual const int GetId() const;

	virtual const bool SetName(const String& name);
	virtual String GetName() const;

	virtual const bool SetBrand(const String& brand);
	virtual String GetBrand() const;

	virtual const bool SetDescription(const String& description);
	virtual String GetDescription() const;

	virtual const bool SetPrice(const double& price);
	virtual const double GetPrice() const;

	virtual const bool DecreaseQuantity(const int& quantity);
	virtual const int GetQuantity()const;

	virtual const bool SetDiscountInPercentige(const double& discount);
	virtual const double GetDiscountInPercentige() const;

	virtual void PrintProduct() const;
	virtual void PrintProductName() const;

	virtual Product& operator =(const Product& obj);
	virtual  const bool operator ==(const Product& obj) const;
};

