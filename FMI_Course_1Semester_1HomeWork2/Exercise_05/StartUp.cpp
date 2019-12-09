#include<iostream>

using namespace std;

void PrintMatrix(int**, int);
bool IsThereValidDiagonal(int**, int, int);

int main() {
	int matrixSize = 0;

	cout << "Enter matrix size: "; cin >> matrixSize;

	int** matrix = new int* [matrixSize];

	for (int row = 0; row < matrixSize; row++)
	{
		matrix[row] = new int[matrixSize];
		for (int col = 0; col < matrixSize; col++)
		{
			int element = 0;
			cin >> element;

			matrix[row][col] = element;
		}
	}
	IsThereValidDiagonal(matrix, matrixSize, 0);

	PrintMatrix(matrix, matrixSize);

	for (int i = 0; i < matrixSize; i++)
	{

		delete[] matrix[i];

	}

	delete[] matrix;

	return 0;
}

bool IsThereValidDiagonal(int** matrix, int size, int startFrom) {
	bool IsTheDiagonalValid = true;

	int smallestRowOnCol = startFrom;

	int col = startFrom;

	for (int i = startFrom; i < size - 1; i++)
	{
		int currentDiagonalElement = matrix[i][col];

		int nextDiagonalElement = matrix[i + 1][col + 1];

		if (currentDiagonalElement <= nextDiagonalElement) {
			swap(matrix[startFrom], matrix[i ]);
			IsTheDiagonalValid = IsThereValidDiagonal(matrix, size, startFrom + 1);
			if (IsTheDiagonalValid) {
				return IsTheDiagonalValid;
			}
			else {
				swap(matrix[startFrom], matrix[i ]);
			}
		}
	}

	return IsTheDiagonalValid;
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

