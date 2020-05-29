#pragma once
#include "String.h"
#include "Date.h"
class File
{
private:

	String name;
	String extension;

	Date date;
	double megabytes;

public:
	File();
	File(const String& name, const String& extension, const Date& date, const double& megabytes);

	virtual const String& GetName() const;
	virtual void SetName(const String& name);

	virtual  const String& GetExtension() const;
	virtual void SetExtension(const String& extension);

	virtual const Date& GetDate()const;
	virtual void SetDate(const Date& date);

	virtual const double& GetMegabytes()const;
	virtual void SetMegabytes();

};

