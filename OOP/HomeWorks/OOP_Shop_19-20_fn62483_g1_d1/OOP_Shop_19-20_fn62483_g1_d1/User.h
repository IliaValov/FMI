#pragma once
#include"String.h"
#include "Cart.h"
#include "Product.h"
#include "ProductCart.h"

class User
{
private:
	String username;
	String password;

	Cart cart;

	List<String> roles;
public:
	User();
	User(const String& username, const String& password);
	~User();

	const String& GetUsername() const;

	const bool RegisterUser(const String& userName, const String& password);

	const bool AddProductToCart(const Product& product);

	const bool DeleteProductFromCartByName(const String& name);
	const bool DeleteProductFromCartByIndex(const int& index);

	const bool AnyRoleByName(const String& name) const;

	const double GetUserBill() const;

	const double BuyAllUserProductsFromCart();

	const bool IsMatch(const String& username, const String& password) const;

	void ShowUserBill() const;

	const bool operator==(const User& user) const;
};

