#pragma once
#include "Date.h"
#include "String.h"

class Date
{
private:
	String hour;
	String minute;
	
	String day;
	String month;
	String year;
public:
	Date();
	Date(const String& hour, const String& minute, const String& day, const String& month, const String& year);

	const String& GetDate();
	void SetDate(const String& hour, const String& minute, const String& day, const String& month, const String& year);

};

