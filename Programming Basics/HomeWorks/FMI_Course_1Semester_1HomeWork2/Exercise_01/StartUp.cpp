/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Iliya Vladislavov Valov
* @idnumber 62483
* @task 01
* @compiler VC
*
*/


#include <iostream>
using namespace std;

int StartProgram();

int CalculateExcelCol(char* symbols);

const int TEXT_MAX_LENGHT = 4;

const int SUBSTACT_SYMBOLBY_A = 'A' - 1;

int main() {
	//Starts the program and is returning value to check if it ran successfully or now.
	int executedCode = StartProgram();

	if (executedCode == -1) {
		cout << "The program failed! \r\n";
	}
	else
	{
		cout << "The program executed successfully. \r\n";
	}

	return 0;
}

bool IsTheInputValid(char* symbols) {
	int index = 0;

	//Checks if the symbols are not bewtween A and Z if is not the input is invalid
	while (symbols[index] != '\0') {
		if (symbols[index] < 'A' || symbols[index] > 'Z')
			return false;
		index++;
	}

	return true;
}

int StartProgram() {
	//Initialize array with 4 symbols because by condition the max lenght is 3 but we are adding 1 for \0.
	char* symbols = new char[4]();

	//This variable is used for the while to start it and stop it.
	bool isStarted = true;
	
		do {
			cout << "Enter symbol "; cin.getline(symbols, TEXT_MAX_LENGHT);

			//Checks if the input is valid.
			if (!IsTheInputValid(symbols)) {
				cout << "The input is invalid! \r\n";
				continue;
			}

			//Checks if the user entered.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			
			//Calculating the excel symbols and print them.
			cout << CalculateExcelCol(symbols);
			cout << "\r\n";

			isStarted = false;
		} while (isStarted);

		
	delete[] symbols;

	return 0;
}

int CalculateExcelCol(char* symbols) {
	//Converting the symbol to int value and substact 'A' from the symbol to get 1 to 26 in this case the number will represent every alphabet.
	int firstSymbolInInt = symbols[0] - SUBSTACT_SYMBOLBY_A;

	//column is the result from the calculating
	int column = firstSymbolInInt;

	//If the symbols are 3 first symbol will multiplie by 26 on power 2 and next symbol will be multiplie by 26 only and all 3 will be agregate.
	if (symbols[2] >= 'A' && symbols[2] <= 'Z') {
	
		column = (firstSymbolInInt * pow(26,2)) + ((symbols[1] - SUBSTACT_SYMBOLBY_A) * 26) + (symbols[2] - SUBSTACT_SYMBOLBY_A);
	}

	//Same like above but with 2 symbols 
	else if (symbols[1] >= 'A' && symbols[1] <= 'Z') {
		column = (firstSymbolInInt * 26) + (symbols[1] - SUBSTACT_SYMBOLBY_A);
	}

	return column;
}