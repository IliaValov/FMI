#include "Product.h"


int Product::IncreaseIdCounter()
{
	return this->counterId++;
}

Product::Product() {
	this->id = this->IncreaseIdCounter();
	this->price = 0;
	this->discountInPercentige = 0;
	this->quantity = 0;
}

Product::Product(const std::string& name, const std::string& description, const std::string& brand, const double& price, const int& quantity, const double& discountInPercentige)
{
	this->id = this->IncreaseIdCounter();
	this->name = name;
	this->description = description;
	this->brand = brand;
	this->price = price;
	this->quantity = quantity;
	this->discountInPercentige = discountInPercentige;
}

Product::Product(const Product& obj)
{
	this->id = obj.id;
	this->name = obj.name;
	this->description = obj.description;
	this->brand = obj.brand;
	this->price = obj.price;
	this->quantity = obj.quantity;
	this->discountInPercentige = obj.discountInPercentige;
}

Product::~Product() {
}

const int Product::GetId()const
{
	return this->id;
}

const bool Product::SetName(const std::string& name)
{
	this->name = name;

	return true;
}

const std::string Product::GetName() const
{
	return this->name;
}

const bool Product::SetBrand(const std::string& brand)
{
	this->brand = brand;

	return true;
}

const  std::string Product::GetBrand() const
{
	return this->brand;
}

const bool Product::SetDescription(const std::string& description)
{
	this->description = description;

	return true;
}

const std::string Product::GetDescription() const
{
	return this->description;
}

const bool Product::SetPrice(const double& price)
{
	if (price < 0) {
		return false;
	}

	this->price = price;

	return true;
}

const double Product::GetPrice() const
{
	if (this->discountInPercentige > 0) {
		return price - (price * (this->discountInPercentige / 100));
	}

	return this->price;
}

const bool Product::IncreaseQuantity(const int& quantity)
{
	if (quantity < 0) {
		return false;
	}

	this->quantity += quantity;

	return true;
}

const bool Product::DecreaseQuantity(const int& quantity)
{
	if (quantity < 0 || quantity > this->quantity) {
		return false;
	}

	this->quantity -= quantity;

	return true;
}

const int Product::GetQuantity()const
{
	return this->quantity;
}

const bool Product::SetDiscountInPercentige(const double& discount)
{
	if (discount >= 100 || discount < 0) {
		return false;
	}

	this->discountInPercentige = discount;

	return true;
}

const double Product::GetDiscountInPercentige()const
{
	return this->discountInPercentige;
}

void Product::PrintProduct() const
{
	std::cout << "	-name: " << this->name << "\r\n";
	std::cout << "	-brand: " << this->brand << "\r\n";
	std::cout << "	-description: " << this->description << "\r\n";
	std::cout << "	-price: " << this->price << "\r\n";
	std::cout << "	-quantity: " << this->quantity << "\r\n";
	std::cout << "	-discount: " << this->discountInPercentige << "%\r\n";
}

void Product::PrintProductName() const
{
	std::cout << "	-name: " << this->name << "\r\n";
}

Product& Product::operator=(const Product& obj)
{
	if (this != &obj) {
		this->id = obj.id;
		this->name = obj.name;
		this->description = obj.description;
		this->brand = obj.brand;
		this->price = obj.price;
		this->quantity = obj.quantity;
		this->discountInPercentige = obj.discountInPercentige;
	}

	return *this;
}

const bool Product::operator==(const Product& obj) const
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


