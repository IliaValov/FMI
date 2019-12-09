#include<iostream>

#include <regex>

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
	char a[] = { 'a','b' };
	regex reg("(?<=\\s|^)([A-Za-z]+[-]*[_]*[A-Za-z]*)(?=\\s|$)");
	smatch matches;

	while (regex_search(text, reg)) {
		cout << matches.ready() << "\r\n";
	}


	return 0;
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