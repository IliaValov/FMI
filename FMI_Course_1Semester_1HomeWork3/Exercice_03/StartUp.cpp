/**
*
* Solution to homework assignment 3
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

void DeleteElement(char* arr, int deleteIndex, int numLenght);

bool IsWord(char* word, int length);
bool IsAABWord(char* word, int length);
bool IsDWord(char* word, int IndexOfTheDSymbol, int length);
bool IsCWord(char* word, int IndexOfTheCSymbol, int length);


char* CoppyString(char* arr, int startFrom, int end);

size_t StrLenght(char* firstArr);

int main() {
	const int INPUT_WORD_SIZE = 255;
	int size = 0;

	cout << "Enter size: "; cin >> size;

	bool* isWords = new bool[size];
	char* inputWord = new char[INPUT_WORD_SIZE];



	cout << "Enter words: \r\n";
	cin.ignore();
	for (int i = 0; i < size; i++)
	{

		cin.getline(inputWord, INPUT_WORD_SIZE);
		isWords[i] = IsWord(inputWord, StrLenght(inputWord));

	}

	for (int i = 0; i < size; i++)
	{
		cout << isWords[i] << "\r\n";
	}

	return 0;
}

bool IsWord(char* word, int wordLength) {

	if (word[0] == '\0')
		return true;

	//Searching for specific symbols or combination of them
	for (int i = 0; i < wordLength; i++)
	{

		if (word[i] == 'A' && word[wordLength - 1] == 'B') {
			if (IsAABWord(word, wordLength))
				return true;
		}
		else if (word[i] == 'D') {
			if (IsDWord(word, i, wordLength))
				return true;
		}
		else if (word[i] == 'C') {
			if (IsCWord(word, i, wordLength))
				return true;
		}
	}

	return false;
}

bool IsCWord(char* word, int IndexOfTheCSymbol, int wordLength) {
	//If we found C in the word we divide the string in 2 strings
	//One from the start to the symbol 'C'
	//And the other one from the 'C' + 1 to the end of the string.

	char* leftSide = CoppyString(word, 0, IndexOfTheCSymbol);
	char* rightSide = CoppyString(word, IndexOfTheCSymbol + 1, wordLength);

	//Checking with recursion if the left and right side are valid
	bool isLeftSideValid = IsWord(leftSide, StrLenght(leftSide));
	bool isRightSideValid = IsWord(rightSide, StrLenght(rightSide));

	if (!isLeftSideValid || !isRightSideValid)
		return false;


	delete[] leftSide;
	delete[] rightSide;
	return true;
}

bool IsDWord(char* word, int IndexOfTheDSymbol, int length) {
	//If we found D in the word we divide the string in 2 strings
	//One from the start to the symbol 'D'
	//And the other one from the 'D' + 1 to the end of the string.
	int wordLenght = StrLenght(word);
	int leftSideLenght = IndexOfTheDSymbol;
	int rightSideLenght = wordLenght - (IndexOfTheDSymbol + 1);

	char* leftSide = CoppyString(word, 0, IndexOfTheDSymbol);
	char* rightSide = CoppyString(word, IndexOfTheDSymbol + 1, wordLenght);

	//Checking with recursion if the left and right side are valid and if they are equal.
	bool isLeftSideValid = IsWord(leftSide, StrLenght(leftSide));
	bool isRightSideValid = IsWord(rightSide, StrLenght(rightSide));

	if ((!isLeftSideValid || !isRightSideValid) || (leftSideLenght != rightSideLenght))
		return false;


	for (int i = 0; i < leftSideLenght; i++)
	{
		if (leftSide[i] != rightSide[i]) {
			return false;
		}
	}

	delete[] leftSide;
	delete[] rightSide;
	return true;
}

bool IsAABWord(char* word, int wordLength) {
	//When we find AA.B in the word we delete AA and B from the string.

	if (word[1] != 'A' || word[wordLength - 1] != 'B')
		return false;


	char* tempWord = CoppyString(word, 0, wordLength);
	DeleteElement(tempWord, 0, wordLength);
	DeleteElement(tempWord, 0, wordLength);
	DeleteElement(tempWord, wordLength - 3, wordLength);

	//After the deleting we are checking if the middle part is valid.
	if (!IsWord(tempWord, StrLenght(tempWord)))
		return false;


	delete[] tempWord;
	return true;
}


size_t StrLenght(char* firstArr) {
	size_t index = 0;

	while (firstArr[index++] != '\0');

	return index - 1;
}

char* CoppyString(char* arr, int startFrom, int end) {
	char* result = new char[end + 1];

	if (end - 1 < 0 || startFrom > end - 1) {
		result[0] = '\0';
		return result;
	}

	if (startFrom == end - 1) {
		result[startFrom] = arr[end];
	}

	for (int i = 0; i < end; i++)
	{
		result[i] = arr[i + startFrom];
	}

	result[end] = '\0';

	return result;
}

void DeleteElement(char* arr, int deleteIndex, int numLenght) {

	int counter = deleteIndex;
	for (int i = deleteIndex + 1; i < numLenght; i++)
	{
		arr[i - 1] = arr[i];
		counter++;
	}

	arr[counter] = '\0';
}