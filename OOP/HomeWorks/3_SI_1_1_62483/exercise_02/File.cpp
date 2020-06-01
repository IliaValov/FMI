#include "File.h"

File::File(): name(""), extension(""), date(), megabytes(-1)
{
}

File::File(const std::string& name, const std::string& extension, const Date& date, const double& megabytes) : name(name), extension(extension), date(date), megabytes(megabytes)
{
}


const std::string& File::GetName()const
{
	return this->name;
}

void File::SetName(const std::string& name)
{
	this->name = name;
}

const std::string& File::GetExtension() const
{
	return this->extension;
}

void File::SetExtension(const std::string& extension)
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
