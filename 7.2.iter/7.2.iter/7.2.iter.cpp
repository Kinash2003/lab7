#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
bool SearchMaxEven(int** a, const int n, int& maxEven);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int n;
	cout << "n = "; cin >> n;
	
	
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	int maxEven;
	if (SearchMaxEven(a, n, maxEven))
		cout << "sum max = " << maxEven << endl;
	else
		cout << "there are no even elements" << endl;

		
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

bool SearchMaxEven(int** a, const int n, int& maxEven)
{
	int j, k = 1;
	for (int i = 0; i < n; i++)
	{
		j = n - 1 - i;
		if (a[i][j] % 2 != 0)
		{
			k = i;
			maxEven = a[i][j];
			break;
		}
	}

	if (k == 1)
		return false;
	for (int i = k + 1; i < n; i++)
	{
		j = n - 1 - i;
		if (a[i][j] % 2 != 0 && a[i][j] > maxEven)
		{
			maxEven = a[i][j];
		}
	}
	return true;
}