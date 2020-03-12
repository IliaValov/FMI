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

	virtual ~Category();

	virtual void Set_Name(const String name);
	virtual String Get_Name();

	virtual bool Add_Product(Product product);
	virtual Product Get_Product_By_Index(int index);
	virtual Product Get_Product_By_Name(String name);
	virtual const List<Product> Get_Product_All_Products();

	virtual bool Any_Product_By_Name(String name);
};



