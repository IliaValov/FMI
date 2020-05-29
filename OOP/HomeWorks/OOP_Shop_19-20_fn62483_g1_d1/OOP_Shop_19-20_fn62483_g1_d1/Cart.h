#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "ProductCart.h"

class Cart
{
private:
	std::vector<ProductCart> productsInCart;

public:
	const std::vector<ProductCart> GetProducts() const;

	const bool AddProductToCart(const ProductCart& product);
	
	const bool DeleteProductFromCartByIndex(const int& index);

	const bool DeleteProductFromCartByName(const std::string& name);

	const double BuyTheProducts();

	const double TotalBill() const;

	void ShowTheBill() const;

	const bool AnyProductByThisName(const std::string& name) const;

};

