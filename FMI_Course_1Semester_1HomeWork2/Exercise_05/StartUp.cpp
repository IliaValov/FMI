/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Iliya Vladislavov Valov
* @idnumber 62483
* @task 05
* @compiler VC
*
*/

#include<iostream>

using namespace std;

void GetInputForMatrix(int**, int);
void GetInput(int& arg);
void PrintMatrix(int**, int);
void DeleteMatrix(int**, int);
void swapMatrixRows(int**, int, int);
void OverwriteMatrixes(int**, int**, int);
void SortMatrixByRowAndFirstCol(int**, int);

bool IsInputValid();
bool IsThereValidDiagonal(int**, int, int);

int main() {
	int matrixSize = 0;

	GetInput(matrixSize);

	int** matrix = new int* [matrixSize];

	//Gets the input for the matrix
	GetInputForMatrix(matrix, matrixSize);

	//Making temp matrix if there is no valid diagonal to print the older version
	int** tempMatrix = new int* [matrixSize];
	OverwriteMatrixes(matrix, tempMatrix, matrixSize);

	//Sorting the matrix soo we will have bigger chance to find diagonal by less iterations.
	SortMatrixByRowAndFirstCol(matrix, matrixSize);

	//Checking if the matrix diagonal is valid or not
	//If it is we will print the matrix
	//If it isn't we will print the older version(the temp matrix).
	if (IsThereValidDiagonal(matrix, matrixSize, 0)) {
		PrintMatrix(matrix, matrixSize);
	}
	else {
		PrintMatrix(tempMatrix, matrixSize);
	}

	DeleteMatrix(matrix, matrixSize);
	DeleteMatrix(tempMatrix, matrixSize);

	return 0;
}

bool IsThereValidDiagonal(int** matrix, int size, int startFrom) {
	bool IsTheDiagonalValid = true;

	int smallestRowOnCol = startFrom;

	int col = startFrom;

	for (int i = startFrom; i < size; i++)
	{
		//Checks if we are on the first row
		if (startFrom == 0) {

			//Swaping current row with i row.
			swapMatrixRows(matrix, startFrom, i);
			//Recursive entering the same function we will give next row.
			IsTheDiagonalValid = IsThereValidDiagonal(matrix, size, startFrom + 1);
			if (IsTheDiagonalValid) {
				return IsTheDiagonalValid;
			}
			else {
				//If the function return false we are returning the matrix to it's old condition and trying with another row.
				swapMatrixRows(matrix, startFrom, i);
			}

		}
		else if (startFrom > 0) {
			
			int currentDiagonalElement = matrix[i][col];
			int previousDiagonalElement = matrix[startFrom - 1][col - 1];

			//Checking if the element given row col is bigger than the element from row -1 and col - 1. or previous element in the diagonal.
			if (currentDiagonalElement >= previousDiagonalElement) {

				
				swapMatrixRows(matrix, startFrom, i);
				//Recursive entering the function to sort the other rows and checks if the diagonal is still valid.
				//If the diagonal is invalid and the function returns false we will return the matrix to it's previous condition.
				IsTheDiagonalValid = IsThereValidDiagonal(matrix, size, startFrom + 1);
				if (IsTheDiagonalValid) {
					return IsTheDiagonalValid;
				}
				else {
					swapMatrixRows(matrix, startFrom, i);
				}
			}
		}

		//If the for cicle finishes and there is no valid diagonal the function will return false.
		if (i >= size - 1) {
			IsTheDiagonalValid = false;
		}
	}

	return IsTheDiagonalValid;
}

void SortMatrixByRowAndFirstCol(int** matrix, int size) {
	for (int i = 0; i < size; i++)
	{
		int smallestElementInIndex = i;
		for (int j = i; j < size; j++)
		{
			if (matrix[smallestElementInIndex][0] > matrix[j][0]) {
				smallestElementInIndex = j;
			}
		}
		swapMatrixRows(matrix, i, smallestElementInIndex);
	}
}

void OverwriteMatrixes(int** firstMatrix, int** secondMatrix, int size) {

	for (int row = 0; row < size; row++)
	{
		secondMatrix[row] = new int[size];
		for (int col = 0; col < size; col++)
		{
			secondMatrix[row][col] = firstMatrix[row][col];
		}
	}
}

void GetInputForMatrix(int** matrix, int size) {
	
	bool isStarted = true;

	while (isStarted) {
	
		bool isInputValid = true;
	
		cout << "Enter " << size * size << " elements for the matrix \r\n";
		
		for (int row = 0; row < size; row++)
		{
			matrix[row] = new int[size];
			for (int col = 0; col < size; col++)
			{
				int element = 0;
				cin >> element;
				isInputValid = IsInputValid();
				if (!isInputValid)
					break;


				matrix[row][col] = element;
			}
		
			if (!isInputValid)
				break;
		}

		if (!isInputValid) {
			cout << "Invalid input for matrix \r\n";
			continue;
		}

		isStarted = false;
	}
}

void GetInput(int& arg) {
	bool isStarted = true;

	while (isStarted) {
		bool isInputValid = true;
		cout << "Enter size for the matrix \"Size can be < or = 10: ";
		cin >> arg;

		if (!IsInputValid() || arg > 10) {
			cout << "\r\nInvalid input for size \r\n";
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

void PrintMatrix(int** matrix, int size) {
	cout << "\n";
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void DeleteMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void swapMatrixRows(int** matrix, int firstRow, int secondRow) {
	int* tempValue = matrix[firstRow];
	matrix[firstRow] = matrix[secondRow];
	matrix[secondRow] = tempValue;
}
