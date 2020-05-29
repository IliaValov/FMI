#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "Category.h"

class Storage
{
private:
	std::vector<Category> categories;
	
	const int& FindProductIndexByIdAndCategoryIndex(const int& id, const int& categoryIndex);

	const int& FindCategoryIndexByName(const std::string& categoryName);
public:

	const bool AddCategory(const Category& category);
	const bool DeleteCategoryByName(const std::string& categoryName);

	const Product GetProductByName(const std::string& name) const ;

	const bool AddProductToCategory(const std::string& categoryName, const Product& product);
	const bool DeleteProductByName(const std::string& productName);

	const bool IncreaseProductQuantity(const int& productQuantityBy, const std::string& categoryName, const int& productId);
	const bool DecreaseProductQuantity(const int& decreaseQuantityBy, const std::string& categoryName, const int& productId);

	const bool AnyCategoryByThisName(const std::string& categoryName) const;
	const bool AnyProductByThisName(const std::string& productName) const;

	void PrintAllCategoriesNames();
	void PrintAllCategoriesProducts();
	void PrintAllCategoriesProductsNames();

};

