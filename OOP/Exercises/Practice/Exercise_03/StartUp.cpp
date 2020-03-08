#include <iostream>;
#include "Warehouse.h";

using namespace std;

int main() {
	int lengthOfStocks = 0;

	Warehouse warehouse;

	cout << "Enter quanitity of the stocks: "; cin >> lengthOfStocks;

	for (size_t i = 0; i < lengthOfStocks; i++)
	{
		cout << "Enter information for a stock: \r\n";

		int quantityOfTheStock = 0;
		int stockType = 0;
		double priceToBuy = 0;
		double priceToSell = 0;

		cout << "Quantity of the stock: "; cin >> quantityOfTheStock;
		cout << "Price to buy: "; cin >> priceToBuy;
		cout << "Price to sell: "; cin >> priceToSell;
		cout << "Choose stockType between 1 and 4 : "; cin >> stockType;

		Stock stock(quantityOfTheStock, priceToBuy, priceToSell, (StockType)stockType);

		warehouse.AddStock(stock);
	}

	for (size_t i = 0; i < warehouse.Get_Length(); i++)
	{
		cout << "Profit of the stock: " << warehouse.Calculate_Profit_Of_Specific_Stock(i + 1) << "\r\n";
	
		warehouse.Find_Specific_Stock_By_Stock_Type(i + 1).Print_Whole_Information();
	}

	
	


}