#include<iostream>

using namespace std;

void DeleteElement(char* arr, int deleteIndex, int numLenght);

bool IsWord(char* word);
bool IsAABWord(char* word);
bool IsDWord(char* word, int IndexOfTheDSymbol);
bool IsCWord(char* word, int IndexOfTheCSymbol);


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
		isWords[i] = IsWord(inputWord);

	}

	for (int i = 0; i < size; i++)
	{
		cout << isWords[i] << "\r\n";
	}

	return 0;
}

bool IsWord(char* word) {
	int wordLenght = StrLenght(word);

	if (word[0] == '\0')
		return true;

	for (int i = 0; i < wordLenght; i++)
	{

		if (word[i] == 'A' && word[wordLenght - 1] == 'B') {
			if (IsAABWord(word))
				return true;
		}
		else if (word[i] == 'D') {
			if (IsDWord(word, i))
				return true;
		}
		else if (word[i] == 'C') {
			if (IsCWord(word, i))
				return true;
		}
	}

	return false;
}

bool IsCWord(char* word, int IndexOfTheCSymbol) {
	int wordLenght = StrLenght(word);

	char* leftSide = CoppyString(word, 0, IndexOfTheCSymbol);
	char* rightSide = CoppyString(word, IndexOfTheCSymbol + 1, wordLenght);

	bool isLeftSideValid = IsWord(leftSide);
	bool isRightSideValid = IsWord(rightSide);

	if (!isLeftSideValid || !isRightSideValid)
		return false;


	delete[] leftSide;
	delete[] rightSide;
	return true;
}

bool IsDWord(char* word, int IndexOfTheDSymbol) {

	int wordLenght = StrLenght(word);
	int leftSideLenght = IndexOfTheDSymbol;
	int rightSideLenght = wordLenght - (IndexOfTheDSymbol + 1);

	char* leftSide = CoppyString(word, 0, IndexOfTheDSymbol);
	char* rightSide = CoppyString(word, IndexOfTheDSymbol + 1, wordLenght);

	bool isLeftSideValid = IsWord(leftSide);
	bool isRightSideValid = IsWord(rightSide);

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

bool IsAABWord(char* word) {
	int wordLenght = StrLenght(word);

	if (word[1] != 'A' || word[wordLenght - 1] != 'B')
		return false;


	char* tempWord = CoppyString(word, 0, wordLenght);
	DeleteElement(tempWord, 0, wordLenght);
	DeleteElement(tempWord, 0, wordLenght);
	DeleteElement(tempWord, wordLenght - 3, wordLenght);

	if (!IsWord(tempWord))
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