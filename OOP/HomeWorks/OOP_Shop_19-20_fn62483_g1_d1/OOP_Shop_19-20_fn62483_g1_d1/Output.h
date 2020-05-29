#pragma once
#include<iostream>
#include<string>

class Output
{
public:
	const bool WriteOnConsole();
	const bool WriteLineOnConsole();

	const bool WriteOnFile(const  std::string& path, const  std::string& fileName);
	const bool WriteLineOnFile(const  std::string& path, const  std::string& fileName);
};

