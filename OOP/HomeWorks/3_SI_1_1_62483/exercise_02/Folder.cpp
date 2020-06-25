#include "Folder.h"

const File* Folder::FindFile(const std::string& name)const
{
	for (int i = 0; i < this->files.size(); i++)
	{
		if ((*this->files[i]).GetName() == name) {
			return this->files[i];
		}
	}

	return  nullptr;
}

const int& Folder::FindFileIndex(const std::string& name)const
{
	for (int i = 0; i < this->files.size(); i++)
	{
		if ((*this->files[i]).GetName() == name) {
			return i;
		}
	}

	return -1;
}

const Folder* Folder::FindFolder(const std::string& name)const
{
	for (int i = 0; i < this->folders.size(); i++)
	{
		if (this->folders[i].GetName() == name) {
			return &this->folders[i];
		}
	}

	return nullptr;
}

const int& Folder::FindFolderIndex(const std::string& name)const
{
	for (int i = 0; i < this->folders.size(); i++)
	{
		if (this->folders[i].GetName() == name) {
			return i;
		}
	}

	return -1;
}

Folder::Folder() : name(), date()
{
}

Folder::Folder(const std::string& name, const Date& date) : name(name), date(date)
{
}

Folder::~Folder()
{
	for (int i = 0; i < this->files.size(); i++)
	{
		delete this->files[i];
	}

}

const std::string& Folder::GetName() const
{
	return this->name;
}

void Folder::SetName(const std::string& name)
{
	this->name = name;
}

const Date& Folder::GetDate() const
{
	return this->date;
}

void Folder::SetDate(const Date& date)
{
	this->date = date;
}

const File& Folder::GetFile(const int& index)const
{
	return *this->files[index];
}

const File& Folder::GetFile(const std::string& fileName) const
{
	return *this->FindFile(fileName);
}

const bool& Folder::AddFile(const File& file)
{
	File* temp = new File(file);

	if (this->AnyFileByName(file.GetName()))
		return false;

	this->files.push_back(temp);

	return true;
}

void Folder::DeleteFile(const int& index)
{
	//this->files.DeleteElement(index);
}

void Folder::DeleteFile(const std::string& fileName)
{
	//this->files.DeleteElement(this->FindFileIndex(fileName));
}

const Folder& Folder::GetFolder(const int& index)const
{
	return this->folders[index];
}

const Folder& Folder::GetFolder(const std::string& folderName) const
{
	return *this->FindFolder(folderName);
}

const bool& Folder::AddFolder(const std::string& folderName, const Date& date)
{
	Folder temp(folderName, date);

	if (this->AnyFolderByName(folderName))
		return false;

	this->folders.push_back(temp);

	return true;
}

void Folder::DeleteFolder(const int& index)
{
	//this->folders.DeleteElement(index);
}

void Folder::DeleteFolder(const std::string& folderName)
{
	//this->folders.DeleteElement(this->FindFolderIndex(folderName));
}

const bool Folder::AddFileToFolder(const File& file, const std::string& path)
{
	std::vector<std::string> results = Split(path, '/');

	if (results[results.size() - 1] == this->name) {
		return this->AddFile(file);
	}

	else if (results.size() > 1) {
		std::string text;
		for (int i = 1; i < results.size(); i++)
		{
			text += results[i];
			text += '/';
		}

		for (int i = 0; i < this->folders.size(); i++)
		{
			if (this->folders[i].GetName() == results[1]) {
				return this->folders[i].AddFileToFolder(file, text);
			}
		}
	}

	return false;
}

const bool Folder::AddFolderToFolder(const std::string& folderName, const Date& date, const std::string& path)
{
	std::vector<std::string> results = Split(path, '/');


	if (results[results.size() - 1] == this->name) {
		return this->AddFolder(folderName, date);
	}

	else if (results.size() > 1) {
		std::string text;
		for (int i = 1; i < results.size(); i++)
		{
			text += results[i];
			text += '/';
		}

		for (int i = 0; i < this->folders.size(); i++)
		{
			if (this->folders[i].GetName() == results[0]) {
				return this->folders[i].AddFolderToFolder(folderName, date, text);
			}
		}
	}

	return false;
}

const File& Folder::GetFileFromFolder(const std::string& fileName, const std::string& path) const
{
	std::vector<std::string> results = Split(path, '/');

	if (results.size() == 1) {
		return *this->FindFile(fileName);
	}

	else if (results.size() > 1) {
		std::string text;
		for (int i = 1; i < results.size(); i++)
		{
			text += results[i];
			text += '/';
		}

		for (int i = 0; i < this->folders.size(); i++)
		{
			if (this->folders[i].GetName() == results[1]) {
				return this->GetFileFromFolder(fileName, text);
			}
		}
	}

	return File();
}

const bool& Folder::AnyFileByName(const std::string& fileName) const
{
	if (this->FindFileIndex(fileName) == -1) {
		return false;
	}

	return true;
}

const bool& Folder::AnyFolderByName(const std::string& folderName) const
{
	if (this->FindFolderIndex(folderName) == -1) {
		return false;
	}

	return true;
}
