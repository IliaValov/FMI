#pragma once
#include "Constants.h"
#include "Category.h"
#include "Storage.h"
#include "String.h"
#include "List.h"
#include "Cart.h"
#include "User.h"

class Shop
{
private:
	String name;

	Storage storage;

	User currentUser;

	List<User> users;

public:
	Shop();
	Shop(const String& name);
	~Shop();

	const String GetName() const;
	const bool SetName(const String& name);

	const bool AddCategory(const Category category);
	const bool DeleteCategoryFromShopByName(const String& categoryName);

	const Product GetProductByName(const String& name) const;

	const bool AddProductToCategory(const String& categoryName, const Product& product);
	const bool DeleteProductFromShopByName(const String& productName);

	const double GetUserBillFromCart() const;
	const double BuyCurrentUserProducts();

	const bool RegisterUser(const User& user);

	const bool LoginUser(const String& username, const String& password);

	const bool AddProductToUserCart(const Product& product);
	const bool DeleteProductFromUserCartByName(const String& name);

	const bool DeleteProductFromCartByIndex(const int& index);

	const bool AnyCategoryByThisName(const String& categoryName) const;
	const bool AnyProductByThisName(const String& productName) const;
	const bool AnyProductInCartByThisName(const String& productName) const;

	void ListProductsFromUserCart() const;

	void PrintAllCategoriesNames();
	void PrintAllCategoriesProducts();
	void PrintAllCategoriesProductsNames();
};

