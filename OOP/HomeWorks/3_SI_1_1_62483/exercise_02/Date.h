#pragma once
#include "Date.h"
#include "String.h"

class Date
{
private:
	std::string hour;
	std::string minute;
	
	std::string day;
	std::string month;
	std::string year;

public:
	Date();
	Date(const std::string& hour, const std::string& minute, const std::string& day, const std::string& month, const std::string& year);

	const std::string& GetDate();
	void SetDate(const std::string& hour, const std::string& minute, const std::string& day, const std::string& month, const std::string& year);

};

