#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "List.h"

class String
{
private:
	char* text;

public:
	String();
	String(const String& str);
	String(const char* str);
	~String();

	const int GetLength() const;

	const char* GetString() const;

	void Print();

	void Append(const char& symbol);
	void Append(const char* symbols);
	void Append(const String& obj);

	const bool operator ==(const char* sym) const;
	//bool operator ==(const char* sym) const;
	const bool operator ==(const String& obj) const;
	//bool operator ==(const String& obj) const;

	const bool operator !=(const char* sym) const;
	const bool operator !=(const String& obj) const;

	const bool operator < (const char* sym)const;
	const bool operator < (const String& obj)const;

	const bool operator >(const char* sym)const;
	const bool operator >(const String& obj)const;

	String& operator =(const char* obj);
	String& operator =(const String& obj);

	String& operator +(const char& symbol);
	String& operator +(const char* symbols);
	String& operator +(const String& obj);

	char operator[](const int&) const;

	friend std::ostream& operator<<(std::ostream& os, const String& obj);

	//TODO Const for obj
	friend std::istream& operator>>(std::istream& is, String& obj);
};

const std::vector<std::string> Split(std::string text, const char& splitBy);
const int StringToInt(const char* text);
const int GetStrLenth(const char* text);
char* Concat(const char* text1, const char* text2);
