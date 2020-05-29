#include "Folder.h"

const File* Folder::FindFile(const String& name)const
{
	for (int i = 0; i < this->files.GetLength(); i++)
	{
		if ((*this->files[i]).GetName() == name) {
			return this->files[i];
		}
	}

	return  nullptr;
}

const int& Folder::FindFileIndex(const String& name)const
{
	for (int i = 0; i < this->files.GetLength(); i++)
	{
		if ((*this->files[i]).GetName() == name) {
			return i;
		}
	}

	return -1;
}

const Folder* Folder::FindFolder(const String& name)const
{
	for (int i = 0; i < this->folders.GetLength(); i++)
	{
		if (this->folders[i].GetName() == name) {
			return &this->folders[i];
		}
	}

	return nullptr;
}

const int& Folder::FindFolderIndex(const String& name)const
{
	for (int i = 0; i < this->folders.GetLength(); i++)
	{
		if (this->folders[i].GetName() == name) {
			return i;
		}
	}

	return -1;
}

Folder::Folder()
{
}

Folder::Folder(const String& name, const Date& date) : name(name), date(date)
{
}

Folder::~Folder()
{
	for (int i = 0; i < this->files.GetLength(); i++)
	{
		delete this->files[i];
	}

}

const String& Folder::GetName() const
{
	return this->name;
}

void Folder::SetName(const String& name)
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

const File& Folder::GetFile(const String& fileName) const
{
	return *this->FindFile(fileName);
}

const bool& Folder::AddFile(const File& file)
{
	File* temp = new File(file);

	if (this->AnyFileByName(file.GetName()))
		return false;

	return this->files.AddElement(temp);
}

void Folder::DeleteFile(const int& index)
{
	this->files.DeleteElement(index);
}

void Folder::DeleteFile(const String& fileName)
{
	this->files.DeleteElement(this->FindFileIndex(fileName));
}

const Folder& Folder::GetFolder(const int& index)const
{
	return this->folders[index];
}

const Folder& Folder::GetFolder(const String& folderName) const
{
	return *this->FindFolder(folderName);
}

const bool& Folder::AddFolder(const String& folderName, const Date& date)
{
	Folder temp (folderName,date);

	if (this->AnyFolderByName(folderName))
		return false;

	return this->folders.AddElement(temp);
}

void Folder::DeleteFolder(const int& index) 
{
	this->folders.DeleteElement(index);
}

void Folder::DeleteFolder(const String& folderName) 
{
	this->folders.DeleteElement(this->FindFolderIndex(folderName));
}

const bool& Folder::AnyFileByName(const String& fileName)
{
	if (this->FindFileIndex(fileName) == -1) {
		return false;
	}

	return true;
}

const bool& Folder::AnyFolderByName(const String& folderName)
{
	if (this->FindFolderIndex(folderName) == -1) {
		return false;
	}

	return true;
}
