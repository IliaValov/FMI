#include "String.h"

String::String()
{
	this->text = new char[1];
	this->text[0] = '\0';
}

String::String(const String& str)
{
	this->text = Concat(str.text, nullptr);
}

String::String(const char* str)
{
	this->text = Concat(str, nullptr);
}

String::~String()
{
	delete[] this->text;
}

const int String::GetLength()const
{
	int length = 0;
	while (this->text[length]) {
		length++;
	}

	return length;
}

const char* String::GetString()const
{
	return this->text;
}

void String::Print()
{
	std::cout << this->text << "\r\n";
}

void String::Append(const char& symbol)
{
	char* previousText = this->text;

	char temp[2]{ symbol, '\0' };

	this->text = Concat(this->text, temp);

	delete[] previousText;
}

void String::Append(const char* symbols)
{
	char* previousText = this->text;

	this->text = Concat(this->text, symbols);;

	delete[] previousText;
}

void String::Append(const String& obj)
{
	char* previousText = this->text;

	this->text = Concat(this->text, obj.text);

	delete[] previousText;
}

const bool String::operator==(const char* symbols)const
{
	int currentStringLength = this->GetLength();
	int objLength = GetStrLenth(symbols);

	if (objLength != currentStringLength)
		return false;

	for (int i = 0; i < objLength; i++)
	{
		if (this->text[i] != symbols[i])
			return false;
	}

	return true;
}

const bool String::operator==(const String& obj)const
{
	int currentStringLength = GetStrLenth(this->text);
	int objLength = GetStrLenth(obj.text);

	if (objLength != currentStringLength)
		return false;

	for (int i = 0; i < objLength; i++)
	{
		if (this->text[i] != obj.text[i])
			return false;
	}

	return true;
}

const bool String::operator!=(const char* obj)const
{
	int currentStringLength = this->GetLength();
	int objLength = GetStrLenth(obj);

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

const bool String::operator!=(const String& obj)const
{

	int currentStringLength = this->GetLength();
	int objLength = GetStrLenth(obj.text);

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

const bool String::operator<(const char* text)const
{
	int firstTextLength = this->GetLength();
	int secondTextLength = GetStrLenth(text);

	for (int i = 0; i < GetLowest(firstTextLength, secondTextLength); i++)
	{
		char firstTextcurrentSymbol = this->text[i];
		char secondTextcurrentSymbol = text[i];

		if (firstTextcurrentSymbol < secondTextcurrentSymbol)
			return true;
		else if (firstTextcurrentSymbol > secondTextcurrentSymbol)
			return false;
	}

	if (firstTextLength < secondTextLength || firstTextLength != secondTextLength) {
		return true;
	}
	else {
		return false;
	}
}

const bool String::operator<(const String& obj)const
{
	int firstTextLength = this->GetLength();
	int secondTextLength = GetStrLenth(obj.text);

	for (int i = 0; i < GetLowest(firstTextLength, secondTextLength); i++)
	{
		char firstTextcurrentSymbol = this->text[i];
		char secondTextcurrentSymbol = obj.text[i];

		if (firstTextcurrentSymbol < secondTextcurrentSymbol)
			return true;
		else if (firstTextcurrentSymbol > secondTextcurrentSymbol)
			return false;
	}

	if (firstTextLength < secondTextLength || firstTextLength != secondTextLength) {
		return true;
	}
	else {
		return false;
	}
}

const bool String::operator>(const char* text)const
{
	int firstTextLength = this->GetLength();
	int secondTextLength = GetStrLenth(text);

	for (int i = 0; i < GetLowest(firstTextLength, secondTextLength); i++)
	{
		char firstTextcurrentSymbol = this->text[i];
		char secondTextcurrentSymbol = text[i];

		if (firstTextcurrentSymbol < secondTextcurrentSymbol)
			return false;
		else if (firstTextcurrentSymbol > secondTextcurrentSymbol)
			return true;
	}

	if (firstTextLength < secondTextLength || firstTextLength == secondTextLength) {
		return false;
	}
	else {
		return true;
	}
}

const bool String::operator>(const String& obj)const
{
	int firstTextLength = this->GetLength();
	int secondTextLength = GetStrLenth(obj.text);

	for (int i = 0; i < GetLowest(firstTextLength, secondTextLength); i++)
	{
		char firstTextcurrentSymbol = this->text[i];
		char secondTextcurrentSymbol = obj.text[i];

		if (firstTextcurrentSymbol < secondTextcurrentSymbol)
			return false;
		else if (firstTextcurrentSymbol > secondTextcurrentSymbol)
			return true;
	}


	if (firstTextLength < secondTextLength || firstTextLength == secondTextLength) {
		return false;
	}
	else {
		return true;
	}
}

String& String::operator=(const String& obj)
{
	if (this != &obj) {

		delete[] this->text;

		this->text = Concat(obj.text, nullptr);
	}

	return *this;
}

String& String::operator=(const char* obj)
{

	delete[] this->text;

	this->text = Concat(obj, nullptr);

	return *this;
}

String& String::operator+(const String& obj)
{
	String result;

	result.text = Concat(this->text, obj.text);

	return result;
}

String& String::operator+(const char& symbol)
{
	String result;

	char temp[2]{ symbol, '\0' };

	result.text = Concat(this->text, temp);

	return result;
}

String& String::operator+(const char* obj)
{
	String result;

	result.text = Concat(this->text, obj);

	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	os << obj.text;

	return os;
}

std::istream& operator>>(std::istream& is, String& obj)
{
	char c;
	while (std::cin.get(c) && c != '\n') {
		String temp = (obj + c);

		obj = temp;
	}

	return is;
}

const int StringToInt(const char* text)
{
	int sum = 0;

	for (int i = 0; i < GetStrLenth(text); i++)
	{
		sum += text[i];
	}

	return sum;
}

const int GetStrLenth(const char* text)
{
	int length = 0;

	if (text != nullptr) {
		while (text[length] != '\0')
			length++;
	}

	return length;
}

char* Concat(const char* text1, const char* text2)
{
	if (text1 == nullptr)
		return nullptr;

	int text1Length = GetStrLenth(text1);
	int text2Length = GetStrLenth(text2);

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

const int GetLowest(int a, int b)
{
	if (a > b)
		return a;

	return b;

}
