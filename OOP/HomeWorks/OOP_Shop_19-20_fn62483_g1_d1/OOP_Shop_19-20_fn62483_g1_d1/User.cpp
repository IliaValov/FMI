#include "User.h"

User::User()
{
	this->username = "";
	this->password = "";
}

User::User(const std::string& username, const std::string& password)
{
	this->username = username;
	this->password = password;
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return this->username;
}

const std::vector<ProductCart> User::GetUserProducts() const
{
	return this->cart.GetProducts();
}

const bool User::RegisterUser(const std::string& username, const std::string& password)
{
	this->username = username;
	this->password = password;

	return true;
}

const bool User::AddProductToCart(const Product& product)
{
	return this->cart.AddProductToCart(product);
}

const bool User::DeleteProductFromCartByName(const std::string& name)
{
	return this->cart.DeleteProductFromCartByName(name);
}

const bool User::DeleteProductFromCartByIndex(const int& index)
{
	return this->cart.DeleteProductFromCartByIndex(index);
}

const bool User::AnyRoleByName(const std::string& name) const
{
	for (int i = 0; i < this->roles.size(); i++)
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
	if (this->account.Substract(this->cart.TotalBill()))
	{

		return this->cart.BuyTheProducts();
	}

	return -1;
}

const bool User::IsMatch(const std::string& username, const std::string& password) const
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
