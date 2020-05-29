#include "Chocolate.h"

Chocolate::Chocolate():Product()
{
	this->daysToExpire = 0;
}

Chocolate::Chocolate(const  std::string& name, const  std::string& description, const  std::string& brand, const double& price, const int& quantity, const double& discountInPercentige, const int& daysToExpire)
	: Product(name, description, brand, price, quantity, discountInPercentige)
{
	this->daysToExpire = daysToExpire;
}

Chocolate::Chocolate(const Chocolate& obj) : Product(obj)
{
	this->daysToExpire = obj.daysToExpire;
}

Chocolate::~Chocolate()
{
}

void Chocolate::PrintProduct() const
{
	std::cout << "	-name: " << this->name << "\r\n";
	std::cout << "	-brand: " << this->brand << "\r\n";
	std::cout << "	-description: " << this->description << "\r\n";
	std::cout << "	-price: " << this->price << "\r\n";
	std::cout << "	-quantity: " << this->quantity << "\r\n";
	std::cout << "	-Expires after: " << this->daysToExpire << " days\r\n";
	std::cout << "	-discount: " << this->discountInPercentige << "%\r\n";
}
