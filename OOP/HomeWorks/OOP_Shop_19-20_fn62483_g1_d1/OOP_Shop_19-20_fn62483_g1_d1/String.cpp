#include "String.h"

String::String()
{
	this->text = new char[0];
}

String::String(String const& str)
{
	this->text = str.text;
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

bool String::operator==(String const* obj)
{
	int currentStringLength = this->Get_Length();
	int objLength = getStrLenth(obj->text);

	if (objLength != currentStringLength)
		return false;

	for (int i = 0; i < objLength; i++)
	{
		if (this->text[i] != obj->text[i])
			return false;
	}

	return true;
}

String String::operator=(String const& obj)
{
	String result;

	result.text = concat(obj.text, nullptr);

	return result;
}

String String::operator=(const char* obj)
{
	String result;

	result.text = concat(obj, nullptr);

	return result;
}

String String::operator+(String const& obj)
{
	String result;

	result.text = concat(this->text, obj.text);

	return result;
}

String String::operator+(char* const& obj)
{
	String result;

	result.text = concat(this->text, obj);

	return result;
}

int getStrLenth(const char* text)
{
	int length = 0;

	while (text[length] != '\0')
		length++;

	return length;
}

char* concat(const char* text1, const char* text2)
{
	if (text1 == nullptr)
		return nullptr;

	int text1Length = getStrLenth(text1);
	int text2Length = getStrLenth(text2);

	char* newText = new char[text1Length + text2Length + 1];

	for (size_t i = 0; i < text1Length; i++)
	{
		newText[i] = text1[i];
	}

	if (text2 == nullptr) {
		newText[text1Length] = '\0';

		return newText;
	}

	for (int i = text1Length; i < text1Length + text2Length; i++)
	{
		newText[i] = text2[i - text1Length];
	}

	newText[text1Length + text2Length] = '\0';

	return newText;
}
