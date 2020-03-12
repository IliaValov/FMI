#include "Category.h"

Category::Category()
{
}

Category::~Category()
{
}

void Category::Set_Name(const String name)
{
	this->name = name;
}

String Category::Get_Name()
{
	return this->name;
}

bool Category::Add_Product(Product product)
{
	this->products.Add_Element(product);

	return true;
}

Product Category::Get_Product_By_Index(int index)
{
	if (index >= this->products.Get_Length()) {
		return Product();
	}

	return this->products[index];
}

Product Category::Get_Product_By_Name(String name)
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

const List<Product> Category::Get_Product_All_Products()
{
	return this->products;
}

bool Category::Any_Product_By_Name(String name)
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

