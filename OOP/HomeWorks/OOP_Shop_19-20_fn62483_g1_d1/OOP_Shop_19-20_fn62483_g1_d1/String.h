#pragma once
class String
{
private:
	char* text;

public:
	String();
	String(String const& str);
	~String();

	int Get_Length();

	char* Get_String();

	bool operator ==(const char* obj);
	bool operator ==(String const* obj);

	String operator =(const char* obj);
	String operator =(String const& obj);

	String operator +(char* const& obj);
	String operator +(String const& obj);
};

int getStrLenth(const char* text);
char* concat(const char* text1, const char* text2);
