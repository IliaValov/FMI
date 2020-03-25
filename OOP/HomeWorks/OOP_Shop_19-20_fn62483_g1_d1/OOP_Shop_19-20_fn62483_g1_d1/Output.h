#pragma once
#include "String.h"

class Output
{
public:
	bool WriteOnConsole();
	bool WriteLineOnConsole();

	bool WriteOnFile(const String& path, const String& fileName);
	bool WriteLineOnFile(const String& path, const String& fileName);
};

