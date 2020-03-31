#pragma once
#include "String.h"

class Output
{
public:
	const bool WriteOnConsole();
	const bool WriteLineOnConsole();

	const bool WriteOnFile(const String& path, const String& fileName);
	const bool WriteLineOnFile(const String& path, const String& fileName);
};

