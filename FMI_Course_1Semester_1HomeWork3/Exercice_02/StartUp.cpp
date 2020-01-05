#include<iostream>

using namespace std;

struct Number {
	char* number = new char[1];
	bool isPositive = true;
};

void ShiftNumberToRight(char* number, int lenght);
void ShiftNumberToLeft(char* number, int numLenght);

bool GetInputForNumber(char& op, Number& number1, Number& number2);

char ConvertDecimalToSymbol(int num);

int ConvertSymbolToDecimal(char num);
size_t StrLenght(char* firstArr);

Number SubstactBigNumber(Number, Number);
Number GatherBigNumbers(Number, Number);

Number MultiplyBigNumbers(Number biggerNum, Number smallerNum);

int main() {
	char inputOperator = ' ';

	Number inputNum1;
	Number inputNum2;
	Number resultNum;

	while (true) {
		if (!GetInputForNumber(inputOperator, inputNum1, inputNum2)) {
			cout << "Invalid input";
			continue;
		}

		switch (inputOperator)
		{
		case '+':
			resultNum = GatherBigNumbers(inputNum1, inputNum2);
			break;
		case '-':
			if (inputNum2.isPositive)
				inputNum2.isPositive = false;
			resultNum = SubstactBigNumber(inputNum1, inputNum2);
			break;
		case '*':
			resultNum = MultiplyBigNumbers(inputNum1, inputNum2);
			break;
		default:
			cout << "Invalid operator";
			continue;
		}

		break;
	}

	if (!resultNum.isPositive) {
		cout << '-';
	}

	cout << resultNum.number;
}

Number SubstactBigNumber(Number firstNum, Number secondNum) {
	Number resultNum;

	if (!firstNum.isPositive && !secondNum.isPositive) {
		resultNum = GatherBigNumbers(firstNum, secondNum);
		resultNum.isPositive = false;
		return resultNum;
	}

	int firstNumLenght = (int)StrLenght(firstNum.number);
	int secondNumLenght = (int)StrLenght(secondNum.number);

	int biggerNumLenght = firstNumLenght;
	int smallerNumLenght = secondNumLenght;

	resultNum.isPositive = firstNum.isPositive;

	bool needToBeSwapped = false;

	if (firstNumLenght == secondNumLenght) {
		for (int i = firstNumLenght - 1; i >= 0; i--)
		{
			if (firstNum.number[i] < secondNum.number[i])
				needToBeSwapped = true;
			else if (firstNum.number[i] > secondNum.number[i])
				needToBeSwapped = false;
		}
	}

	if (firstNumLenght < smallerNumLenght || needToBeSwapped) {
		biggerNumLenght = secondNumLenght;
		smallerNumLenght = firstNumLenght;
		swap(firstNum, secondNum);
		resultNum.isPositive = firstNum.isPositive;
	}

	resultNum.number = new char[biggerNumLenght + 2];

	int smallerNumIndex = smallerNumLenght - 1;

	for (int i = biggerNumLenght - 1; i >= 0; i--)
	{
		int digitFromBiggerNum = ConvertSymbolToDecimal(firstNum.number[i]);

		int result = digitFromBiggerNum;

		if (smallerNumIndex >= 0) {
			int digitFromSmallerNum = ConvertSymbolToDecimal(secondNum.number[smallerNumIndex--]);

			if (result - digitFromSmallerNum < 0 && i > 0) {

				result = (result + 10) - digitFromSmallerNum;

				for (int j = i - 1; j >= 0; j--)
				{
					if (firstNum.number[j] > '0') {
						firstNum.number[j]--;
						break;
					}
					else {
						firstNum.number[j] = '9';
					}
				}
			}
			else {
				result = abs(result - digitFromSmallerNum);
			}
		}

		resultNum.number[i] = ConvertDecimalToSymbol(result);

	}

	resultNum.number[biggerNumLenght] = '\0';

	for (int i = 0; i < biggerNumLenght; i++)
	{
		if (resultNum.number[i + 1] == '\0') {
			break;
		}

		if (resultNum.number[i] == '0') {
			ShiftNumberToLeft(resultNum.number, biggerNumLenght);
		}
		else if (resultNum.number[i] > '0') {
			break;
		}
	}

	return resultNum;
}

Number GatherBigNumbers(Number firstNum, Number secondNum) {
	Number resultNum;

	if (!firstNum.isPositive && secondNum.isPositive || firstNum.isPositive && !secondNum.isPositive) {
		return SubstactBigNumber(firstNum, secondNum);
	}

	int firstNumLenght = (int)StrLenght(firstNum.number);
	int secondNumLenght = (int)StrLenght(secondNum.number);

	int biggerNumLenght = firstNumLenght;
	int smallerNumLenght = secondNumLenght;

	if (firstNumLenght < secondNumLenght) {
		swap(firstNum, secondNum);
		swap(firstNumLenght, secondNumLenght);

		biggerNumLenght = firstNumLenght;
		smallerNumLenght = secondNumLenght;
	}

	resultNum.number = new char[biggerNumLenght + 2];

	int remainder = 0;

	int end = biggerNumLenght - smallerNumLenght;
	int smallerNumIndex = smallerNumLenght - 1;

	for (int i = biggerNumLenght - 1; i >= 0; i--)
	{
		int digitFromBigNum = ConvertSymbolToDecimal(firstNum.number[i]);


		int result = digitFromBigNum + remainder;

		if (smallerNumIndex >= 0) {
			int digitFromSmallerNum = ConvertSymbolToDecimal(secondNum.number[smallerNumIndex--]);

			result += digitFromSmallerNum;
		}

		if (remainder > 0) {
			remainder = 0;
		}

		if (result > 9) {
			result -= 10;
			remainder++;
		}

		resultNum.number[i] = ConvertDecimalToSymbol(result);
	}

	if (remainder > 0) {
		ShiftNumberToRight(resultNum.number, biggerNumLenght);
		resultNum.number[0] = ConvertDecimalToSymbol(remainder);
	}
	else {
		resultNum.number[biggerNumLenght] = '\0';
	}

	return resultNum;
}

Number MultiplyBigNumbers(Number firstNum, Number secondNum) {
	Number resultNum;

	int firstNumLenght = (int)StrLenght(firstNum.number);
	int secondNumLenght = (int)StrLenght(secondNum.number);

	int resultNumLenght = firstNumLenght + secondNumLenght;

	resultNum.number = new char[resultNumLenght + 1];

	resultNum.number[0] = '0';
	resultNum.number[1] = '\0';

	for (int f = firstNumLenght - 1; f >= 0; f--)
	{
		
		for (int s = secondNumLenght - 1; s >= 0; s--)
		{
			Number currentNum;
			currentNum.number = new char[(3) + (firstNumLenght + secondNumLenght)];
			int currentNumLenght = 0;

			int multiplyNumFromBothNums =
				ConvertSymbolToDecimal(firstNum.number[f]) * ConvertSymbolToDecimal(secondNum.number[s]);

			if (multiplyNumFromBothNums >= 10)
			{
				for (int i = 1; i >= 0; i--)
				{
					currentNum.number[i] = ConvertDecimalToSymbol(multiplyNumFromBothNums % 10);
					multiplyNumFromBothNums /= 10;
				}
				currentNum.number[2] = '\0';
				currentNumLenght = 2;
			}
			else {
				currentNum.number[0] = ConvertDecimalToSymbol(multiplyNumFromBothNums);
				currentNum.number[1] = '\0';
				currentNumLenght = 1;
			}

			int index = currentNumLenght;

			for (int i = 0; i < (secondNumLenght - 1 - s); i++)
			{
				currentNum.number[index++] = '0';
				
			}

			currentNum.number[index] = '\0';

			for (int i = 0; i < (firstNumLenght - 1 - f); i++)
			{
				currentNum.number[index++] = '0';
			}

			currentNum.number[index] = '\0';

			resultNum = GatherBigNumbers(resultNum, currentNum);
			//CANT DELETE  CURRENTNUM
		}
	}

	if ((!firstNum.isPositive && secondNum.isPositive) || (firstNum.isPositive && !secondNum.isPositive))
		resultNum.isPositive = false;

	return resultNum;
}

int ConvertSymbolToDecimal(char num) {
	return num - '0';
}

char ConvertDecimalToSymbol(int num) {
	return num + '0';
}

bool GetInputForNumber(char& op, Number& number1, Number& number2) {
	char* input = new char[408];
	number1.number = new char[102];

	number2.number = new char[102];

	cin.getline(input, 408);

	if (input[0] != '<' || input[1] != '<')
		return false;

	int inputLenght = (int)StrLenght(input);

	int startFrom = 0;

	if ((input[2] != '+' && input[2] != '-' && input[2] != '*') || input[3] != ' ' || input[3] == '\0')
		return false;


	op = input[2];

	if (input[4] == ' ' || '\0')
		return false;

	int removeIndex = 0;

	for (int i = 4; i < inputLenght; i++)
	{
		if (input[i] == ' ') {
			startFrom = i + 1;
			number1.number[i - (2 + removeIndex + 2)] = '\0';
			break;
		}

		if (input[i] == '-') {
			number1.isPositive = false;
			removeIndex++;
			continue;
		}

		if (input[i] < '0' || input[i] > '9')
			return false;

		//TODO ADD VALIDATION;



		number1.number[i - (2 + removeIndex + 2)] = input[i];

	}

	if (input[startFrom - 1] != ' ' || input[startFrom - 1] == '\0')
		return false;

	removeIndex = 0;


	for (int i = startFrom; i < inputLenght; i++)
	{
		if (i + 1 == inputLenght) {
			return false;
		}

		if (input[i] == '>' && i > startFrom) {
			if (input[i + 1] != '>') {
				return false;
			}
			break;
		}

		if (input[i] < '0' || input[i] > '9')
			return false;

		//TODO ADD VALIDATION;
		if (input[i] == '-') {
			number2.isPositive = false;
			removeIndex++;
			continue;
		}

		number2.number[i - (startFrom + removeIndex)] = input[i];
	}

	number2.number[inputLenght - (startFrom + removeIndex + 2)] = '\0';

	return true;

}

size_t StrLenght(char* firstArr) {
	size_t index = 0;

	while (firstArr[index++] != '\0');

	return index - 1;
}

void ShiftNumberToLeft(char* number, int numLenght) {

	int counter = 0;
	for (int i = 1; i < numLenght; i++)
	{
		number[i - 1] = number[i];
		counter++;
	}

	number[counter] = '\0';
}

void ShiftNumberToRight(char* number, int lenght) {

	for (int i = lenght - 1; i >= 0; i--)
	{
		number[i + 1] = number[i];
	}
	number[lenght + 1] = '\0';

}