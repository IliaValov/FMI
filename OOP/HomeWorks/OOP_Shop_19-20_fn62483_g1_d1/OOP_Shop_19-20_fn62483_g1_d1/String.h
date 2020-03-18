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

	int Get_Length();

	char* Get_String();

	bool operator ==(const char* obj);
	bool operator ==(const String& obj);

	bool operator !=(const char* obj);
	bool operator !=(const String& obj);

	String& operator =(const char* obj);
	String& operator =(const String& obj);

	String operator +(char symbol);
	String operator +(const char* symbols);
	String operator +(const String& obj);

	friend std::ostream& operator<<(std::ostream& os, const String& obj);
	friend std::istream& operator>>(std::istream& is, String& obj);
};

int getStrLenth(const char* text);
char* concat(const char* text1, const char* text2);
