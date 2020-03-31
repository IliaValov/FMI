#include "Shop.h"
const bool Shop::DecreaseProductQuantity(int productId, int quantity)
{
	for (int i = 0; i < this->categories.GetLength(); i++)
	{
		if (this->categories[i].DecreaseProductQuantity(productId, quantity))
			return true;
	}

	return false;
}

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

const bool Shop::AddCategory(Category category)
{
	if (this->AnyCategoryByThisName(category.GetName()) || this->currentUser.AnyRoleByName(this->ADMIN_ROLE))
		return false;

	return this->categories.AddElement(category);
}

const String Shop::GetName()const
{
	return this->name;
}

const Product Shop::GetProductByName(const String& name)const
{
	for (int i = 0; i < categories.GetLength(); i++)
	{
		Category currentCategory = categories.GetElement(i);
		for (int j = 0; j < categories[i].GetProductsLength(); j++)
		{
			Product currentProduct = currentCategory.GetProductByIndex(j);
			if (currentProduct.GetName() == name) {
				return currentProduct;
			}
		}
	}

	return Product();
}

const bool Shop::AddProductToCategory(const String& categoryName, const Product& product)
{
	//TODO validation
	if (this->currentUser.AnyRoleByName(this->ADMIN_ROLE)) {
		for (int i = 0; i < this->categories.GetLength(); i++)
		{
			if (this->categories[i].GetName() == categoryName)
				return this->categories[i].AddProduct(product);
		}
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

const bool Shop::DeleteProductFromShopByName(const String& productName)
{
	if (this->currentUser.AnyRoleByName(this->ADMIN_ROLE)) {
		for (int i = 0; i < categories.GetLength(); i++)
		{
			Category currentCategory = categories.GetElement(i);
			for (int j = 0; j < categories[i].GetProductsLength(); j++)
			{
				Product currentProduct = currentCategory.GetProductByIndex(j);
				if (currentProduct.GetName() == productName) {
					currentCategory.DeleteProductByIndex(j);
					return true;
				}
			}
		}

	}
	return false;
}

const bool Shop::DeleteCategoryFromShopByName(const String& categoryName)
{
	if (this->currentUser.AnyRoleByName(this->ADMIN_ROLE)) {
		for (int i = 0; i < categories.GetLength(); i++)
		{
			Category currentCategory = categories.GetElement(i);

			if (currentCategory.GetName() == categoryName) {
				this->categories.DeleteElement(i);
				return true;
			}
		}
	}

	return false;
}

const bool Shop::DeleteProductFromCartByIndex(const int& index)
{
	if (this->currentUser.AnyRoleByName(this->ADMIN_ROLE))
		return this->currentUser.DeleteProductFromCartByIndex(index);

	return false;
}

const bool Shop::AnyCategoryByThisName(const String& categoryName)const
{
	for (int i = 0; i < this->categories.GetLength(); i++)
	{
		if (this->categories.GetElement(i).GetName() == categoryName) {
			return true;
		}
	}

	return false;
}

const bool Shop::AnyProductByThisName(const String& productName)const
{
	for (int i = 0; i < this->categories.GetLength(); i++)
	{
		if (this->categories[i].AnyProductByName(productName))
			return true;
	}

	return false;
}

const bool Shop::AnyProductInCartByThisName(const String& productName)const
{
	return this->AnyProductInCartByThisName(productName);
}

void Shop::PrintAllCategoriesNames()
{
	std::cout << "Categories names: ";
	for (int i = 0; i < this->categories.GetLength(); i++)
	{
		this->categories[i].PrintCategory();
	}
}

void Shop::PrintAllCategoriesProducts()
{
	for (int i = 0; i < this->categories.GetLength(); i++)
	{
		this->categories[i].PrintCategoryProducts();
	}
}

void Shop::PrintAllCategoriesProductsNames()
{
	for (int i = 0; i < this->categories.GetLength(); i++)
	{
		this->categories[i].PrintCategoryProductsNames();
	}
}



