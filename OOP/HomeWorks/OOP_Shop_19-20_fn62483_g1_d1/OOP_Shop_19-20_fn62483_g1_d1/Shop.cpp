#include "Shop.h"
Shop::Shop() {
}

Shop::Shop(const String& name)
{
	this->name = name;
}

Shop::Shop(const Shop& obj)
{
	this->name = obj.name;

	this->categories = obj.categories;
}

Shop::~Shop() {
}

bool Shop::Set_Name(const String& name)
{
	//TODO VALIDATION

	this->name = name;

	return true;
}

bool Shop::Add_Category(Category category)
{
	if (this->Any_Category_By_This_Name(category.Get_Name()))
		return false;

	this->categories.Add_Element(category);

	return true;
}

String Shop::Get_Name()
{
	return this->name;
}

Category* Shop::Get_Category_By_Name(const String& name)
{
	for (int i = 0; i < this->categories.Get_Length(); i++)
	{
		if (this->categories[i].Get_Name() == name) {
			return &this->categories[i];
		}
	}

	return &Category();
}

Product Shop::Get_Product_By_Name(const String& name)
{
	for (int i = 0; i < categories.Get_Length(); i++)
	{
		Category currentCategory = categories.Get_Element(i);
		for (int j = 0; j < categories[i].Get_Products_Length(); j++)
		{
			Product currentProduct = currentCategory.Get_Product_By_Index(j);
			if (currentProduct.Get_Name() == name) {
				return currentProduct;
			}
		}
	}

	return Product();
}

const List<Category> Shop::Get_All_Categories()
{
	return this->categories;
}

bool Shop::Add_Product_To_Category(const String& categoryName, const Product& product)
{
	//TODO validation

	Category* category = this->Get_Category_By_Name(categoryName);

	category->Add_Product(product);

	return true;
}

double Shop::Get_Bill_From_Cart()
{
	return this->cart.Total_Bill();
}

double Shop::Buy_All_Products_From_Cart()
{
	return this->cart.Buy_The_Products();
}

bool Shop::Add_Product_To_Cart(const ProductCart& product)
{
	return this->cart.Add_Product_To_Cart(product);
}

bool Shop::Delete_Product_From_Cart_By_Name(const String& name)
{
	return this->cart.Delete_Product_From_Cart_By_Name(name);
}

void Shop::List_Products_From_Cart()
{
	this->cart.Show_The_Bill();
}

bool Shop::Delete_Product_From_Shop_By_Name(const String& productName)
{

	for (int i = 0; i < categories.Get_Length(); i++)
	{
		Category currentCategory = categories.Get_Element(i);
		for (int j = 0; j < categories[i].Get_Products_Length(); j++)
		{
			Product currentProduct = currentCategory.Get_Product_By_Index(j);
			if (currentProduct.Get_Name() == productName) {
				currentCategory.Delete_Product_By_Index(j);
				return true;
			}
		}
	}

	return false;
}

bool Shop::Delete_Category_From_Shop_By_Name(const String& categoryName)
{
	for (int i = 0; i < categories.Get_Length(); i++)
	{
		Category currentCategory = categories.Get_Element(i);
		
		if (currentCategory.Get_Name() == categoryName) {
			this->categories.Delete_Element(i);
			return true;
		}
	}

	return false;
}

bool Shop::Delete_Product_From_Cart_By_Index(const int& index)
{
	return this->cart.Delete_Product_From_Cart_By_Index(index);
}

bool Shop::Any_Category_By_This_Name(const String& categoryName)
{
	for (int i = 0; i < this->categories.Get_Length(); i++)
	{
		if (this->categories.Get_Element(i).Get_Name() == categoryName) {
			return true;
		}
	}

	return false;
}

bool Shop::Any_Product_By_This_Name(const String& productName)
{
	for (int i = 0; i < this->categories.Get_Length(); i++)
	{
		if (this->categories[i].Any_Product_By_Name(productName))
			return true;
	}

	return false;
}

bool Shop::Any_Product_In_Cart_By_This_Name(const String& productName)
{
	return this->Any_Product_In_Cart_By_This_Name(productName);
}

void Shop::Print_All_Categories_Names()
{
	std::cout << "Categories names: ";
	for (int i = 0; i < this->categories.Get_Length(); i++)
	{
		this->categories[i].Print_Category();
	}
}

void Shop::Print_All_Categories_Products()
{
	for (int i = 0; i < this->categories.Get_Length(); i++)
	{
		this->categories[i].Print_Category_Products();
	}
}

void Shop::Print_All_Categories_Products_Names()
{
	for (int i = 0; i < this->categories.Get_Length(); i++)
	{
		this->categories[i].Print_Category_Products_Names();
	}
}



