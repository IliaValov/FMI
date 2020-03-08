#pragma once

#include "StockType.h";
#include <iostream>;

using namespace std;

class Stock
{


private:
	int quantity = 0;

	int id = 0;

	double priceToBuy = 0;
	double priceToSell = 0;

	StockType stockType = StockType::None;

public:

	Stock() {

	}

	Stock(int quantity, int priceToBuy, int priceToSell, StockType stockType) {
		this->quantity = quantity;
		this->priceToBuy = priceToBuy;
		this->priceToSell = priceToSell;
		this->stockType = stockType;

	}

	int Get_Quantity() {
		return this->quantity;
	}

	void Set_Quantity(int value) {
		this->quantity = value;
	}

	double Get_PriceToBuy() {
		return this->priceToBuy;
	}

	double Set_PriceToBuy(double value) {
		this->priceToBuy = value;
	}

	double Get_PriceToSell() {
		return this->priceToSell;
	}

	double Set_PriceToSell(double value) {
		this->priceToSell = value;
	}

	int Get_Id() {
		return this->id;
	}

	void Set_Id(int id) {
		this->id = id;
	}

	void Print_Whole_Information() {
	
		cout << "Id: " << this->id << "\r\n";
		cout << "Quantity: " << this->quantity << "\r\n";
		cout << "Price to buy: " << this->priceToBuy << "\r\n";
		cout << "Price to sell: " << this->priceToSell << "\r\n";
		cout << "Stock type: " << this->stockType << "\r\n";
	}
};


