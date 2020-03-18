#include "ProductCart.h"

ProductCart::ProductCart()
{
	this->price = 0;
	this->quantity = 0;
	this->discountInPercentige = 0;
}

ProductCart::ProductCart(const ProductCart& obj)
{
	this->name = obj.name;
	this->description = obj.description;
	this->brand = obj.brand;
	this->categoryName = obj.categoryName;
	this->price = obj.price;
	this->quantity = obj.quantity;
	this->discountInPercentige = obj.discountInPercentige;
}

ProductCart::ProductCart(Product& obj)
{
	this->name = obj.Get_Name();
	this->description = obj.Get_Description();
	this->brand = obj.Get_Brand();
	this->price = obj.Get_Price();
	this->quantity = obj.Get_Quantity();
	this->discountInPercentige = obj.Get_DiscountInPercentige();
}

ProductCart::ProductCart(Product product, const String categoryName)
{
	this->name = product.Get_Name();
	this->description = product.Get_Description();
	this->brand = product.Get_Brand();
	this->categoryName = categoryName;
	this->price = product.Get_Price();
	this->quantity = product.Get_Quantity();
	this->discountInPercentige = product.Get_DiscountInPercentige();
}

ProductCart::~ProductCart()
{
}

String ProductCart::Get_Category_Name()
{
	return this->categoryName;
}

bool ProductCart::Set_Category_Name(const String categoryName)
{
	//TODO VALIDATION

	this->categoryName = categoryName;

	return true;
}

String ProductCart::Get_Product_Name()
{
	return this->name;
}

String ProductCart::Get_Description()
{
	return this->description;
}

String ProductCart::Get_Brand()
{
	return this->brand;
}

double ProductCart::Get_Price()
{
	return this->price;
}

double ProductCart::Get_DiscountInPercentige()
{
	return this->discountInPercentige;
}

int ProductCart::Get_Quantity()
{
	return this->quantity;
}

void ProductCart::Print_Product()
{
	std::cout << this->name;
}

void ProductCart::Print_Product_Name()
{
	std::cout << this->name
		<< " " << this->brand
		<< " " << this->categoryName
		<< " " << this->price
		<< " " << this->quantity
		<< " " << this->price * this->quantity;
}

ProductCart ProductCart::operator=(const ProductCart& obj)
{
	if (this != &obj) {
		this->name = obj.name;
		this->description = obj.description;
		this->brand = obj.brand;
		this->categoryName = obj.categoryName;
		this->price = obj.price;
		this->quantity = obj.quantity;
		this->discountInPercentige = obj.discountInPercentige;
	}

	return *this;
}

ProductCart ProductCart::operator=(Product& obj)
{
	this->name = obj.Get_Name();
	this->description = obj.Get_Description();
	this->brand = obj.Get_Brand();
	this->price = obj.Get_Price();
	this->quantity = obj.Get_Quantity();
	this->discountInPercentige = obj.Get_DiscountInPercentige();

	return *this;
}
