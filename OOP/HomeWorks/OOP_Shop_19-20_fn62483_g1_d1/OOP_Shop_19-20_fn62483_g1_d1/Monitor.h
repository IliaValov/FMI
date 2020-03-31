#pragma once
#include "Product.h"
class Monitor : Product
{
private:
	int heightPx;
	int widthPx;

public:
	Monitor();
	Monitor(const String& name, const String& description, const String& brand, const double& price, const int& quantity, const double& discountInPercentige, const int& widthPx, const int& heightPx);
	Monitor(const Monitor& obj);
	~Monitor();

	void PrintProduct() const override;
};

