#include "Product.h"

Product::Product() {

}

Product::Product(const Product& obj)
{
	this->name = obj.name;
	this->description = obj.description;
	this->brand = obj.brand;
	this->price = obj.price;
	this->quantity = obj.quantity;
	this->discountInPercentige = obj.discountInPercentige;
	this->productType = obj.productType;
}

Product::~Product() {
}

bool Product::Set_Name(const String& name)
{
	this->name = name;

	return true;
}

String Product::Get_Name()
{
	return this->name;
}

bool Product::Set_Brand(const String& brand)
{
	this->brand = brand;

	return true;
}

String Product::Get_Brand()
{
	return this->brand;
}

bool Product::Set_Description(const String& description)
{
	this->description = description;

	return true;
}

String Product::Get_Description()
{
	return this->description;
}

bool Product::Set_Price(double price)
{
	if (price < 0) {
		return false;
	}

	this->price = price;

	return true;
}

double Product::Get_Price()
{
	if (this->discountInPercentige > 0) {
		return price - (price * (this->discountInPercentige / 100));
	}

	return this->price;
}

bool Product::Set_Quantity(int quantity)
{
	if (quantity < 0) {
		return false;
	}

	this->quantity = quantity;

	return true;
}

int Product::Get_Quantity(int quantity)
{
	return this->quantity;
}

bool Product::Set_DiscountInPercentige(double discount)
{
	if (discount >= 100 || discount < 0) {
		return false;
	}

	this->discountInPercentige = discount;

	return true;
}

double Product::Get_DiscountInPercentige()
{
	return this->discountInPercentige;
}

bool Product::Set_ProductType(ProductType type)
{
	this->productType = type;

	return true;
}

ProductType Product::Get_ProductType()
{
	return this->productType;
}

Product Product::operator=(const Product& obj)
{
	if (this != &obj) {
		this->name = obj.name;
		this->description = obj.description;
		this->brand = obj.brand;
		this->price = obj.price;
		this->quantity = obj.quantity;
		this->discountInPercentige = obj.discountInPercentige;
		this->productType = obj.productType;
	}

	return *this;
}

bool Product::operator==(const Product& obj)
{
	if (this->name != obj.name) {
		return false;
	}
	else if (this->description != obj.description)
	{
		return false;
	}
	else if (this->brand != obj.brand)
	{
		return false;
	}
	else if (this->price != obj.price)
	{
		return false;
	}
	else if (this->quantity != obj.quantity)
	{
		return false;
	}
	else if (this->discountInPercentige != obj.discountInPercentige)
	{
		return false;
	}
	else if (this->productType != obj.productType)
	{
		return false;
	}
	else
		return true;
}


