#include<iostream>

using namespace std;

void GetLeftSightOfIndex(char* word, char* result, int index);
void GetRightSightOfIndex(char* word, char* result, int index);

bool IsWord(char* word);

bool HasDWord(char* word, int indexOfTheDSymbol);
bool IsValidDWord(char* leftSideOfTheD, char* rightSideOfTheD);

bool HasCWord(char* word, int IndexOfTheCSymbol);

int StrLenght(char* firstArr);


int main() {
	char* inputWord = new char[255];

	cin.getline(inputWord, 255);

	cout << IsWord(inputWord);


	return 0;
}

bool IsWord(char* word) {
	for (int i = 0; i < StrLenght(word); i++)
	{
		if (word[i] == 'D') {
			if (HasDWord(word, i))
				return true;
		}
		if (word[i] == 'C')
		{
			if (HasCWord(word, i))
				return true;
		}
	}

	return false;
}

bool HasCWord(char* word, int IndexOfTheCSymbol) {
	int leftSightOfTheCLenght = IndexOfTheCSymbol;
	int rightSightOfTheCLenght = (StrLenght(word) - 1) - IndexOfTheCSymbol;


	if (leftSightOfTheCLenght == 0 || rightSightOfTheCLenght == 0 || leftSightOfTheCLenght + rightSightOfTheCLenght > 64) {
		return false;
	}

	return true;
}

bool HasDWord(char* word, int indexOfTheDSymbol) {
	int leftSightOfTheDLenght = indexOfTheDSymbol + 1;
	int rightSightOfTheDLenght = StrLenght(word) - indexOfTheDSymbol;

	char* leftSightOfTheD = new char[leftSightOfTheDLenght];
	char* rightSightOfTheD = new char[rightSightOfTheDLenght];

	rightSightOfTheD[rightSightOfTheDLenght - 1] = '\0';
	leftSightOfTheD[leftSightOfTheDLenght - 1] = '\0';

	if (leftSightOfTheDLenght == 0 || rightSightOfTheDLenght == 0 || rightSightOfTheDLenght * 2 > 64) {
		return false;
	}

	GetLeftSightOfIndex(word, leftSightOfTheD, indexOfTheDSymbol - 1);
	GetRightSightOfIndex(word, rightSightOfTheD, indexOfTheDSymbol + 1);

	if (!IsValidDWord(leftSightOfTheD, rightSightOfTheD))
		return false;

	return true;
}

bool IsValidDWord(char* leftSideOfTheD, char* rightSideOfTheD) {
	int leftSightLenght = StrLenght(leftSideOfTheD);
	int rightSightLenght = StrLenght(rightSideOfTheD);

	if (leftSightLenght != rightSightLenght)
		return false;

	for (int i = 0; i < leftSightLenght; i++)
	{
		if (leftSideOfTheD[i] != rightSideOfTheD[i]) {
			return false;
		}
	}

	return true;
}

void GetRightSightOfIndex(char* word, char* result, int index) {
	for (int i = index; i < StrLenght(word); i++)
	{
		result[i - index] = word[i];
	}
}

void GetLeftSightOfIndex(char* word, char* result, int index) {
	for (int i = index; i >= 0; i--)
	{
		result[i] = word[i];
	}
}

int StrLenght(char* firstArr) {
	int index = 0;

	while (firstArr[index++] != '\0');

	return index - 1;
}