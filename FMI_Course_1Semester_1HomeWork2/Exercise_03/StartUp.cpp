/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Iliya Vladislavov Valov
* @idnumber 62483
* @task 03
* @compiler VC
*
*/

#include<iostream>

using namespace std;

void PrintTheSmallestArray(char* firstText, char* secondText);
void OverwriteTheSmallerTextIntoTheBiggerText(char* biggerText, char* smallerText, int size);
void GetInputTexts(char* firstText, char* secondText);

bool IsTheInputValid();
//bool IsTheSymbolLiteral(char symbol);

int getTextLenght(char*);

const int TEXT_MAX_LENGHT = pow(2, 10);

int main() {
	char* firstText = new char[TEXT_MAX_LENGHT]();
	char* secondText = new char[TEXT_MAX_LENGHT]();

	GetInputTexts(firstText, secondText);

	int firstTextLenght = getTextLenght(firstText);
	int secondTextLenght = getTextLenght(secondText);

	PrintTheSmallestArray(firstText, secondText);

	if (firstTextLenght > secondTextLenght) {
		cout << firstText;
	}
	else {
		cout << secondText;
	}

	delete[] firstText;
	delete[] secondText;

	return 0;
}

void GetInputTexts(char* firstText, char* secondText) {
	bool isStarted = true;

	while (isStarted) {

		cout << "First text: ";  cin.getline(firstText, TEXT_MAX_LENGHT);

		if (!IsTheInputValid())
		{
			cout << "Wrong input! \r\n";
			continue;
		}

		cout << "Second text: ";  cin.getline(secondText, TEXT_MAX_LENGHT);

		if (!IsTheInputValid())
		{
			cout << "Wrong input!\r\n";
			continue;
		}

		isStarted = false;
	}
}

void PrintTheSmallestArray(char* firstText, char* secondText) {
	int firstTextLenght = getTextLenght(firstText);
	int secondTextLenght = getTextLenght(secondText);

	//Finding biggest array.
	if (firstTextLenght >= secondTextLenght) {
		OverwriteTheSmallerTextIntoTheBiggerText(firstText, secondText, firstTextLenght);
		return;
	}

	OverwriteTheSmallerTextIntoTheBiggerText(secondText, firstText, secondTextLenght);
}

void OverwriteTheSmallerTextIntoTheBiggerText(char* biggerText, char* smallerText, int size) {

	//Overwrite the smallerText in to bigger one.
	//i % textSize is getting currentSymbol from the smallerArray which is needed to be writen on the bigger array.
	int textSize = getTextLenght(smallerText);

	for (int i = 0; i < size; i++)
	{
		biggerText[i] = smallerText[i % textSize];
	}
}

//bool IsTheSymbolLiteral(char symbol) {
//	switch (symbol) {
//	case't':
//		return true;
//	case'n':
//		return true;
//	case'b':
//		return true;
//	case'r':
//		return true;
//	case'a':
//		return true;
//	default:
//		return false;
//	}
//}

bool IsTheInputValid() {
	//Checks if the console is throwing error(exception).
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}

	return true;
}

int getTextLenght(char* text) {
	int lenght = 0;
	//int literals = 0;

	//Get text lenght.
	while (lenght < TEXT_MAX_LENGHT) {
		if (text[lenght] == '\0')
			break;
		/*if (text[lenght] == '\\') {
			if ((lenght + 1) != '\0' && IsTheSymbolLiteral(text[lenght + 1]))
				literals++;
		}*/
		lenght++;
	}

	return lenght;
}