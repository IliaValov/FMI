#include<iostream>

using namespace std;

void RecursiveAddingRemainder(char* number, int remainder, int index);

char ConvertDecimalToSymbol(int num);

int ConvertSymbolToDecimal(char num);
int StrLenght(char* firstArr);

int MinLenght(char* firstArr, char* secondArr);
int MaxLenght(char* firstArr, char* secondArr);

char* GatherTwoBigNumber(char* firstNum, char* secondNum);

int main() {
	char inputOperator = ' ';

	char* inputNumber1 = new char[101];

	char* inputNumber2 = new char[101];

	cin >> inputOperator;
	cin >> inputNumber1;
	cin >> inputNumber2;

	char* resultNum = GatherTwoBigNumber(inputNumber1, inputNumber2);

	cout << resultNum;
	

}

char* GatherTwoBigNumber(char* firstNum, char* secondNum) {
	int remainder = 0;

	char* resultNum = new char[(MaxLenght(firstNum, secondNum) + 2)];

	for (int i = 0; i < MinLenght(firstNum, secondNum); i++)
	{
		int result = ConvertSymbolToDecimal(firstNum[i]) + ConvertSymbolToDecimal(secondNum[i]);

		if (remainder > 0) {
			result += remainder;
			remainder = 0;
		}

		if (result > 9) {
			result -= 9;
			remainder++;
		}

		resultNum[i] = ConvertDecimalToSymbol(result);
	}

	if (remainder > 0) {
		RecursiveAddingRemainder(resultNum, remainder, MinLenght(firstNum, secondNum));
	}

	resultNum[MaxLenght(firstNum, secondNum) + 1] = '\0';

	return resultNum;
}

void RecursiveAddingRemainder(char* number, int remainder, int index) {
	int currentNum = ConvertSymbolToDecimal(number[index]) + remainder;

	if (currentNum > 9) {
		currentNum -= 9;
		number[index] = currentNum;
		RecursiveAddingRemainder(number, remainder, index + 1);
	}
	else {
		number[index] = currentNum;
	}
}

int ConvertSymbolToDecimal(char num) {
	return num - '0';
}

char ConvertDecimalToSymbol(int num) {
	return num + '0';
}

int MinLenght(char* firstArr, char* secondArr) {
	int firstArrLenght = StrLenght(firstArr);
	int secondArrLenght = StrLenght(secondArr);

	if (firstArrLenght < secondArrLenght)
		return firstArrLenght;

	return secondArrLenght;
}

int MaxLenght(char* firstArr, char* secondArr) {
	int firstArrLenght = StrLenght(firstArr);
	int secondArrLenght = StrLenght(secondArr);

	if (firstArrLenght > secondArrLenght)
		return firstArrLenght;

	return secondArrLenght;
}

int StrLenght(char* firstArr) {
	int index = 0;

	while (firstArr[index++] != '\0');

	return index - 1;
}