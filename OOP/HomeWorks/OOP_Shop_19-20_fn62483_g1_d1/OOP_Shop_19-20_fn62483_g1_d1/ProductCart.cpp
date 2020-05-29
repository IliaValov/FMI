#include "ProductCart.h"

ProductCart::ProductCart()
{
	this->id = 0;
	this->price = 0;
	this->quantity = 0;
	this->discountInPercentige = 0;
}

ProductCart::ProductCart(const Product& obj)
{
	this->id = obj.id;
	this->name = obj.name;
	this->price = obj.price;
	this->quantity = obj.quantity;
	this->discountInPercentige = obj.discountInPercentige;
}

ProductCart::ProductCart(const Product& obj, const std::string& categoryName)
{
	this->id = obj.id;
	this->name = obj.name;
	this->price = obj.price;
	this->quantity = obj.quantity;
	this->discountInPercentige = obj.discountInPercentige;
	this->categoryName = categoryName;
}

ProductCart::~ProductCart()
{
}

const int ProductCart::GetId() const
{
	return this->id;
}

const std::string ProductCart::GetCategoryName() const
{
	return this->categoryName;
}

const bool ProductCart::SetCategoryName(const std::string& categoryName)
{
	//TODO VALIDATION

	this->categoryName = categoryName;

	return true;
}

const std::string ProductCart::GetProductName()const
{
	return this->name;
}

const double ProductCart::GetPrice()const
{
	return this->price;
}

const double ProductCart::GetDiscountInPercentige()const
{
	return this->discountInPercentige;
}

const int ProductCart::GetQuantity()const
{
	return this->quantity;
}

void ProductCart::PrintProduct()
{
	std::cout << this->name;
}

void ProductCart::PrintProductName() const
{
	std::cout << this->name
		<< " " << this->categoryName
		<< " " << this->price
		<< " " << this->quantity
		<< " " << this->price * this->quantity;
}

ProductCart& ProductCart::operator=(const Product& obj)
{
	this->id = obj.id;
	this->name = obj.name;
	this->price = obj.price;
	this->quantity = obj.quantity;
	this->discountInPercentige = obj.discountInPercentige;

	return *this;
}
