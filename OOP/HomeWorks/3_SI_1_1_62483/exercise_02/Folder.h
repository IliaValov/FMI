#pragma once

#include "String.h"
#include "File.h"
#include "Date.h"
#include "List.h"

class Folder
{

private:
	String name;
	Date date;

	List<File*> files;
	List<Folder> folders;

	const File* FindFile(const String& name) const;
	const int& FindFileIndex(const String& name) const;

	const Folder* FindFolder(const String& name)const;
	const int& FindFolderIndex(const String& name) const;

public:
	Folder();
	Folder(const String& name, const Date& date);

	~Folder();

	const String& GetName() const;
	void SetName(const String& name);

	const Date& GetDate() const;
	void SetDate(const Date& date);

	const bool& AddFile(const File& file);

	const File& GetFile(const int& index) const;
	const File& GetFile(const String& fileName) const;

	void DeleteFile(const int& index);
	void DeleteFile(const String& fileName);

	const bool& AddFolder(const String& folderName, const Date& date);

	const Folder& GetFolder(const int& index) const;
	const Folder& GetFolder(const String& folderName) const;

	void DeleteFolder(const int& index);
	void DeleteFolder(const String& folderName);

	const bool& AnyFileByName(const String& fileName);
	const bool& AnyFolderByName(const String& folderName);

};

