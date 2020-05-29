#include "Storage.h"

const int& Storage::FindProductIndexByIdAndCategoryIndex(const int& id, const int& categoryIndex)
{
	return this->categories[categoryIndex].GetProductIndexById(id);
}

const int& Storage::FindCategoryIndexByName(const std::string& categoryName)
{
	for (int i = 0; i < this->categories.size(); i++)
	{
		if (this->categories[i].GetName() == categoryName)
			return i;
	}

	return -1;
}

const bool Storage::AddCategory(const Category& category)
{
	if (this->AnyCategoryByThisName(category.GetName()))
		return false;

	this->categories.push_back(category);

	return true;
}

const bool Storage::DeleteCategoryByName(const std::string& categoryName)
{

	for (int i = 0; i < categories.size(); i++)
	{
		Category currentCategory = categories[i];

		if (currentCategory.GetName() == categoryName) {
			this->categories.erase(this->categories.begin() + i);
			return true;
		}
	}

	return false;
}

const Product Storage::GetProductByName(const std::string& name) const
{
	for (int i = 0; i < categories.size(); i++)
	{
		Category currentCategory = categories[i];
		for (int j = 0; j < categories[i].GetProductsLength(); j++)
		{
			Product currentProduct = currentCategory.GetProductByIndex(j);
			if (currentProduct.GetName() == name) {
				return currentProduct;
			}
		}
	}

	return Product();
}

const bool Storage::AddProductToCategory(const std::string& categoryName, const Product& product)
{

	for (int i = 0; i < this->categories.size(); i++)
	{
		if (this->categories[i].GetName() == categoryName)
			return this->categories[i].AddProduct(product);
	}

	return false;
}

const bool Storage::DeleteProductByName(const std::string& productName)
{

	for (int i = 0; i < categories.size(); i++)
	{
		Category currentCategory = categories[i];
		for (int j = 0; j < categories[i].GetProductsLength(); j++)
		{
			Product currentProduct = currentCategory.GetProductByIndex(j);
			if (currentProduct.GetName() == productName) {
				currentCategory.DeleteProductByIndex(j);
				return true;
			}
		}
	}

	return false;
}

const bool Storage::IncreaseProductQuantity(const int& productQuantityBy, const std::string& categoryName, const int& productId)
{
	const int categoryIndex = this->FindCategoryIndexByName(categoryName);

	return this->categories[categoryIndex].DecreaseProductQuantityById(productId, productQuantityBy);
}

const bool Storage::DecreaseProductQuantity(const int& decreaseQuantityBy, const std::string& categoryName, const int& productId)
{
	const int categoryIndex = this->FindCategoryIndexByName(categoryName);

	return this->categories[categoryIndex].DecreaseProductQuantityById(productId, decreaseQuantityBy);
}

const bool Storage::AnyCategoryByThisName(const std::string& categoryName) const
{
	for (int i = 0; i < this->categories.size(); i++)
	{
		if (this->categories[i].GetName() == categoryName) {
			return true;
		}
	}

	return false;
}

const bool Storage::AnyProductByThisName(const std::string& productName) const
{
	for (int i = 0; i < this->categories.size(); i++)
	{
		if (this->categories[i].AnyProductByName(productName))
			return true;
	}

	return false;
}

void Storage::PrintAllCategoriesNames()
{
	std::cout << "Categories names: ";
	for (int i = 0; i < this->categories.size(); i++)
	{
		this->categories[i].PrintCategory();
	}
}

void Storage::PrintAllCategoriesProducts()
{
	for (int i = 0; i < this->categories.size(); i++)
	{
		this->categories[i].PrintCategoryProducts();
	}
}

void Storage::PrintAllCategoriesProductsNames()
{
	for (int i = 0; i < this->categories.size(); i++)
	{
		this->categories[i].PrintCategoryProductsNames();
	}
}

