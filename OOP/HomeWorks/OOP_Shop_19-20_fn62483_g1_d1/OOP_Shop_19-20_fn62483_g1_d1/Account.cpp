#include "Account.h"

Account::Account() : balance(0)
{
}

const double Account::GetBalance() const
{
	return this->balance;
}

const bool Account::Add(const double& money)
{
	if (money < 0) {
		return false;
	}

	this->balance += money;

	return true;
}

const bool Account::Substract(const double& money)
{
	if (this->balance - money < 0)
		return false;

	this->balance -= money;

	return true;
}
