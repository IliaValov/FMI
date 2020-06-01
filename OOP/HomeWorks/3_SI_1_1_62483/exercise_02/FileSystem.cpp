#include "FileSystem.h"

FileSystem::FileSystem() : mainHardDrive("C:", Date())
{
}

FileSystem::FileSystem(const std::string& mainHardDriveName) : mainHardDrive(mainHardDriveName, Date())
{

}

const bool& FileSystem::AddFileToFolder(const File& file, const std::string& path)
{
	return this->mainHardDrive.AddFileToFolder(file, path);
}

const bool& FileSystem::CreateFolder(const std::string& folderName,const Date& date,const std::string& path)
{
	return this->mainHardDrive.AddFolderToFolder(folderName, date,path);
}

const File& FileSystem::FindFileFromFolder(const std::string& fileName, const std::string& path)
{
	return this->mainHardDrive.GetFileFromFolder(fileName, path);
}
