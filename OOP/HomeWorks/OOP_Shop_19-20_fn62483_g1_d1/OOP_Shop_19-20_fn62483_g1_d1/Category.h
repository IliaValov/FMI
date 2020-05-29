#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "Product.h"

class Category
{
private:
	std::string name;


	std::vector<Product*> products;

public:
	Category();
	Category(const std::string& name);
	~Category();

	const std::string GetName() const;
	const bool SetName(const std::string& name);

	const int GetProductsLength() const;

	const bool AddProduct(const Product& product);

	const int GetProductIndexById(const int& id);
	const Product GetProductByIndex(const int& index);
	const Product GetProductByName(const std::string& name);

	const std::vector<Product*> GetAllProducts();

	const bool AnyProductByName(const std::string& name) const;

	const bool DeleteProductByIndex(const int& index);

	const bool IncreaseProductQuantityById(const int& productId, const int& quantity);
	const bool IncreaseProductQuantityByIndex(const int& index, const int& quantity);

	const bool DecreaseProductQuantityById(const int& productId, const int& quantity);
	const bool DecreaseProductQuantityByIndex(const int& index, const int& quantity);

	void PrintCategory();
	void PrintCategoryProducts();
	void PrintCategoryProductsNames();
};



