#pragma once
#include <iostream>
#include "List.h"
#include "ProductCart.h"

class Cart
{
private:
	List<ProductCart> productsInCart;

public:
	const List<ProductCart> GetProducts() const;

	const bool AddProductToCart(const ProductCart& product);
	
	const bool DeleteProductFromCartByIndex(const int& index);

	const bool DeleteProductFromCartByName(const String& name);

	const double BuyTheProducts();

	const double TotalBill() const;

	void ShowTheBill() const;

	const bool AnyProductByThisName(const String& name) const;

};

