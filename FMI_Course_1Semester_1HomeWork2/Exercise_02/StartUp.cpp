#include<iostream>

using namespace std;

void EncryptText(char*, int, int);
int getTextLenght(char*);
bool IsTextValid(char*);

int TEXT_MAX_LENGHT = 100;

//TODO VALIDATION OF THE SYMBOLS 32-126

int main() {

	char* inputText = new char[TEXT_MAX_LENGHT]();

	int stepsToMoveTheCharToRight = 0;
	int encrypticKey = 0;

	cout << "Input the text: "; cin.getline(inputText, TEXT_MAX_LENGHT);

	cout << "M = "; cin >> encrypticKey;
	cout << "L = "; cin >> stepsToMoveTheCharToRight;

	EncryptText(inputText, encrypticKey, stepsToMoveTheCharToRight);

	cout << inputText;

	delete[] inputText;
	return 0;
}


void EncryptText(char* text, int encrypticKey, int stepsToMoveTheCharToRight) {
	if (!IsTextValid(text)) {
		return;
	}

	int textLenght = getTextLenght(text);

	char* newText = new char[textLenght]();

	for (int i = 0; i < textLenght - 1; i++)
	{
		int newPosition = (i + stepsToMoveTheCharToRight) % (textLenght - 1);

		newText[newPosition] = text[i] + encrypticKey;
	}

	for (int i = 0; i < textLenght - 1; i++)
	{
		text[i] = newText[i];
	}

	newText[textLenght - 1] = '\0';

	delete[] newText;
}

bool IsTextValid(char* text) {
	for (int i = 0; i < getTextLenght(text) - 1; i++)
	{
		if (text[i] < 32 || text[i] >= 126) {
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

	return ++lenght;
}
