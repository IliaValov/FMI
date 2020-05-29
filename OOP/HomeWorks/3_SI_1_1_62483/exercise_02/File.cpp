#include "File.h"

File::File(): name(""), extension(""), date(), megabytes(-1)
{
}

File::File(const String& name, const String& extension, const Date& date, const double& megabytes) : name(name), extension(extension), date(date), megabytes(megabytes)
{
}


const String& File::GetName()const
{
	return this->name;
}

void File::SetName(const String& name)
{
	this->name = name;
}

const String& File::GetExtension() const
{
	return this->extension;
}

void File::SetExtension(const String& extension)
{
	this->extension = extension;
}

const Date& File::GetDate()const
{
	return this->date;
}

void File::SetDate(const Date& date)
{
	this->date = date;
}

const double& File::GetMegabytes() const
{
	return this->megabytes;
}

void File::SetMegabytes()
{
	this->megabytes = megabytes;
}
