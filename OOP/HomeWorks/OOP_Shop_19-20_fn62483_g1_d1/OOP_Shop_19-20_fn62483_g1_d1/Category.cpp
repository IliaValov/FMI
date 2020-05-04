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

const int Category::GetProductIndexById(const int& id)
{
	for (int i = 0; i < this->products.GetLength(); i++)
	{
		Product currentProduct = this->products[i];
		if (currentProduct.GetId() == id)
			return i;
	}

	return -1;
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

const bool Category::IncreaseProductQuantityById(const int& productId, const int& quantity)
{
	for (int i = 0; i < this->products.GetLength(); i++)
	{
		if (this->products[i].GetId() == productId) {
			return this->products[i].IncreaseQuantity(quantity);
		}
	}

	return false;
}

const bool Category::IncreaseProductQuantityByIndex(const int& index, const int& quantity)
{
	return this->products[index].IncreaseQuantity(quantity);
}

const bool Category::DecreaseProductQuantityById(const int& productId, const int& quantity)
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

const bool Category::DecreaseProductQuantityByIndex(const int& index, const int& quantity)
{
	return this->products[index].DecreaseQuantity(quantity);
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


