#include "Cart.h"

bool Cart::Add_Product_To_Cart(const ProductCart& product)
{
	//TODO ADD VALIDATION

	return this->productsInCart.Add_Element(product);

}

bool Cart::Delete_Product_From_Cart_By_Index(const int& index)
{
	return this->productsInCart.Delete_Element(index);

}

bool Cart::Delete_Product_From_Cart_By_Name(const String& name)
{
	for (int i = 0; i < this->productsInCart.Get_Length(); i++)
	{
		ProductCart productCat = this->productsInCart[i];
		if (productCat.Get_Product_Name() == name) {
			this->productsInCart.Delete_Element(i);
			return true;
		}
	}

	return false;
}

double Cart::Buy_The_Products()
{
	double totalBill = this->Total_Bill();

	std::cout << "You paid: " << totalBill;

	this->productsInCart.Delete_All();

	return totalBill;
}

double Cart::Total_Bill()
{
	double totalBill = 0;

	for (int i = 0; i < this->productsInCart.Get_Length(); i++)
	{
		ProductCart currentProduct = this->productsInCart[i];

		totalBill += currentProduct.Get_Price() * currentProduct.Get_Quantity();
	}

	return totalBill;
}

void Cart::Show_The_Bill()
{
	std::cout << "name | brand | category | price | quantity | total cost";
	for (int i = 0; i < this->productsInCart.Get_Length(); i++)
	{
		this->productsInCart[i].Print_Product_Name();
	}

	std::cout << "Total bill: " << this->Total_Bill();
}

bool Cart::Any_Product_By_This_Name(const String& name)
{
	int length = this->productsInCart.Get_Length();

	for (int i = 0; i < length; i++)
	{
		if (this->productsInCart[i].Get_Product_Name() == name)
		{
			return true;
		}
	}

	return false;
}
