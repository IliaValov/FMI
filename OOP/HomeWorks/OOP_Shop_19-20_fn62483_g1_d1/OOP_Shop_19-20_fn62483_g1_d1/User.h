#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "Cart.h"
#include "Product.h"
#include "ProductCart.h"
#include "Account.h"

class User
{
private:
	std::string username;
	std::string password;

	Account account;

	Cart cart;

	std::vector<std::string> roles;
public:
	User();
	User(const std::string& username, const std::string& password);
	~User();

	const std::string& GetUsername() const;

	const std::vector<ProductCart> GetUserProducts() const;

	const bool RegisterUser(const std::string& userName, const std::string& password);

	const bool AddProductToCart(const Product& product);

	const bool DeleteProductFromCartByName(const std::string& name);
	const bool DeleteProductFromCartByIndex(const int& index);

	const bool AnyRoleByName(const std::string& name) const;

	const double GetUserBill() const;

	const double BuyAllUserProductsFromCart();

	const bool IsMatch(const std::string& username, const std::string& password) const;

	void ShowUserBill() const;

	const bool operator==(const User& user) const;
};

