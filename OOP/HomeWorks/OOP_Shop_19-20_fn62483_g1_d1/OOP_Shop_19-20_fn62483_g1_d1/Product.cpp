#include "Product.h"

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

	return false;
}

ProductType Product::Get_ProductType()
{
	return this->productType;
}

Product::Product() {
	this->name = new char[41];
	this->brand = new char[41];
	this->description = new char[401];

	this->price = 0;
	this->quantity = 0;
	this->discountInPercentige = 0;

	this->productType = ProductType::None;
}

Product::~Product() {
}

bool Product::Set_Name(String* name)
{
	return false;
}

String Product::Get_Name()
{
	return this->name;
}

bool Product::Set_Brand(String* brand)
{
	return false;
}

String Product::Get_Brand()
{
	return String();
}

bool Product::Set_Description(String* description)
{
	return false;
}

String Product::Get_Description()
{
	return String();
}
