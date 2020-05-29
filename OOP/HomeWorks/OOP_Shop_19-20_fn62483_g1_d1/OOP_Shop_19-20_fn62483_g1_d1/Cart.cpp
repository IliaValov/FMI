#include "Cart.h"
const std::vector<ProductCart> Cart::GetProducts() const
{
	return productsInCart;
}

const bool Cart::AddProductToCart(const ProductCart& product)
{
	//TODO ADD VALIDATION

	this->productsInCart.push_back(product);

	return true;

}

const bool Cart::DeleteProductFromCartByIndex(const int& index)
{

	this->productsInCart.erase(this->productsInCart.begin() + index);

	return true;

}

const bool Cart::DeleteProductFromCartByName(const std::string& name)
{
	for (int i = 0; i < this->productsInCart.size(); i++)
	{
		ProductCart productCat = this->productsInCart[i];
		if (productCat.GetProductName() == name) {
			this->productsInCart.erase(this->productsInCart.begin() + i);
			return true;
		}
	}

	return false;
}

const double Cart::BuyTheProducts()
{
	double totalBill = this->TotalBill();

	std::cout << "You paid: " << totalBill;

	this->productsInCart.clear();

	return totalBill;
}

const double Cart::TotalBill() const
{
	double totalBill = 0;

	for (int i = 0; i < this->productsInCart.size(); i++)
	{
		ProductCart currentProduct = this->productsInCart[i];

		totalBill += currentProduct.GetPrice() * currentProduct.GetQuantity();
	}

	return totalBill;
}

void Cart::ShowTheBill() const
{
	std::cout << "name | brand | category | price | quantity | total cost";
	for (int i = 0; i < this->productsInCart.size(); i++)
	{
		this->productsInCart[i].PrintProductName();
	}

	std::cout << "Total bill: " << this->TotalBill();
}

const bool Cart::AnyProductByThisName(const std::string& name) const
{
	int length = this->productsInCart.size();

	for (int i = 0; i < length; i++)
	{
		if (this->productsInCart[i].GetProductName() == name)
		{
			return true;
		}
	}

	return false;
}
