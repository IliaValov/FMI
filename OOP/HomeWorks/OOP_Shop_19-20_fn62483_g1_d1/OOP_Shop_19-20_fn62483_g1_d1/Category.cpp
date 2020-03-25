#include "Category.h"

Category::Category()
{
}

Category::Category(const Category& obj)
{
	this->name = obj.name;
	this->products = obj.products;
}

Category::Category(const String& name)
{
	this->name = name;
}

Category::~Category()
{
}

void Category::Set_Name(const String& name)
{
	this->name = name;
}

int Category::Get_Length()
{
	return this->products.Get_Length();
}

int Category::Get_Products_Length()
{
	return this->products.Get_Length();
}

String Category::Get_Name()
{
	return this->name;
}

bool Category::Add_Product(const Product& product)
{
	Product temp = product;
	if (this->Any_Product_By_Name(temp.Get_Name()))
		return false;

	this->products.Add_Element(temp);

	return true;
}

Product Category::Get_Product_By_Index(const int& index)
{
	if (index >= this->products.Get_Length()) {
		return Product();
	}

	return this->products[index];
}

Product Category::Get_Product_By_Name(const String& name)
{
	int length = this->products.Get_Length();

	for (int i = 0; i < length; i++)
	{
		if (this->products[i].Get_Name() == name)
		{
			return this->products[i];
		}
	}

	return Product();
}

const List<Product> Category::Get_All_Products()
{
	return this->products;
}

bool Category::Any_Product_By_Name(const String& name)
{
	int length = this->products.Get_Length();

	for (int i = 0; i < length; i++)
	{
		if (this->products[i].Get_Name() == name)
		{
			return true;
		}
	}

	return false;
}

bool Category::Delete_Product_By_Index(const int& index)
{
	return this->products.Delete_Element(index);
}

void Category::Print_Category()
{
	std::cout << "	-" << this->name << "\r\n";
}

void Category::Print_Category_Products()
{
	std::cout << "Category: " << this->name << "\r\n";
	for (int i = 0; i < this->products.Get_Length(); i++)
	{
		this->products[i].Print_Product();
	}
}

void Category::Print_Category_Products_Names()
{
	std::cout << "Category: " << this->name << "\r\n";
	for (int i = 0; i < this->products.Get_Length(); i++)
	{
		this->products[i].Print_Product_Name();
	}
}

Category Category::operator=(const Category& obj)
{
	if (this != &obj) {
		this->name = obj.name;
		this->products = obj.products;
	}

	return *this;
}

