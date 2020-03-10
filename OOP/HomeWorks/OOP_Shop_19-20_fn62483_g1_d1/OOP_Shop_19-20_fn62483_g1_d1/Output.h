#pragma once
#include "String.h"

class Output
{
public:
	bool WriteOnConsole();
	bool WriteLineOnConsole();

	bool WriteOnFile(String path, String fileName);
	bool WriteLineOnFile(String path, String fileName);
};

