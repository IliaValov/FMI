#include "Category.h"

Category::Category()
{
}

Category::Category(const String& name)
{
	this->name = name;
}

Category::~Category()
{
}

const bool Category::SetName(const String& name)
{
	this->name = name;

	return true;
}

const int Category::GetProductsLength()
{
	return this->products.GetLength();
}

const String Category::GetName() const
{
	return this->name;
}

const bool Category::AddProduct(const Product& product)
{
	Product temp = product;
	if (this->AnyProductByName(temp.GetName()))
		return false;

	this->products.AddElement(temp);

	return true;
}

const Product Category::GetProductByIndex(const int& index)
{
	if (index >= this->products.GetLength()) {
		return Product();
	}

	return this->products[index];
}

const Product Category::GetProductByName(const String& name)
{
	int length = this->products.GetLength();

	for (int i = 0; i < length; i++)
	{
		if ((this->products[i].GetName()) == name)
		{
			return this->products[i];
		}
	}

	return Product();
}

const List<Product> Category::GetAllProducts()
{
	return this->products;
}

const bool Category::AnyProductByName(const String& name)
{
	int length = this->products.GetLength();

	for (int i = 0; i < length; i++)
	{
		if (this->products[i].GetName() == name)
		{
			return true;
		}
	}

	return false;
}

const bool Category::DeleteProductByIndex(const int& index)
{
	return this->products.DeleteElement(index);
}

const bool Category::DecreaseProductQuantity(int productId, int quantity)
{
	for (int i = 0; i < this->products.GetLength(); i++)
	{
		if (this->products[i].GetId() == productId) {
			this->products[i].DecreaseQuantity(quantity);
			return true;
		}
	}

	return false;
}

void Category::PrintCategory()
{
	std::cout << "	-" << this->name << "\r\n";
}

void Category::PrintCategoryProducts()
{
	std::cout << "Category: " << this->name << "\r\n";
	for (int i = 0; i < this->products.GetLength(); i++)
	{
		this->products[i].PrintProduct();
	}
}

void Category::PrintCategoryProductsNames()
{
	std::cout << "Category: " << this->name << "\r\n";
	for (int i = 0; i < this->products.GetLength(); i++)
	{
		this->products[i].PrintProductName();
	}
}


