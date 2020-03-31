#pragma once
#include <iostream>

class String
{
private:
	char* text;

public:
	String();
	String(const String& str);
	String(const char* str);
	~String();

	int GetLength();

	char* GetString();

	void Print();

	void Append(const char& symbol);
	void Append(const char* symbols);
	void Append(const String& obj);

	bool operator ==(const char* sym);
	bool operator ==(const String& obj);

	bool operator !=(const char* sym);
	bool operator !=(const String& obj);

	bool operator < (const char* sym);
	bool operator < (const String& obj);

	bool operator >(const char* sym);
	bool operator >(const String& obj);

	String& operator =(const char* obj);
	String& operator =(const String& obj);

	String operator +(const char& symbol);
	String operator +(const char* symbols);
	String operator +(const String& obj);

	friend std::ostream& operator<<(std::ostream& os, const String& obj);

	//TODO Const for obj
	friend std::istream& operator>>(std::istream& is, String& obj);
};

int StringToInt(const char* text);
int GetStrLenth(const char* text);
char* Concat(const char* text1, const char* text2);
