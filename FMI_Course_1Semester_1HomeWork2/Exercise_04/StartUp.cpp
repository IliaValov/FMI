#include<iostream>

using namespace std;

int getTextLenght(char*);

int GetAllSmallestWords(char*);

bool IsCharValid(char);

const int TEXT_MAX_LENGHT = pow(2, 10);

int main() {
	char* inputText = new char[TEXT_MAX_LENGHT]();

	cout << "Input text: ";  cin.getline(inputText, TEXT_MAX_LENGHT);

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
		
		if (!IsCharValid(text[i])) {
			isWordValid = false;
			continue;
		}

		currentWordLenght++;
	
		if (text[i + 1] == ' ' || text[i + 1] == (int)'\t' || text[i + 1] == (int)'\n' || i + 1 == textSize) {
			if (currentWordLenght < smallestWordLenght && isWordValid && text[i] != ' ') {
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

		if (i + 1 == textSize - 1 && currentWordLenght == smallestWordLenght) {
			smallestWordCount++;
		}
	}

	return smallestWordCount;
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