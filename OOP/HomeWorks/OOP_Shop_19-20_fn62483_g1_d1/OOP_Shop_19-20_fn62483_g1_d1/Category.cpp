#include "Category.h"

Category::Category()
{
}

Category::Category(const std::string& name)
{
	this->name = name;
}

Category::~Category()
{
}

const bool Category::SetName(const std::string& name)
{
	this->name = name;

	return true;
}

const int Category::GetProductsLength() const
{
	return this->products.size();
}

const std::string Category::GetName() const
{
	return this->name;
}

const bool Category::AddProduct(const Product& product)
{
	Product temp = product;
	if (this->AnyProductByName(temp.GetName()))
		return false;

	this->products.push_back(&temp);

	return true;
}

const int Category::GetProductIndexById(const int& id)
{
	for (int i = 0; i < this->products.size(); i++)
	{
		Product currentProduct = *this->products[i];
		if (currentProduct.GetId() == id)
			return i;
	}

	return -1;
}

const Product Category::GetProductByIndex(const int& index)
{
	if (index >= this->products.size()) {
		return Product();
	}

	return *this->products[index];
}

const Product Category::GetProductByName(const std::string& name)
{
	int length = this->products.size();

	for (int i = 0; i < length; i++)
	{
		if (((*this->products[i]).GetName()) == name)
		{
			return *this->products[i];
		}
	}

	return Product();
}

const std::vector<Product*> Category::GetAllProducts()
{
	return this->products;
}

const bool Category::AnyProductByName(const std::string& name) const
{
	int length = this->products.size();

	for (int i = 0; i < length; i++)
	{
		if ((*this->products[i]).GetName() == name)
		{
			return true;
		}
	}

	return false;
}

const bool Category::DeleteProductByIndex(const int& index)
{
	this->products.erase(this->products.begin() + index);

	return true;
}

const bool Category::IncreaseProductQuantityById(const int& productId, const int& quantity)
{
	for (int i = 0; i < this->products.size(); i++)
	{
		if ((*this->products[i]).GetId() == productId) {
			return (*this->products[i]).IncreaseQuantity(quantity);
		}
	}

	return false;
}

const bool Category::IncreaseProductQuantityByIndex(const int& index, const int& quantity)
{
	return (*this->products[index]).IncreaseQuantity(quantity);
}

const bool Category::DecreaseProductQuantityById(const int& productId, const int& quantity)
{
	for (int i = 0; i < this->products.size(); i++)
	{
		if ((*this->products[i]).GetId() == productId) {
			(*this->products[i]).DecreaseQuantity(quantity);
			return true;
		}
	}

	return false;
}

const bool Category::DecreaseProductQuantityByIndex(const int& index, const int& quantity)
{
	return (*this->products[index]).DecreaseQuantity(quantity);
}

void Category::PrintCategory()
{
	std::cout << "	-" << this->name << "\r\n";
}

void Category::PrintCategoryProducts()
{
	std::cout << "Category: " << this->name << "\r\n";
	for (int i = 0; i < this->products.size(); i++)
	{
		(*this->products[i]).PrintProduct();
	}
}

void Category::PrintCategoryProductsNames()
{
	std::cout << "Category: " << this->name << "\r\n";
	for (int i = 0; i < this->products.size(); i++)
	{
		(*this->products[i]).PrintProductName();
	}
}


