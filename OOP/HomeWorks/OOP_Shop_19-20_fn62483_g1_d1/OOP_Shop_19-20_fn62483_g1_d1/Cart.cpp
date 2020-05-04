#include "Cart.h"
const List<ProductCart> Cart::GetProducts() const
{
	return productsInCart;
}

const bool Cart::AddProductToCart(const ProductCart& product)
{
	//TODO ADD VALIDATION

	return this->productsInCart.AddElement(product);

}

const bool Cart::DeleteProductFromCartByIndex(const int& index)
{
	return this->productsInCart.DeleteElement(index);

}

const bool Cart::DeleteProductFromCartByName(const String& name)
{
	for (int i = 0; i < this->productsInCart.GetLength(); i++)
	{
		ProductCart productCat = this->productsInCart[i];
		if (productCat.GetProductName() == name) {
			this->productsInCart.DeleteElement(i);
			return true;
		}
	}

	return false;
}

const double Cart::BuyTheProducts()
{
	double totalBill = this->TotalBill();

	std::cout << "You paid: " << totalBill;

	this->productsInCart.DeleteAll();

	return totalBill;
}

const double Cart::TotalBill() const
{
	double totalBill = 0;

	for (int i = 0; i < this->productsInCart.GetLength(); i++)
	{
		ProductCart currentProduct = this->productsInCart[i];

		totalBill += currentProduct.GetPrice() * currentProduct.GetQuantity();
	}

	return totalBill;
}

void Cart::ShowTheBill() const
{
	std::cout << "name | brand | category | price | quantity | total cost";
	for (int i = 0; i < this->productsInCart.GetLength(); i++)
	{
		this->productsInCart[i].PrintProductName();
	}

	std::cout << "Total bill: " << this->TotalBill();
}

const bool Cart::AnyProductByThisName(const String& name) const
{
	int length = this->productsInCart.GetLength();

	for (int i = 0; i < length; i++)
	{
		if (this->productsInCart[i].GetProductName() == name)
		{
			return true;
		}
	}

	return false;
}
