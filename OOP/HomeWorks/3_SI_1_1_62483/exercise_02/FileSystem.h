#pragma once
#include "Folder.h"

class FileSystem
{
private:
	Folder disk;

public:

	const bool& AddFileToFolder(const File& file, const String& path);

	const bool& CreateFolder(const Folder& folder, const String& path);


};

