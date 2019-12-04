#include <iostream>
using namespace std;

int TEXT_MAX_LENGHT = 4;

int main() {
	const int SUBSTACT_SYMBOLBY_A = 'A' - 1;

	char* symbols = new char[4]();

	cout << "Enter symbol "; cin.getline(symbols, TEXT_MAX_LENGHT);

	int firstSymbolInInt = symbols[0] - SUBSTACT_SYMBOLBY_A ;

	int column = firstSymbolInInt;

	if (symbols[2] >= 'A' && symbols[2] <= 'Z') {
		column =  (firstSymbolInInt * 676)+ ((symbols[1] - SUBSTACT_SYMBOLBY_A) * 26)  + ( symbols[2] - SUBSTACT_SYMBOLBY_A);
	}
	else if (symbols[1] >= 'A' && symbols[1] <= 'Z') {
		column = (firstSymbolInInt * 26) + (symbols[1] - SUBSTACT_SYMBOLBY_A);
	}

	cout << column;

	delete[] symbols;
	return 0;
}