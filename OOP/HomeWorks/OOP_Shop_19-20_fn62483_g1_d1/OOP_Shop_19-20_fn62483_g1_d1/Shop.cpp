//#include "Shop.h"
//
//bool Shop::Set_Name(char* name)
//{
//	this->name = name;
//
//	return true;
//}
//
//String Shop::Get_Name()
//{
//	return this->name;
//}
//
//Product Shop::Get_Product_By_Index(int i)
//{
//	if (i >= this->products.Get_Length())
//		return Product();
//
//	return Product();
//}
//
//Product Shop::Get_Product_By_Name(char* name)
//{
//	if (this->Any_Product_By_Name(name))
//		return Product();
//}
//
//bool Shop::Add_Product(Product product)
//{/*
//	this->products.Add_Element(product);*/
//
//	return true;
//}
//
//bool Shop::Any_Product_By_Name(char* name)
//{
//	/*int productsLength = this->length;
//	int nameLength = strlen(name);
//
//	for (int i = 0; i < productsLength; i++)
//	{
//		Product currentProduct = this->products[i];
//		char* currentProductName = currentProduct.Get_Name();
//		int currentNameLength = strlen(currentProduct.Get_Name());
//
//
//		if (currentNameLength != nameLength) {
//			continue;
//		}
//
//		bool isEquals = true;
//		for (int i = 0; i < nameLength; i++)
//		{
//			if (name[i] != currentProductName[i]) {
//				isEquals = false;
//				break;
//			}
//		}
//
//		if (isEquals) {
//			return isEquals;
//		}
//	}*/
//
//	return false;
//}
//
//Shop::Shop() {
//}
//
//Shop::~Shop() {
//}