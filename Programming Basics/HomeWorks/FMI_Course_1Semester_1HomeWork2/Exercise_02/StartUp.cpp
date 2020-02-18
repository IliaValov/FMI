/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Iliya Vladislavov Valov
* @idnumber 62483
* @task 02
* @compiler VC
*
*/

#include<iostream>
		
using namespace std;

int getTextLenght(char*);

void GetTextInput(char*);
void EncryptText(char*, int, int);
void GetOtherArgInput(int&, int&);

bool IsInputValid();
bool IsTextValid(char*);

const int TEXT_MAX_LENGHT = 100;

int main() {
	
	char* inputText = new char[TEXT_MAX_LENGHT]();

	int stepsToMoveTheCharToRight = 0;
	
	//This varible will have the value which will be add to every char latter
	int encrypticKey = 0;

	//Gets the text which need to be encrypt.
	GetTextInput(inputText);
	//Gets the encrypt things for the encrypting.
	GetOtherArgInput(encrypticKey, stepsToMoveTheCharToRight);

	//Encrypts the text (: .
	EncryptText(inputText, encrypticKey, stepsToMoveTheCharToRight);

	cout << inputText;

	delete[] inputText;
	return 0;
}


void EncryptText(char* text, int encrypticKey, int stepsToMoveTheCharToRight) {
	//Checks if the text is valid if is not will exit out of the function and leave the texd untouched.
	if (!IsTextValid(text)) {
		return;
	}

	//Get the lenght of the text given by the function.
	int textLenght = getTextLenght(text);

	//Temp array to make the changes on it soo we will not interupt the values in the main array given by the function
	//and get wrong result.
	char* newText = new char[textLenght]();

	//We are interating by the lenght of the array soo we can get every symbols and make the encrypt thing :).
	for (int i = 0; i < textLenght - 1; i++)
	{
		//The new position in the new array where the symbol need to go.
		int newPosition = (i + stepsToMoveTheCharToRight) % (textLenght - 1);

		//Adding the symbol with the encryptkey on it.
		newText[newPosition] = text[i] + encrypticKey;
	}

	//Adding the elements from the temp array to the main array given by the function.
	for (int i = 0; i < textLenght - 1; i++)
	{
		text[i] = newText[i];
	}

	//Adding the terminate 0 at the end of the array so when we are printing it will not get wrong result.
	newText[textLenght - 1] = '\0';

	//Deleting the temp array
	delete[] newText;
}

void GetTextInput(char* inputText) {
	bool isStarted = true;

	//Gets the input text and checks if is valid
	while (isStarted) {
		cout << "Input the text: "; cin.getline(inputText, TEXT_MAX_LENGHT);

		if (!IsInputValid()) {
			continue;
		}

		isStarted = false;
	}
}

void GetOtherArgInput(int& encrypticKey, int& stepsToMoveTheCharToRight) {
	bool isStarted = true;

	//Gets the other arg for the encrypting and checks if they are valid if they ar enot the user need to enter new ones.
	while (isStarted) {

		cout << "M = "; cin >> encrypticKey;
		if (!IsInputValid() || encrypticKey < 0) {
			cout << "Invalid argument for M! \r\n";
			continue;
		}

		cout << "L = "; cin >> stepsToMoveTheCharToRight;
		if (!IsInputValid() || 0 > stepsToMoveTheCharToRight) {
			cout << "Invalid argument for L! \r\n";
			continue;
		}

		isStarted = false;
	}
}

bool IsInputValid() {
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}

	return true;
}

bool IsTextValid(char* text) {
	int testSize = getTextLenght(text);

	for (int i = 0; i < testSize - 1; i++)
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
