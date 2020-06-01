#pragma once
#include "Folder.h"

class FileSystem
{
private:
	Folder mainHardDrive;

public:
	FileSystem();
	FileSystem(const std::string& mainHardDriveName);

	const bool& AddFileToFolder(const File& file, const std::string& path);

	const bool& CreateFolder(const std::string& folderName, const Date& date, const std::string& path);

	const File& FindFileFromFolder(const std::string& fileName, const std::string& path);
};

