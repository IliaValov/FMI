#pragma once
#include "Category.h"
#include "List.h"
#include "String.h"
#include "Cart.h"
#include "User.h"

class Shop
{
private:
	String name;

	List<User> users;

	//This field in next patch will be moved in class storage
	List<Category> categories;

	User currentUser;

	const String ADMIN_ROLE = "Admin";

	const bool DecreaseProductQuantity(int productId, int quantity);

public:
	Shop();
	Shop(const String& name);
	~Shop();

	const String GetName() const;
	const bool SetName(const String& name);

	//TODO Const for category
	const bool AddCategory(Category category);

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

	void ListProductsFromUserCart() const;

	const bool DeleteProductFromCartByIndex(const int& index);

	const bool AnyCategoryByThisName(const String& categoryName) const;
	const bool AnyProductByThisName(const String& productName) const;
	const bool AnyProductInCartByThisName(const String& productName) const;

	void PrintAllCategoriesNames();
	void PrintAllCategoriesProducts();
	void PrintAllCategoriesProductsNames();
};

