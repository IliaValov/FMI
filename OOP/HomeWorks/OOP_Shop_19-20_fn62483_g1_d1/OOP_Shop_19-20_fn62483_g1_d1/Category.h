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
	Category(const Category& obj);
	Category(const String& name);
	~Category();

	String Get_Name();
	void Set_Name(const String& name);
	
	int Get_Length();
	int Get_Products_Length();

	bool Add_Product(const Product& product);

	Product Get_Product_By_Index(const int& index);
	Product Get_Product_By_Name(const String& name);

	const List<Product> Get_All_Products();

	bool Any_Product_By_Name(const String& name);

	bool Delete_Product_By_Index(const int& index);

	void Print_Category();
	void Print_Category_Products();
	void Print_Category_Products_Names();

	Category operator =(const Category& obj);
};



