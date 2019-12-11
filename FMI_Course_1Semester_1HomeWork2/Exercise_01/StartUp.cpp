#include <iostream>
using namespace std;

int StartProgram();

int CalculateExcelCol(char* symbols);

const int TEXT_MAX_LENGHT = 4;

const int SUBSTACT_SYMBOLBY_A = 'A' - 1;

int main() {
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

	while (symbols[index] != '\0') {
		if (symbols[index] < 'A' || symbols[index] > 'Z')
			return false;
		index++;
	}

	return true;
}

int StartProgram() {
	char* symbols = new char[4]();

	bool isStarted = true;
	
		do {
			cout << "Enter symbol "; cin.getline(symbols, TEXT_MAX_LENGHT);

			if (!IsTheInputValid(symbols)) {
				cout << "The input is invalid! \r\n";
				continue;
			}

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			cout << CalculateExcelCol(symbols);
			cout << "\r\n";

			isStarted = false;
		} while (isStarted);

	delete[] symbols;

	return 0;
}

int CalculateExcelCol(char* symbols) {
	int firstSymbolInInt = symbols[0] - SUBSTACT_SYMBOLBY_A;

	int column = firstSymbolInInt;

	if (symbols[2] >= 'A' && symbols[2] <= 'Z') {
		column = (firstSymbolInInt * 676) + ((symbols[1] - SUBSTACT_SYMBOLBY_A) * 26) + (symbols[2] - SUBSTACT_SYMBOLBY_A);
	}
	else if (symbols[1] >= 'A' && symbols[1] <= 'Z') {
		column = (firstSymbolInInt * 26) + (symbols[1] - SUBSTACT_SYMBOLBY_A);
	}

	return column;
}