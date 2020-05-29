#include "Shop.h"

Shop::Shop() : isUserLogged(false)
{
}

const bool Shop::SetName(const std::string& name)
{
	//TODO VALIDATION

	this->name = name;

	return true;
}

const std::string Shop::GetName()const
{
	return this->name;
}

const bool Shop::AddCategory(const Category category)
{
	if (this->AnyCategoryByThisName(category.GetName()) || this->currentUser.AnyRoleByName(ADMIN_ROLE))
		return false;

	return this->storage.AddCategory(category);
}

const bool Shop::DeleteCategoryFromShopByName(const std::string& categoryName)
{
	if (this->currentUser.AnyRoleByName(ADMIN_ROLE)) {
		return this->storage.DeleteCategoryByName(categoryName);
	}

	return false;
}

const Product Shop::GetProductByName(const std::string& name)const
{
	return this->storage.GetProductByName(name);
}

const bool Shop::AddProductToCategory(const std::string& categoryName, const Product& product)
{
	//TODO validation
	if (this->currentUser.AnyRoleByName(ADMIN_ROLE)) {
		return this->storage.AddProductToCategory(categoryName, product);
	}

	return false;
}

const bool Shop::DeleteProductFromShopByName(const std::string& productName)
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
	if (isUserLogged) {
		const std::vector<ProductCart> products = this->currentUser.GetUserProducts();

		for (int i = 0; i < products.size(); i++)
		{
			ProductCart currentProduct = products[i];
			this->storage.DecreaseProductQuantity(currentProduct.GetQuantity(), currentProduct.GetCategoryName(), currentProduct.GetId());
		}

		return this->currentUser.BuyAllUserProductsFromCart();
	}

	return -1;
}

const bool Shop::RegisterUser(const User& user)
{
	 this->users.push_back(user);

	 return true;
}

const bool Shop::LoginUser(const std::string& username, const std::string& password)
{
	for (int i = 0; i < this->users.size(); i++)
	{
		if (this->users[i].IsMatch(username, password))
		{
			this->currentUser = users[i];
			isUserLogged = true;
			return true;
		}
	}

	return false;
}

const bool Shop::AddProductToUserCart(const Product& product)
{
	return this->currentUser.AddProductToCart(product);
}

const bool Shop::DeleteProductFromUserCartByName(const std::string& name)
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

const bool Shop::AnyCategoryByThisName(const std::string& categoryName)const
{
	return this->storage.AnyCategoryByThisName(categoryName);
}

const bool Shop::AnyProductByThisName(const std::string& productName)const
{
	return this->storage.AnyProductByThisName(productName);
}

const bool Shop::AnyProductInCartByThisName(const std::string& productName)const
{
	return this->AnyProductInCartByThisName(productName);
}

void Shop::Logout()
{
	isUserLogged = false;
	this->currentUser = User();
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



