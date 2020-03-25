#pragma once
#include <iostream>
#include <fstream>
#include "String.h"
class Input
{
public:
	template<typename T>
	T ReadLineFromConsole(const int& lengthOfSymbols);

	template<typename T>
	T ReadLineFromFile(const String& path, const String& fileName, const int& lengthOfSymbols);
};

template<typename T>
inline T Input::ReadLineFromConsole(const int& lengthOfSymbols)
{
	T result();
	char* a = new char[lengthOfSymbols];

	std::cin.getline(a, lengthOfSymbols);

	result = a;

	return result;
}

template<typename T>
inline T Input::ReadLineFromFile(const String& path, const String& fileName, const int& lengthOfSymbols)
{
	T result;



	return result;
}
