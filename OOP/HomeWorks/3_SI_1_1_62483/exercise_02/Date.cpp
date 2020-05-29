#include "Date.h"

Date::Date() : hour("00"), minute("00"), day("01"), month("01"), year("1970")
{
}

Date::Date(const String& hour, const String& minute, const String& day, const String& month, const String& year) : hour(hour), minute(minute), day(day), month(month), year(year)
{
}

const String& Date::GetDate()
{
	return this->day + "/" + this->month + "/" + this->year + " " + this->hour + ":" + this->minute;
}

void Date::SetDate(const String& hour, const String& minute, const String& day, const String& month, const String& year)
{
	this->hour = hour;
	this->minute = minute;

	this->day = day;
	this->month = month;
	this->year = year;
}
