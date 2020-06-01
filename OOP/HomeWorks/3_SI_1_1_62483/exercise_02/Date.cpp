#include "Date.h"

Date::Date()
{
	
}

Date::Date(const std::string& hour, const std::string& minute, const std::string& day, const std::string& month, const std::string& year) : hour(hour), minute(minute), day(day), month(month), year(year)
{
}

const std::string& Date::GetDate()
{
	return this->day + "/" + this->month + "/" + this->year + " " + this->hour + ":" + this->minute;
}

void Date::SetDate(const std::string& hour, const std::string& minute, const std::string& day, const std::string& month, const std::string& year)
{
	this->hour = hour;
	this->minute = minute;

	this->day = day;
	this->month = month;
	this->year = year;
}
