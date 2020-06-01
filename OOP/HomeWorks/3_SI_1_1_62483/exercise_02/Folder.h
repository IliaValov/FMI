#pragma once

#include "String.h"
#include "File.h"
#include "Date.h"
#include "List.h"

class Folder
{

private:
	std::string name;
	Date date;

	std::vector<File*> files;
	std::vector<Folder> folders;

	const File* FindFile(const std::string& name) const;
	const int& FindFileIndex(const std::string& name) const;

	const Folder* FindFolder(const std::string& name)const;
	const int& FindFolderIndex(const std::string& name) const;

public:
	Folder();
	Folder(const std::string& name, const Date& date);

	~Folder();

	const std::string& GetName() const;
	void SetName(const std::string& name);

	const Date& GetDate() const;
	void SetDate(const Date& date);

	const bool& AddFile(const File& file);

	const File& GetFile(const int& index) const;
	const File& GetFile(const std::string& fileName) const;

	void DeleteFile(const int& index);
	void DeleteFile(const std::string& fileName);

	const bool& AddFolder(const std::string& folderName, const Date& date);

	const Folder& GetFolder(const int& index) const;
	const Folder& GetFolder(const std::string& folderName) const;

	void DeleteFolder(const int& index);
	void DeleteFolder(const std::string& folderName);

	const bool AddFileToFolder(const File& fileName, const std::string& path);
	const bool AddFolderToFolder(const std::string& folderName, const Date& date, const std::string& path);

	const File& GetFileFromFolder(const std::string& fileName, const std::string& path);

	const bool& AnyFileByName(const std::string& fileName);
	const bool& AnyFolderByName(const std::string& folderName);

};

