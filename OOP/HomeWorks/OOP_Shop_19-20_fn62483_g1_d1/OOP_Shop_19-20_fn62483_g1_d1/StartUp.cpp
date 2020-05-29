#include <iostream> 
#include "List.h"
#include "String.h"

#include "Shop.h"
#include "Category.h"

#include "User.h"

using namespace std;

void AdministrationPanel(Shop* shop);
void AdministrationPanelAddCategory(Shop* shop);
void AdministrationPanelAddProductToCategory(Shop* shop);
void AdministrationPanelDeleteProductByName(Shop* shop);
void AdministrationPanelDeleteCategoryByName(Shop* shop);

void UserPanel(Shop* shop);
void UserPanelAddProductToCart(Shop* shop);
void UserPanelDeleteProductFromCart(Shop* shop);
void UserPanelListTheProductsFromTheCart(Shop* shop);
void UserPanelBuyEverything(Shop* shop);

int Product::counterId = 0;


int main() {

	//TODO this is not working properly and will be moved in class maybe in next patch :D
	Shop shop;

	std::string shopName;

	cout << "Enter name for the shop \r\n";

	cin >> shopName;

	shop.SetName(shopName);

	char command = '\0';

	while (true) {
		cout << "A: For entering administration panel\r\n";
		cout << "U: For entering user panel\r\n";
		cout << "E: For exiting\r\n";
		cout << "Enter command: ";

		cin >> command;

		switch (command) {
		case 'A':
			AdministrationPanel(&shop);
			break;
		case 'U':
			UserPanel(&shop);
			break;
		case'E':
			return 0;
		default:
			cout << "Invalid command!";
		}
	}

	return 0;
}

void AdministrationPanel(Shop* shop) {
	system("cls");
	char command = '\0';
	while (true) {
		system("cls");
		cout << "P: For adding product \r\n";
		cout << "C: For adding category \r\n";
		cout << "F: For deleting category \r\n";
		cout << "G: For deleting product \r\n";
		cout << "E: For exiting \r\n";

		cout << "Enter command: ";

		cin >> command;

		switch (command) {
		case 'P':
			AdministrationPanelAddProductToCategory(shop);
			break;
		case'C':
			AdministrationPanelAddCategory(shop);
			break;
		case'F':
			AdministrationPanelDeleteCategoryByName(shop);
			break;
		case'G':
			AdministrationPanelDeleteProductByName(shop);
			break;
		case'E':
			return;
			break;
		default:
			cout << "Invalid command";
		}
	}
}

void AdministrationPanelAddCategory(Shop* shop) {
	Category category;
	std::string name;

	cout << "Enter name for the category: \r\n";

	cin.ignore();
	cin >> name;

	category.SetName(name);

	shop->AddCategory(category);

	cout << "Category " << name << " is added\r\n";

	system("pause");
}

void AdministrationPanelAddProductToCategory(Shop* shop) {
	std::string categoryName;

	std::string productName;
	std::string productBrand;
	std::string productDescription;

	double price = 0;
	int quantity = 0;
	double discountInPercentiges;
	while (true) {
		system("cls");
		cout << "Creating product: \r\n";

		shop->PrintAllCategoriesNames();

		cout << "Type the name of one of the categories from above: ";

		cin >> categoryName;

		cin.clear();
		cin.sync();

		if (shop->AnyCategoryByThisName(categoryName))
			break;

		categoryName = "";
		cout << "Invalid name!";
	}

	while (true) {
		system("cls");
		cout << "Creating product for category " << categoryName << ": \r\n";

		cout << "Enter product name: ";
		cin >> productName;
		cout << "Enter product brand: ";
		cin >> productBrand;
		cout << "Enter product description: ";
		cin >> productDescription;

		cout << "Enter product price: ";
		cin >> price;
		cout << "Enter product quantity: ";
		cin >> quantity;
		cout << "Enter product discount in percentiges: ";
		cin >> discountInPercentiges;

		return;
	}

	Product product(productName, productBrand, productDescription, price, quantity, discountInPercentiges);

	shop->AddProductToCategory(categoryName, product);
}

void AdministrationPanelDeleteProductByName(Shop* shop) {

	std::string productName;

	while (true) {
		system("cls");
		shop->PrintAllCategoriesProductsNames();

		cout << "Choose one of the products from above to be deleted: ";

		cin.ignore();
		cin >> productName;

		if (shop->AnyProductByThisName(productName))
			break;

		productName = "";

		cout << "Invalid name!";
		system("pause");
	}

	shop->DeleteProductFromShopByName(productName);
	cout << "Deleted Product";
	system("pause");
}


void AdministrationPanelDeleteCategoryByName(Shop* shop) {

	std::string categoryName;

	while (true) {
		system("cls");
		shop->PrintAllCategoriesNames();

		cout << "Choose one of the products from above to be deleted: ";

		cin.ignore();
		cin >> categoryName;

		if (shop->AnyCategoryByThisName(categoryName))
			break;

		categoryName = "";
		cout << "Invalid name!";
		system("pause");
	}

	shop->DeleteCategoryFromShopByName(categoryName);
	cout << "Deleted category";
	system("pause");
}

void UserPanel(Shop* shop) {
	system("cls");
	while (true) {
		char command = '\0';
		while (true) {
			system("cls");
			cout << "P: For adding product to cart\r\n";
			cout << "D: For deleting product from cart\r\n";
			cout << "L: To show the bill\r\n";
			cout << "B: To buy everything from the cart\r\n";
			cout << "E: For exiting\r\n";
			cout << "Enter command: ";

			cin >> command;

			switch (command) {
			case 'P':
				UserPanelAddProductToCart(shop);
				break;
			case'D':
				UserPanelDeleteProductFromCart(shop);
				break;
			case'L':
				UserPanelListTheProductsFromTheCart(shop);
				break;
			case'B':
				UserPanelBuyEverything(shop);
				break;
			case'E':
				return;
				break;
			default:
				cout << "Invalid command";
			}
		}
	}
}

void UserPanelAddProductToCart(Shop* shop) {
	std::string productName;

	while (true) {
		shop->PrintAllCategoriesProducts();
		cout << "Type the name of the product you want: ";

		cin.ignore();
		cin >> productName;

		if (shop->AnyProductByThisName(productName))
			break;

		productName = "";
		cout << "Invalid name!";
	}

	Product chosedProduct = shop->GetProductByName(productName);

	shop->AddProductToUserCart(chosedProduct);
	cout << "Added product to cart";
	system("pause");
}

void UserPanelDeleteProductFromCart(Shop* shop) {
	std::string productName;

	while (true) {
		system("cls");
		shop->PrintAllCategoriesNames();

		cout << "Choose one of the products from above to be deleted: ";

		cin.ignore();
		cin >> productName;

		if (shop->AnyProductInCartByThisName(productName))
			break;

		productName = "";
		cout << "Invalid name!";
		system("pause");
	}

	shop->DeleteProductFromUserCartByName(productName);
	cout << "Product is deleted";
	system("pause");
}

void UserPanelListTheProductsFromTheCart(Shop* shop) {
	system("cls");
	shop->ListProductsFromUserCart();
	system("pause");
}

void UserPanelBuyEverything(Shop* shop) {
	shop->BuyCurrentUserProducts();
	system("cls");
	system("pause");
}