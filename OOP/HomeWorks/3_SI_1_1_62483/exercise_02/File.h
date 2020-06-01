#pragma once
#include "String.h"
#include "Date.h"
class File
{
private:

	std::string name;
	std::string extension;

	Date date;
	double megabytes;

protected:
	
	virtual void SetName(const std::string& name);
	
	virtual  const std::string& GetExtension() const;
	
	virtual void SetDate(const Date& date);
	
	virtual void SetMegabytes();

public:

	File();
	File(const std::string& name, const std::string& extension, const Date& date, const double& megabytes);

	virtual const std::string& GetName() const;

	virtual void SetExtension(const std::string& extension);

	virtual const Date& GetDate()const;

	virtual const double& GetMegabytes()const;


};

