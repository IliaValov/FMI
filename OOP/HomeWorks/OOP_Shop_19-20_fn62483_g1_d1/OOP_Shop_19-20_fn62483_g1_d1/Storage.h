#pragma once
#include "Category.h"
#include "String.h"
#include "List.h"

class Storage
{
private:
	List<Category> categories;

	const int& FindProductIndexByIdAndCategoryIndex(const int& id, const int& categoryIndex);

	const int& FindCategoryIndexByName(const String& categoryName);
public:

	const bool AddCategory(const Category& category);
	const bool DeleteCategoryByName(const String& categoryName);

	const Product GetProductByName(const String& name) const;

	const bool AddProductToCategory(const String& categoryName, const Product& product);
	const bool DeleteProductByName(const String& productName);

	const bool IncreaseProductQuantity(const int& productQuantityBy, const String& categoryName, const int& productId);
	const bool DecreaseProductQuantity(const int& decreaseQuantityBy, const String& categoryName, const int& productId);

	const bool AnyCategoryByThisName(const String& categoryName) const;
	const bool AnyProductByThisName(const String& productName) const;

	void PrintAllCategoriesNames();
	void PrintAllCategoriesProducts();
	void PrintAllCategoriesProductsNames();

};

