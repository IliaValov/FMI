#pragma once
#include <iostream>
#include <fstream>
#include "String.h"
class Input
{
public:
	template<typename T>
	T ReadLineFromConsole(int lengthOfSymbols);

	template<typename T>
	T ReadLineFromFile(String path, String fileName, int lengthOfSymbols);
};

template<typename T>
inline T Input::ReadLineFromConsole(int lengthOfSymbols)
{
	T result();
	char* a = new char[lengthOfSymbols];

	std::cin.getline(a, lengthOfSymbols);

	result = a;

	return result;
}

template<typename T>
inline T Input::ReadLineFromFile(String path, String fileName, int lengthOfSymbols)
{
	T result;



	return result;
}
