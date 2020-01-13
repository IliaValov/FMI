/**
*
* Solution to homework assignment 3
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
			else if (!inputNum2.isPositive)
				inputNum2.isPositive = true;
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

	delete[] resultNum.number;
	delete[] inputNum1.number;
	delete[] inputNum2.number;
}

Number SubstactBigNumber(Number firstNum, Number secondNum) {
	const int DIFFRENCE = 10;

	Number resultNum;
	delete[] resultNum.number;

	//Checks if the both nums are negative
	//If they are we will gather them and the result will be negative
	if (!firstNum.isPositive && !secondNum.isPositive) {
		resultNum = GatherBigNumbers(firstNum, secondNum);
		resultNum.isPositive = false;
		return resultNum;
	}

	//Checks if the both nums are positive
	//If they are we will gather them and the result will be positive
	if (firstNum.isPositive && secondNum.isPositive) {
		resultNum = GatherBigNumbers(firstNum, secondNum);
		resultNum.isPositive = true;
		return resultNum;
	}

	int firstNumLenght = (int)StrLenght(firstNum.number);
	int secondNumLenght = (int)StrLenght(secondNum.number);

	int biggerNumLenght = firstNumLenght;
	int smallerNumLenght = secondNumLenght;

	resultNum.isPositive = firstNum.isPositive;

	bool needToBeSwapped = false;

	//Checking which num is bigger
	if (firstNumLenght == secondNumLenght) {
		for (int i = firstNumLenght - 1; i >= 0; i--)
		{
			if (firstNum.number[i] < secondNum.number[i])
				needToBeSwapped = true;
			else if (firstNum.number[i] > secondNum.number[i])
				needToBeSwapped = false;
		}
	}

	//Swap the numbers if the secondone is bigger or they need to be swap because of the for cycle above.
	if (firstNumLenght < smallerNumLenght || needToBeSwapped) {
		biggerNumLenght = secondNumLenght;
		smallerNumLenght = firstNumLenght;
		swap(firstNum, secondNum);
		resultNum.isPositive = firstNum.isPositive;
	}

	resultNum.number = new char[biggerNumLenght + 2];

	int smallerNumIndex = smallerNumLenght - 1;

	//We are iterating by biggernum 
	for (int i = biggerNumLenght - 1; i >= 0; i--)
	{

		int digitFromBiggerNum = ConvertSymbolToDecimal(firstNum.number[i]);

		int result = digitFromBiggerNum;

		//Checks if the small num has more digits.
		if (smallerNumIndex >= 0) {
			int digitFromSmallerNum = ConvertSymbolToDecimal(secondNum.number[smallerNumIndex--]);

			if (result - digitFromSmallerNum < 0 && i > 0) {


				result = (result + DIFFRENCE) - digitFromSmallerNum;


				for (int j = i - 1; j >= 0; j--)
				{
					//If we find digit bigger than 0 we will substract 1 of it.
					if (firstNum.number[j] > '0') {
						firstNum.number[j]--;
						break;
					}
					else {
						//While searching for digit bigger than 10 we are placing on every 0 9 so when it finds bigger digit it will simulate taking 1 of every digit and passing it to right.
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

	while (resultNum.number[0] == '0' && resultNum.number[1] != '\0') {

		ShiftNumberToLeft(resultNum.number, biggerNumLenght);
	}

	return resultNum;
}

Number GatherBigNumbers(Number firstNum, Number secondNum) {
	const int DIFFRENCE = 10;
	
	Number resultNum;

	delete[] resultNum.number;
	//Checking if one of the number is negative to substract them.
	if (!firstNum.isPositive && secondNum.isPositive || firstNum.isPositive && !secondNum.isPositive) {
		return SubstactBigNumber(firstNum, secondNum);
	}

	int firstNumLenght = (int)StrLenght(firstNum.number);
	int secondNumLenght = (int)StrLenght(secondNum.number);

	int biggerNumLenght = firstNumLenght;
	int smallerNumLenght = secondNumLenght;

	//Checking if the second num is bigger to swap them.
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

		//Checks if the smaller num has digits.
		if (smallerNumIndex >= 0) {
			int digitFromSmallerNum = ConvertSymbolToDecimal(secondNum.number[smallerNumIndex--]);

			result += digitFromSmallerNum;
		}

		if (remainder > 0) {
			remainder = 0;
		}

		if (result >= DIFFRENCE) {
			result -= DIFFRENCE;
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

	while (resultNum.number[0] == '0' && resultNum.number[1] != '\0') {

		ShiftNumberToLeft(resultNum.number, biggerNumLenght);
	}

	return resultNum;
}

Number MultiplyBigNumbers(Number firstNum, Number secondNum) {
	Number resultNum;
	delete[] resultNum.number;

	int firstNumLenght = (int)StrLenght(firstNum.number);
	int secondNumLenght = (int)StrLenght(secondNum.number);
	
	//Max num which can be make by multiply 2 nums is the sum of there digit length
	//if we have 33*444 '33' has 2 digits and '444' has 4 we sum there length and this is the max possible number.
	int resultNumLenght = firstNumLenght + secondNumLenght;

	resultNum.number = new char[resultNumLenght + 1];

	resultNum.number[0] = '0';
	resultNum.number[1] = '\0';

	//With the digit from one of the numbers we are multiplying it with every digit from the other num
	//And all of that we sum it.
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

			//Adding 0 behind the result.
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

			delete[] currentNum.number;
		}
	}

	if ((!firstNum.isPositive && secondNum.isPositive) || (firstNum.isPositive && !secondNum.isPositive))
		resultNum.isPositive = false;

	while (resultNum.number[0] == '0' && resultNum.number[1] != '\0') {

		ShiftNumberToLeft(resultNum.number, resultNumLenght);
	}

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

	//Checks for valid operators
	if ((input[2] != '+' && input[2] != '-' && input[2] != '*') || input[3] != ' ' || input[3] == '\0')
		return false;

	//Taking the operator from the input.
	op = input[2];

	if (input[4] == ' ' || '\0')
		return false;

	//If we find - infront of a num we add 1 to the variable so we can use it latter to substract the - from the size of the array.
	int removeIndex = 0;

	//Taking the firstNum from the input
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


		number1.number[i - (2 + removeIndex + 2)] = input[i];

	}

	if (input[startFrom - 1] != ' ' || input[startFrom - 1] == '\0')
		return false;

	removeIndex = 0;

	//Taking the secondNum from the input

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

		if (input[i] == '-') {
			number2.isPositive = false;
			removeIndex++;
			continue;
		}

		if (input[i] < '0' || input[i] > '9')
			return false;

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