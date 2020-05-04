#include "User.h"

User::User()
{
	this->username = "";
	this->password = "";
}

User::User(const String& username, const String& password)
{
	this->username = username;
	this->password = password;
}

User::~User()
{
}

const String& User::GetUsername() const
{
	return this->username;
}

const List<ProductCart> User::GetUserProducts() const
{
	return this->cart.GetProducts();
}

const bool User::RegisterUser(const String& username, const String& password)
{
	this->username = username;
	this->password = password;

	return true;
}

const bool User::AddProductToCart(const Product& product)
{
	return this->cart.AddProductToCart(product);
}

const bool User::DeleteProductFromCartByName(const String& name)
{
	return this->cart.DeleteProductFromCartByName(name);
}

const bool User::DeleteProductFromCartByIndex(const int& index)
{
	return this->cart.DeleteProductFromCartByIndex(index);
}

const bool User::AnyRoleByName(const String& name) const
{
	for (int i = 0; i < this->roles.GetLength(); i++)
	{
		if (this->roles[i] == name) {
			return true;
		}
	}

	return false;
}

const double User::GetUserBill() const
{
	return this->cart.TotalBill();
}

const double User::BuyAllUserProductsFromCart()
{
	return this->cart.BuyTheProducts();
}

const bool User::IsMatch(const String& username, const String& password) const
{
	if (this->username == username && this->password == password)
		return true;
	return false;
}

void User::ShowUserBill() const
{
	this->cart.ShowTheBill();
}

const bool User::operator==(const User& user) const
{
	if (this->username == user.username && this->password == user.password) {
		return true;
	}

	return false;
}
