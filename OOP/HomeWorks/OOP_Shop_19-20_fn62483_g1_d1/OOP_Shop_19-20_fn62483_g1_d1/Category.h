#pragma once
#include "String.h"
#include "Product.h"
#include "List.h"
class Category
{
private:
	String name;

	List<Product> products;


public:
	Category();
	Category(const String& name);
	~Category();

	const String GetName() const;
	const bool SetName(const String& name);
	
	const int GetProductsLength();

	const bool AddProduct(const Product& product);

	const Product GetProductByIndex(const int& index);
	const Product GetProductByName(const String& name);

	const List<Product> GetAllProducts();

	const bool AnyProductByName(const String& name);

	const bool DeleteProductByIndex(const int& index);

	const bool DecreaseProductQuantity(int productId, int quantity);

	void PrintCategory();
	void PrintCategoryProducts();
	void PrintCategoryProductsNames();
};



