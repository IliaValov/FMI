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

	GetInputForMatrix(matrix, matrixSize);

	int** tempMatrix = new int* [matrixSize];
	OverwriteMatrixes(matrix, tempMatrix, matrixSize);

	SortMatrixByRowAndFirstCol(matrix, matrixSize);

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
		if (startFrom == 0) {

			swapMatrixRows(matrix, startFrom, i);
			IsTheDiagonalValid = IsThereValidDiagonal(matrix, size, startFrom + 1);
			if (IsTheDiagonalValid) {
				return IsTheDiagonalValid;
			}
			else {
				swapMatrixRows(matrix, startFrom, i);
			}

		}
		else if (startFrom > 0) {

			int currentDiagonalElement = matrix[i][col];
			int previousDiagonalElement = matrix[startFrom - 1][col - 1];

			if (currentDiagonalElement >= previousDiagonalElement) {


				swapMatrixRows(matrix, startFrom, i);
				IsTheDiagonalValid = IsThereValidDiagonal(matrix, size, startFrom + 1);
				if (IsTheDiagonalValid) {
					return IsTheDiagonalValid;
				}
				else {
					swapMatrixRows(matrix, startFrom, i);
				}
			}
		}

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
