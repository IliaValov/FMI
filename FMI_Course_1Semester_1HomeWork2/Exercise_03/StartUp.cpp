#include<iostream>

using namespace std;

void PrintTheSmallestArray(char* firstText, char* secondText);
void PrintTheArrayUntilReachesTheLeght(char* text, int size);

int getTextLenght(char*);

int TEXT_MAX_LENGHT = pow(2, 10);

int main() {
	char* firstText = new char[TEXT_MAX_LENGHT]();
	char* secondText = new char[TEXT_MAX_LENGHT]();

	cout << "First text: ";  cin.getline(firstText, TEXT_MAX_LENGHT);
	cout << "Second text: ";  cin.getline(secondText, TEXT_MAX_LENGHT);

	PrintTheSmallestArray(firstText, secondText);

	delete[] firstText;
	delete[] secondText;

	return 0;
}

void PrintTheSmallestArray(char* firstText, char* secondText) {
	int firstTextLenght = getTextLenght(firstText);
	int secondTextLenght = getTextLenght(secondText);

	if (firstTextLenght >= secondTextLenght) {
		PrintTheArrayUntilReachesTheLeght(secondText, firstTextLenght);
		return;
	}

	PrintTheArrayUntilReachesTheLeght(firstText, secondTextLenght);
}

void PrintTheArrayUntilReachesTheLeght(char* text, int size) {
	int textSize = getTextLenght(text);

	for (int i = 0; i < size; i++)
	{
		cout << text[i % textSize];
	}
	cout << "\n";
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