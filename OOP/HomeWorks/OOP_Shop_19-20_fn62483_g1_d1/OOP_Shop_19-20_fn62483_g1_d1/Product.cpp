#include "Product.h"

Product::Product() {
	this->price = 0;
	this->discountInPercentige = 0;
	this->quantity = 0;
}

Product::Product(const String& name, const String& description, const String& brand, const double& price, const int& quantity, const double& discountInPercentige)
{
	this->name = name;
	this->description = description;
	this->brand = brand;
	this->price = price;
	this->quantity = quantity;
	this->discountInPercentige = discountInPercentige;
}

Product::Product(const Product& obj)
{
	this->name = obj.name;
	this->description = obj.description;
	this->brand = obj.brand;
	this->price = obj.price;
	this->quantity = obj.quantity;
	this->discountInPercentige = obj.discountInPercentige;
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

bool Product::Set_Price(const double& price)
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

bool Product::Set_Quantity(const int& quantity)
{
	if (quantity < 0) {
		return false;
	}

	this->quantity = quantity;

	return true;
}

int Product::Get_Quantity()
{
	return this->quantity;
}

bool Product::Set_DiscountInPercentige(const double& discount)
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

void Product::Print_Product()
{
	std::cout << "	-name: " << this->name << "\r\n";
	std::cout << "	-brand: " << this->brand << "\r\n";
	std::cout << "	-description: " << this->description << "\r\n";
	std::cout << "	-price: " << this->price << "\r\n";
	std::cout << "	-quantity: " << this->quantity << "\r\n";
	std::cout << "	-discount: " << this->discountInPercentige << "%\r\n";
}

void Product::Print_Product_Name()
{
	std::cout << "	-name: " << this->name << "\r\n";
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

	else
		return true;
}


