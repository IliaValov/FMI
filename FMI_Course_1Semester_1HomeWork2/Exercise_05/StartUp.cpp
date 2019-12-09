#include<iostream>

using namespace std;

int swapElements(int elIndex1, int elIndex2);

bool HeapPermutation(int** a, int size, int n);

bool IsTheDiagonalValid(int** a, int n);

void MoveTheRowWithTheSmallestNumOnTheFirstColToFirstRow(int**, int);

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

	//MoveTheRowWithTheSmallestNumOnTheFirstColToFirstRow(matrix, matrixSize);

	//HeapPermutation(matrix, matrixSize, matrixSize);
	cout << "\n";
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < matrixSize; i++)
	{

		delete[] matrix[i];

	}

	delete[] matrix;

	return 0;
}

void MoveTheRowWithTheSmallerNumAtTheGivenCol(int** matrix, int size, int row, int col) {
	int rowWithTheSmallestNum = 0;
	
	for (int i = row; i < size; i++)
	{
		if (matrix[rowWithTheSmallestNum][col] < matrix[i][col]) {
			swap(matrix[rowWithTheSmallestNum], matrix[i]);
		}
	}
}

bool IsThereValidDiagonal(int** matrix, int size, int startFrom) {

	for (int i = startFrom; i < size; i++)
	{
		//TODO Need to make some graph shit		
	}

	return true;
}



bool HeapPermutation(int** a, int size, int n)
{
	// if size becomes 1 then prints the obtained 
	// permutation 
	if (size == 1)
	{

		return IsTheDiagonalValid(a, n);
	}

	for (int i = 0; i < size; i++)
	{
		if (HeapPermutation(a, size - 1, n))
			return true;

		// if size is odd, swap first and last 
		// element 
		if (size % 2 == 1)
			swap(a[0], a[size - 1]);

		// If size is even, swap ith and last 
		// element 
		else
			swap(a[i], a[size - 1]);
	}

	return false;

}

bool IsTheDiagonalValid(int** matrix, int size)
{
	for (int i = 0; i < size; i++) {
		if (matrix[i][i + 1] > matrix[i + 1][i + 2])
			return false;
	}

	return true;
}

