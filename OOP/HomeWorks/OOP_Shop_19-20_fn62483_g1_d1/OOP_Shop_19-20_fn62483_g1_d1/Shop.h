#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "Constants.h"
#include "Category.h"
#include "Storage.h"
#include "Cart.h"
#include "User.h"

class Shop
{
private:
	std::string name;

	Storage storage;

	User currentUser;

	bool isUserLogged;


	std::vector<User> users;

public:
	Shop();

	const std::string GetName() const;
	const bool SetName(const std::string& name);

	const bool AddCategory(const Category category);
	const bool DeleteCategoryFromShopByName(const std::string& categoryName);

	const Product GetProductByName(const std::string& name) const;

	const bool AddProductToCategory(const std::string& categoryName, const Product& product);
	const bool DeleteProductFromShopByName(const std::string& productName);

	const double GetUserBillFromCart() const;
	const double BuyCurrentUserProducts();

	const bool RegisterUser(const User& user);

	const bool LoginUser(const std::string& username, const std::string& password);

	const bool AddProductToUserCart(const Product& product);
	const bool DeleteProductFromUserCartByName(const std::string& name);

	const bool DeleteProductFromCartByIndex(const int& index);

	const bool AnyCategoryByThisName(const std::string& categoryName) const;
	const bool AnyProductByThisName(const std::string& productName) const;
	const bool AnyProductInCartByThisName(const std::string& productName) const;

	void Logout();

	void ListProductsFromUserCart() const;

	void PrintAllCategoriesNames();
	void PrintAllCategoriesProducts();
	void PrintAllCategoriesProductsNames();
};

