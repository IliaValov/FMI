#pragma once
#include "Category.h"
#include "List.h"
#include "String.h"
#include "Cart.h"

class Shop
{
private:
	String name;

	Cart cart;

	List<Category> categories;

public:
	Shop();
	Shop(const String& name);
	Shop(const Shop& obj);
	~Shop();

	String Get_Name();
	bool Set_Name(const String& name);

	//TODO Const for category
	bool Add_Category(Category category);

	Category* Get_Category_By_Name(const String& name);
	Product Get_Product_By_Name(const String& name);


	const List<Category> Get_All_Categories();

	bool Add_Product_To_Category(const String& categoryName, const Product& product);

	double Get_Bill_From_Cart();
	double Buy_All_Products_From_Cart();

	bool Add_Product_To_Cart(const ProductCart& product);
	bool Delete_Product_From_Cart_By_Name(const String& name);

	void List_Products_From_Cart();



	bool Delete_Product_From_Shop_By_Name(const String& productName);
	bool Delete_Category_From_Shop_By_Name(const String& categoryName);

	bool Delete_Product_From_Cart_By_Index(const int& index);

	bool Any_Category_By_This_Name(const String& categoryName);
	bool Any_Product_By_This_Name(const String& productName);
	bool Any_Product_In_Cart_By_This_Name(const String& productName);

	void Print_All_Categories_Names();
	void Print_All_Categories_Products();
	void Print_All_Categories_Products_Names();
};

