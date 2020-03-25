#pragma once
#include <iostream>
#include "List.h"
#include "ProductCart.h"

class Cart
{
private:
	List<ProductCart> productsInCart;

public:
	bool Add_Product_To_Cart(const ProductCart& product);
	
	bool Delete_Product_From_Cart_By_Index(const int& index);

	bool Delete_Product_From_Cart_By_Name(const String& name);

	double Buy_The_Products();

	double Total_Bill();

	void Show_The_Bill();

	bool Any_Product_By_This_Name(const String& name);

};

