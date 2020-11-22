#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** p, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** p, const int rowCount, const int colCount);
void Sort(int** p, const int rowCount, const int colCount);
void Change(int** p, const int col1, const int col2, const int rowCount);
void Calc(int** p, const int rowCount, const int colCount, int& S, int& k);
int main()
{
    srand((unsigned)time(NULL));
    int Low = -26;
    int High = 23;
    int rowCount = 8;
    int colCount = 6;
    int** p = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        p[i] = new int[colCount];
    Create(p, rowCount, colCount, Low, High);
    Print(p, rowCount, colCount);
    Sort(p, rowCount, colCount);
    Print(p, rowCount, colCount);
    int S = 0;
    int k = 0;
    Calc(p, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(p, rowCount, colCount);
    for (int i = 0; i < rowCount; i++)
        delete[] p[i];
    delete[] p;
    return 0;
}
void Create(int** p, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            p[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** p, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << p[i][j];
        cout << endl;
    }
    cout << endl;
}
void Sort(int** p, const int rowCount, const int colCount)
{
    for (int j0 = 0; j0 < colCount - 1; j0++)
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
            if ((p[0][j1] > p[0][j1 + 1])
                ||
                (p[0][j1] == p[0][j1 + 1] &&
                    p[1][j1] > p[1][j1 + 1])
                ||
                (p[0][j1] == p[0][j1 + 1] &&
                    p[1][j1] == p[1][j1 + 1] &&
                    p[3][j1] < p[3][j1 + 1]))
                Change(p, j1, j1 + 1, rowCount);
}
void Change(int** p, const int col1, const int col2, const int rowCount)
{
    int tmp;
    for (int i = 0; i < rowCount; i++)
    {
        tmp = p[i][col1];
        p[i][col1] = p[i][col2];
        p[i][col2] = tmp;
    }
}
void Calc(int** p, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (p[i][j] % 2 == 0 && (p[i][j] > 0))
            {
                S += p[i][j];
                k++;
                p[i][j] = 0;
            }

}