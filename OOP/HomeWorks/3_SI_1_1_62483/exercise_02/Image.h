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
	std::string nameOfDevice;
	Resolution resolution;

public:

	Image(const std::string& fileName, const ImageExtension& imageExtension, const Date& date, const double& megabytes, const std::string& nameOfDevice, const Resolution& resolution);

	const std::string& GetNameOfDevice() const;
	void SetNameOfDevice(const std::string& nameOfDevice);

	const Resolution GetResolution() const;
	void SetResolution(const Resolution& resolution);



};

