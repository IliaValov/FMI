#include "Image.h"

Image::Image(const String& fileName, const ImageExtension& imageExtension, const Date& date, const double& megabytes, const String& nameOfDevice, const Resolution& resolution)
	: nameOfDevice(nameOfDevice), resolution(resolution), File(fileName, "", date, megabytes)
{
	if (imageExtension == ImageExtension::JPG) {
		this->SetExtension(".jpg");
	}
	else if (imageExtension == ImageExtension::PNG) {
		this->SetExtension(".png");
	}
	else {
		this->SetExtension("WRONG EXTENSION");
	}
}

const String& Image::GetNameOfDevice() const
{
	return this->nameOfDevice;
}

void Image::SetNameOfDevice(const String& nameOfDevice)
{
	this->nameOfDevice = nameOfDevice;
}

const Resolution Image::GetResolution() const
{
	return this->resolution;
}

void Image::SetResolution(const Resolution& resolution)
{
	this->resolution = resolution;
}
