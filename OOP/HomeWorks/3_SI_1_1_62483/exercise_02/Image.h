#pragma once
#include "File.h"
#include "String.h"
#include "Resolution.h"

enum class ImageExtension {
	JPG = 1,
	PNG = 2,
};

class Image : public File
{
private:
	String nameOfDevice;
	Resolution resolution;

public:

	Image(const String& fileName, const ImageExtension& imageExtension, const Date& date, const double& megabytes, const String& nameOfDevice, const Resolution& resolution);

	const String& GetNameOfDevice() const;
	void SetNameOfDevice(const String& nameOfDevice);

	const Resolution GetResolution() const;
	void SetResolution(const Resolution& resolution);



};

