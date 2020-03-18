#pragma once
#include <iostream>
#include "List.h"
#include "ProductCart.h"

class Cart
{
private:
	List<ProductCart> productsInCart;

public:
	bool Add_Product_To_Cart(ProductCart product);

	bool Delete_Product_From_Cart_By_Index(int index);

	bool Delete_Product_From_Cart_By_Name(String name);

	int Buy_The_Products();

	double Total_Bill();

	void Show_The_Bill();

	bool Any_Product_By_This_Name(String name);

};

