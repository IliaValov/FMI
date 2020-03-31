#include "Monitor.h"

Monitor::Monitor() : Product()
{
	this->widthPx = 0;
	this->heightPx = 0;
}

Monitor::Monitor(const String& name, const String& description, const String& brand, const double& price, const int& quantity, const double& discountInPercentige, const int& widthPx, const int& heightPx) :
	Product(name, description, brand, price, quantity, discountInPercentige)
{
	this->widthPx = widthPx;
	this->heightPx = heightPx;
}

Monitor::Monitor(const Monitor& obj) : Product(obj)
{
	this->widthPx = obj.widthPx;
	this->heightPx = obj.heightPx;
}

Monitor::~Monitor()
{
}

void Monitor::PrintProduct() const
{
	std::cout << "	-name: " << this->name << "\r\n";
	std::cout << "	-brand: " << this->brand << "\r\n";
	std::cout << "	-description: " << this->description << "\r\n";
	std::cout << "	-price: " << this->price << "\r\n";
	std::cout << "	-quantity: " << this->quantity << "\r\n";
	std::cout << "	-Resolution: " << this->widthPx << "x" << this->heightPx << " days\r\n";
	std::cout << "	-discount: " << this->discountInPercentige << "%\r\n";
}
