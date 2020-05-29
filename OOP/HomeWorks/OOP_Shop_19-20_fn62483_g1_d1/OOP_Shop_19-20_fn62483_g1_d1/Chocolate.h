#pragma once
#include<iostream>
#include<string>

#include "Product.h"

class Chocolate : virtual public Product
{
private:
	int daysToExpire;
public:
	Chocolate();
	Chocolate(const std::string& name, const  std::string& description, const  std::string& brand, const double& price, const int& quantity, const double& discountInPercentige, const int& daysToExpire);
	Chocolate(const Chocolate& obj);
	~Chocolate();

	void PrintProduct() const override;
};

