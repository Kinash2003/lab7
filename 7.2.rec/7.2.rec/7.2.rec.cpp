#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n = "; cin >> n;
	cout << endl;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	int Low = -26, High = 23;
	CreateRows(a, n, Low, High, 0);
	PrintRows(a, n, 0);
	int k = -1;
	int maxEven;
	SearchFirstEven(a, n, 0, maxEven, k);
	if (k > -1)
	{
		SearchMaxEven(a, n, k + 1, maxEven);
		cout << "sum max = " << maxEven << endl;
	}
	else
		cout << "there are no even elements" << endl;

	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRow(int** a, const int rowNo, const int n, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < n - 1)
		CreateRow(a, rowNo, n, Low, High, colNo + 1);
}
void CreateRows(int** a, const int n, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, n, Low, High, 0);
	if (rowNo < n - 1)
		CreateRows(a, n, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < n - 1)
		PrintRow(a, rowNo, n, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int n, int rowNo)
{
	PrintRow(a, rowNo, n, 0);
	if (rowNo < n - 1)
		PrintRows(a, n, rowNo + 1);
	else
		cout << endl;
}
void SearchFirstEven(int** a, const int n, int i, int& maxEven, int& k)
{
	if (a[i][n - 1 - i] % 2 != 0)
	{
		k = i;
		maxEven = a[i][n - 1 - i];
	}
	else
		if (i < n - 1)
			SearchFirstEven(a, n, i + 1, maxEven, k);
}
void SearchMaxEven(int** a, const int n, int i, int& maxEven)
{
	if (a[i][n - 1 - i] % 2 != 0 && a[i][n - 1 - i] > maxEven)
		maxEven = a[i][n - 1 - i];
	if (i < n - 1)
		SearchMaxEven(a, n, i + 1, maxEven);
}

