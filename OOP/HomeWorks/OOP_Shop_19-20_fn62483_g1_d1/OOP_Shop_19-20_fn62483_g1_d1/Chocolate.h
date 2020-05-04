#pragma once
#include "Product.h"
class Chocolate : virtual public Product
{
private:
	int daysToExpire;
public:
	Chocolate();
	Chocolate(const String& name, const String& description, const String& brand, const double& price, const int& quantity, const double& discountInPercentige, const int& daysToExpire);
	Chocolate(const Chocolate& obj);
	~Chocolate();

	void PrintProduct() const override;
};

