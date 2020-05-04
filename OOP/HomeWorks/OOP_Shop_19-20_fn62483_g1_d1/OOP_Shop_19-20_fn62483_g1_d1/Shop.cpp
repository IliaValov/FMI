#include "Shop.h"

Shop::Shop() {
}

Shop::Shop(const String& name)
{
	this->name = name;
}

Shop::~Shop() {
}

const bool Shop::SetName(const String& name)
{
	//TODO VALIDATION

	this->name = name;

	return true;
}

const String Shop::GetName()const
{
	return this->name;
}

const bool Shop::AddCategory(const Category category)
{
	if (this->AnyCategoryByThisName(category.GetName()) || this->currentUser.AnyRoleByName(ADMIN_ROLE))
		return false;

	return this->storage.AddCategory(category);
}

const bool Shop::DeleteCategoryFromShopByName(const String& categoryName)
{
	if (this->currentUser.AnyRoleByName(ADMIN_ROLE)) {
		return this->storage.DeleteCategoryByName(categoryName);
	}

	return false;
}

const Product Shop::GetProductByName(const String& name)const
{
	return this->storage.GetProductByName(name);
}

const bool Shop::AddProductToCategory(const String& categoryName, const Product& product)
{
	//TODO validation
	if (this->currentUser.AnyRoleByName(ADMIN_ROLE)) {
		return this->storage.AddProductToCategory(categoryName, product);
	}

	return false;
}

const bool Shop::DeleteProductFromShopByName(const String& productName)
{
	if (this->currentUser.AnyRoleByName(ADMIN_ROLE)) {
		this->storage.DeleteProductByName(productName);
	}

	return false;
}

const double Shop::GetUserBillFromCart()const
{
	return this->currentUser.GetUserBill();
}

const double Shop::BuyCurrentUserProducts()
{
	//TODO decrease products quantity
	const List<ProductCart> products = this->currentUser.GetUserProducts();

	for (int i = 0; i < products.GetLength(); i++)
	{
		ProductCart currentProduct = products[i];
		this->storage.DecreaseProductQuantity(currentProduct.GetQuantity(), currentProduct.GetCategoryName(), currentProduct.GetId());
	}

	return this->currentUser.BuyAllUserProductsFromCart();
}

const bool Shop::RegisterUser(const User& user)
{
	return this->users.AddElement(user);
}

const bool Shop::LoginUser(const String& username, const String& password)
{
	for (int i = 0; i < this->users.GetLength(); i++)
	{
		if (this->users[i].IsMatch(username, password))
		{
			this->currentUser = users[i];
			return true;
		}
	}

	return false;
}

const bool Shop::AddProductToUserCart(const Product& product)
{
	return this->currentUser.AddProductToCart(product);
}

const bool Shop::DeleteProductFromUserCartByName(const String& name)
{
	return this->currentUser.DeleteProductFromCartByName(name);
}

void Shop::ListProductsFromUserCart()const
{
	this->currentUser.ShowUserBill();
}

const bool Shop::DeleteProductFromCartByIndex(const int& index)
{
	if (this->currentUser.AnyRoleByName(ADMIN_ROLE))
		return this->currentUser.DeleteProductFromCartByIndex(index);

	return false;
}

const bool Shop::AnyCategoryByThisName(const String& categoryName)const
{
	return this->storage.AnyCategoryByThisName(categoryName);
}

const bool Shop::AnyProductByThisName(const String& productName)const
{
	return this->storage.AnyProductByThisName(productName);
}

const bool Shop::AnyProductInCartByThisName(const String& productName)const
{
	return this->AnyProductInCartByThisName(productName);
}

void Shop::PrintAllCategoriesNames()
{
	this->storage.PrintAllCategoriesNames();
}

void Shop::PrintAllCategoriesProducts()
{
	this->storage.PrintAllCategoriesProducts();
}

void Shop::PrintAllCategoriesProductsNames()
{
	this->storage.PrintAllCategoriesProductsNames();
}



