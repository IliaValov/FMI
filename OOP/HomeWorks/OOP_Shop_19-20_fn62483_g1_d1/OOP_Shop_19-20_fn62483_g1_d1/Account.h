#pragma once
class Account
{
private:
	double balance;

public:
	Account();

	const double GetBalance() const;

	const bool Add(const double& money);
	const bool Substract(const double& money);
};

