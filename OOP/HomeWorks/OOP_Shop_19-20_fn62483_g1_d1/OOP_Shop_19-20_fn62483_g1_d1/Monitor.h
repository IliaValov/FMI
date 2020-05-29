#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "Product.h"
class Monitor : virtual public Product
{
private:
	int heightPx;
	int widthPx;

public:
	Monitor();
	Monitor(const  std::string& name, const  std::string& description, const  std::string& brand, const double& price, const int& quantity, const double& discountInPercentige, const int& widthPx, const int& heightPx);
	Monitor(const Monitor& obj);
	~Monitor();

	void PrintProduct() const override;
};

