#include "String.h"

String::String()
{
	this->text = new char[1];
	this->text[0] = '\0';
}

String::String(String const& str)
{
	this->text = concat(str.text,nullptr);
}

String::String(const char* str)
{
	this->text = concat(str,nullptr);
}

String::~String()
{
	delete[] this->text;
}

int String::Get_Length()
{
	int length = 0;
	while (this->text[length]) {
		length++;
	}

	return length;
}

char* String::Get_String()
{
	return this->text;
}

bool String::operator==(const char* obj)
{
	int currentStringLength = this->Get_Length();
	int objLength = getStrLenth(obj);

	if (objLength != currentStringLength)
		return false;

	for (int i = 0; i < objLength; i++)
	{
		if (this->text[i] != obj[i])
			return false;
	}

	return true;
}

bool String::operator==(const String& obj)
{
	int currentStringLength = this->Get_Length();
	int objLength = getStrLenth(obj.text);

	if (objLength != currentStringLength)
		return false;

	for (int i = 0; i < objLength; i++)
	{
		if (this->text[i] != obj.text[i])
			return false;
	}

	return true;
}

bool String::operator!=(const char* obj)
{
	int currentStringLength = this->Get_Length();
	int objLength = getStrLenth(obj);

	if (objLength != currentStringLength)
		return true;

	bool isEqual = true;

	for (int i = 0; i < objLength; i++)
	{
		if (this->text[i] != obj[i]) {
			isEqual = false;
			break;
		}
	}

	return isEqual;
}

bool String::operator!=(const String& obj)
{

	int currentStringLength = this->Get_Length();
	int objLength = getStrLenth(obj.text);

	if (objLength != currentStringLength)
		return true;

	bool isEqual = true;

	for (int i = 0; i < objLength; i++)
	{
		if (this->text[i] != obj.text[i]) {
			isEqual = false;
			break;
		}
	}

	return !isEqual;
}

String String::operator=(const String& obj)
{
	if (this != &obj) {

		delete[] this->text;

		this->text = concat(obj.text, nullptr);

	}

	return *this;
}

String String::operator=(const char* obj)
{
	delete[] this->text;

	this->text = concat(obj, nullptr);

	return *this;
}

String String::operator+(const String &obj)
{
	String result;

	result.text = concat(this->text, obj.text);

	return result;
}

String String::operator+(const char* obj)
{
	String result;

	result.text = concat(this->text, obj);

	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	os << obj.text;

	return os;
}

int getStrLenth(const char* text)
{
	int length = 0;

	if (text != nullptr) {
		while (text[length] != '\0')
			length++;
	}

	return length;
}

char* concat(const char* text1, const char* text2)
{
	if (text1 == nullptr)
		return nullptr;

	int text1Length = getStrLenth(text1);
	int text2Length = getStrLenth(text2);

	int newTextLength = text1Length + text2Length;

	char* newText = new char[newTextLength + 1];

	for (int i = 0; i < text1Length; i++)
	{
		newText[i] = text1[i];
	}

	if (text2 == nullptr) {
		newText[text1Length] = '\0';

		return newText;
	}

	for (int i = text1Length; i < newTextLength; i++)
	{
		newText[i] = text2[i - text1Length];
	}

	newText[newTextLength] = '\0';

	return newText;
}
