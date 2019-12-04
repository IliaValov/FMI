#include<iostream>

using namespace std;

int getTextLenght(char*);

int GetAllSmallestWords(char*);

int TEXT_MAX_LENGHT = pow(2, 10);

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

	for (int i = 0; i < textSize; i++)
	{
		if (i + 1 == textSize - 1) 
			currentWordLenght++;
			
		

		if (text[i] == ' ') {
			if (currentWordLenght < smallestWordLenght) {
				smallestWordLenght = currentWordLenght;
				smallestWordCount = 1;
			}
			else if (currentWordLenght == smallestWordLenght) {
				smallestWordCount++;
			}

			currentWordLenght = 0;
			continue;
		}

		currentWordLenght++;

		if (i + 1 == textSize - 1 && currentWordLenght == smallestWordLenght) {
			smallestWordCount++;
		}
	}

	return smallestWordCount;
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