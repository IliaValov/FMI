/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Iliya Vladislavov Valov
* @idnumber 62483
* @task 04
* @compiler VC
*
*/

#include<iostream>
using namespace std;
int getTextLenght(char*);

int GetAllSmallestWords(char*);

bool IsCharLiteral(char);

bool IsCharValid(char);

const int TEXT_MAX_LENGHT = pow(2, 10);

int main() {
	char* inputText = new char[TEXT_MAX_LENGHT]();

	bool isStarted = true;

	while (isStarted) {
		cout << "Input text: ";  cin.getline(inputText, TEXT_MAX_LENGHT);

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		isStarted = false;
	}

	cout << GetAllSmallestWords(inputText);

	delete[] inputText;

	return 0;
}


int GetAllSmallestWords(char* text) {


	int textSize = getTextLenght(text);
	int smallestWordLenght = (int)pow(2, 30);
	int smallestWordCount = 0;

	int currentWordLenght = 0;

	bool isWordValid = true;

	for (int i = 0; i < textSize; i++)
	{
		if (i + 1 == textSize - 1)
			currentWordLenght++;


		//Checks if the char is valid if is not ht word is invalid.
		if (!IsCharValid(text[i])) {
			isWordValid = false;
			continue;
		}


		currentWordLenght++;

		//Checks if the symbol is space \t \n  or is end of the word if is it we are taking the lenght of the symbols before.
		if (text[i + 1] == ' ' || IsCharLiteral(text[i + 1]) || i + 1 == textSize) {

			//If currentWordLenght is smaller than the smallest to now the current will be the smallest.
			//If currentWordLenght is equal to the smallest words the cout for the smallest word will increase.
			if (currentWordLenght < smallestWordLenght && isWordValid && !IsCharLiteral(text[i])) {
				smallestWordLenght = currentWordLenght;
				smallestWordCount = 1;
			}
			else if (currentWordLenght == smallestWordLenght && text[i] != ' ') {
				smallestWordCount++;
			}

			currentWordLenght = 0;
			isWordValid = true;
			continue;

		}

		//Checks the last word.
		if (i + 1 == textSize - 1 && currentWordLenght == smallestWordLenght) {
			smallestWordCount++;
		}

	}
	return smallestWordCount;
}

bool IsCharLiteral(char symbol) {
	switch (symbol) {
	case '\t':
		return true;
	case '\r':
		return true;
	case '\n':
		return true;
	case '\a':
		return true;
	case '\b':
		return true;
	default:
		return false;
	}
}

bool IsCharValid(char symbol) {
	if (symbol < 'A' || (symbol > 'Z' && symbol < 'a') || symbol > 'z') {
		if (symbol != '_' && symbol != '-') {
			return false;
		}
	}

	return true;
}

int getTextLenght(char* text) {
	int lenght = 0;

	while (lenght < TEXT_MAX_LENGHT) {
		if (text[lenght] == '\0')
			break;
		lenght++;
	}
	return lenght;
}