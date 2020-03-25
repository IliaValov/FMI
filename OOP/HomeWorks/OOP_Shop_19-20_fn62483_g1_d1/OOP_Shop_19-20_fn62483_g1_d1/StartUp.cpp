#include <iostream> 
#include "List.h"
#include "String.h"

#include "Shop.h"
#include "Category.h"
using namespace std;


void Administration_Panel(Shop* shop);
void Administration_Panel_Add_Category(Shop* shop);
void Administration_Panel_Add_Product_To_Category(Shop* shop);
void Administration_Panel_Delete_Product_By_Name(Shop* shop);
void Administration_Panel_Delete_Category_By_Name(Shop* shop);

void User_Panel(Shop* shop);
void User_Panel_Add_Product_To_Cart(Shop* shop);
void User_Panel_Delete_Product_From_Cart(Shop* shop);
void User_Panel_List_The_Products_From_The_Cart(Shop* shop);
void User_Panel_Buy_Everything(Shop* shop);

int main() {
	Shop shop;
	String shopName;

	cout << "Enter name for the shop \r\n";

	cin >> shopName;

	shop.Set_Name(shopName);

	char command = '\0';

	while (true) {
		cout << "A: For entering administration panel\r\n";
		cout << "U: For entering user panel\r\n";
		cout << "E: For exiting\r\n";
		cout << "Enter command: ";

		cin >> command;

		switch (command) {
		case 'A':
			Administration_Panel(&shop);
			break;
		case 'U':
			User_Panel(&shop);
			break;
		case'E':
			return 0;
		default:
			cout << "Invalid command!";
		}
	}

	return 0;
}

void Administration_Panel(Shop* shop) {
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
			Administration_Panel_Add_Product_To_Category(shop);
			break;
		case'C':
			Administration_Panel_Add_Category(shop);
			break;
		case'F':
			Administration_Panel_Delete_Category_By_Name(shop);
			break;
		case'G':
			Administration_Panel_Delete_Product_By_Name(shop);
			break;
		case'E':
			return;
			break;
		default:
			cout << "Invalid command";
		}
	}
}

void Administration_Panel_Add_Category(Shop* shop) {
	Category category;
	String name;

	cout << "Enter name for the category: \r\n";

	cin.ignore();
	cin >> name;

	category.Set_Name(name);

	shop->Add_Category(category);

	cout << "Category " << name << " is added\r\n";

	system("pause");
}

void Administration_Panel_Add_Product_To_Category(Shop* shop) {
	String categoryName;

	String productName;
	String productBrand;
	String productDescription;

	double price = 0;
	int quantity = 0;
	double discountInPercentiges;
	while (true) {
		system("cls");
		cout << "Creating product: \r\n";

		shop->Print_All_Categories_Names();

		cout << "Type the name of one of the categories from above: ";

		cin >> categoryName;

		cin.clear();
		cin.sync();

		if (shop->Any_Category_By_This_Name(categoryName))
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

	shop->Add_Product_To_Category(categoryName, product);
}

void Administration_Panel_Delete_Product_By_Name(Shop* shop) {

	String productName;

	while (true) {
		system("cls");
		shop->Print_All_Categories_Products_Names();

		cout << "Choose one of the products from above to be deleted: ";

		cin.ignore();
		cin >> productName;

		if (shop->Any_Product_By_This_Name(productName))
			break;

		productName = "";

		cout << "Invalid name!";
		system("pause");
	}

	shop->Delete_Product_From_Shop_By_Name(productName);
	cout << "Deleted Product";
	system("pause");
}


void Administration_Panel_Delete_Category_By_Name(Shop* shop) {

	String categoryName;

	while (true) {
		system("cls");
		shop->Print_All_Categories_Names();

		cout << "Choose one of the products from above to be deleted: ";

		cin.ignore();
		cin >> categoryName;

		if (shop->Any_Category_By_This_Name(categoryName))
			break;

		categoryName = "";
		cout << "Invalid name!";
		system("pause");
	}

	shop->Delete_Category_From_Shop_By_Name(categoryName);
	cout << "Deleted category";
	system("pause");
}

void User_Panel(Shop* shop) {
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
				User_Panel_Add_Product_To_Cart(shop);
				break;
			case'D':
				User_Panel_Delete_Product_From_Cart(shop);
				break;
			case'L':
				User_Panel_List_The_Products_From_The_Cart(shop);
				break;
			case'B':
				User_Panel_Buy_Everything(shop);
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

void User_Panel_Add_Product_To_Cart(Shop* shop) {
	String productName;

	while (true) {
		shop->Print_All_Categories_Products();
		cout << "Type the name of the product you want: ";

		cin.ignore();
		cin >> productName;

		if (shop->Any_Product_By_This_Name(productName))
			break;

		productName = "";
		cout << "Invalid name!";
	}

	Product chosedProduct = shop->Get_Product_By_Name(productName);

	ProductCart productToBeAdded = chosedProduct;

	shop->Add_Product_To_Cart(productToBeAdded);
	cout << "Added product to cart";
	system("pause");
}

void User_Panel_Delete_Product_From_Cart(Shop* shop) {
	String productName;

	while (true) {
		system("cls");
		shop->Print_All_Categories_Names();

		cout << "Choose one of the products from above to be deleted: ";

		cin.ignore();
		cin >> productName;

		if (shop->Any_Product_In_Cart_By_This_Name(productName))
			break;

		productName = "";
		cout << "Invalid name!";
		system("pause");
	}

	shop->Delete_Product_From_Cart_By_Name(productName);
	cout << "Product is deleted";
	system("pause");
}

void User_Panel_List_The_Products_From_The_Cart(Shop* shop) {
	system("cls");
	shop->List_Products_From_Cart();
	system("pause");
}

void User_Panel_Buy_Everything(Shop* shop) {
	shop->Buy_All_Products_From_Cart();
	system("cls");
	system("pause");
}