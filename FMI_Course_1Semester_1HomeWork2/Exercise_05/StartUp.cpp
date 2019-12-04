#include<iostream>

using namespace std;

int swapElements(int elIndex1, int elIndex2);

void heapPermutation(int a[], int size, int n);

void printArr(int a[], int n);

int main() {
	int matrixSize = 0;

	int** matrix = new int* [matrixSize];

	cout << "Enter matrix size: "; cin >> matrixSize;

	for (int row = 0; row < matrixSize; row++)
	{
		matrix[row] = new int[matrixSize]();
		for (int col = 0; col < matrixSize; col++)
		{
			int element = 0;
			cin >> element;

			matrix[row][col] = element;
		}
	}

	/*
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			cout << matrix[i][j];
		}
		cout << "\n";
	}*/


	heapPermutation(matrix[0], matrixSize, matrixSize);

	for (int i = 0; i < matrixSize; i++)
	{
		delete[] matrix[i];
	}

	return 0;
}


void heapPermutation(int a[], int size, int n)
{
	// if size becomes 1 then prints the obtained 
	// permutation 
	if (size == 1)
	{
		printArr(a, n);
		return;
	}


	for (int i = 0; i < size; i++)
	{
		heapPermutation(a, size - 1, n);

		// if size is odd, swap first and last 
		// element 
		if (size % 2 == 1)
			swap(a[0], a[size - 1]);

		// If size is even, swap ith and last 
		// element 
		else
			swap(a[i], a[size - 1]);
	}
}

void printArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	printf("\n");
}

