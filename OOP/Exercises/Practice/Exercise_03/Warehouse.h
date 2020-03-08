#pragma once

#include "Stock.h";

class Warehouse
{
private:
	Stock* stocks;

	int size = 0;
	int length = 0;

	void Resize_Array() {
		int size = this->size * 2;
		int length = this->length;


		Stock* stocks = new Stock[size];

		for (size_t i = 0; i < length; i++)
		{
			stocks[i] = this->stocks[i];
		}

		delete[] this->stocks;

		this->stocks = stocks;

		this->size = size;
	}

public:
	Warehouse() {
		this->stocks = new Stock[0];
	}

	~Warehouse() {
		delete[] this->stocks;
	}

	int Get_Length() {
		return this->length;
	}

	int Get_Size() {
		return this->size;
	}

	int AddStock(Stock stock) {

		if (this->length == 0 && this->size == 0) {
			this->length = 1;
			this->size = 1;

			this->Resize_Array();

			stock.Set_Id(this->length);
			this->stocks[0] = stock;

			return this->length;
		}

		if (this->length == this->size) {
			this->Resize_Array();
		}

		this->length++;

		stock.Set_Id(this->length);

		this->stocks[this->length - 1] = stock;

	}

	double Calculate_Profit_Of_Specific_Stock(int id) {
		Stock stock = Find_Specific_Stock_By_Stock_Type(id);

		return stock.Get_PriceToSell() * stock.Get_Quantity();
	}

	Stock Find_Specific_Stock_By_Stock_Type(int id) {
		for (size_t i = 0; i < this->length; i++)
		{
			if (stocks[i].Get_Id() == id) {
				return stocks[i];
			}
		}
	}
};

