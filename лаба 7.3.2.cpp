// лаба 7.3.2. cpp

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int j0, int j1);
int Sum(int** a, const int colNo, const int rowCount, int i);
void Change(int** a, const int col1, const int col2, const int rowCount, int i);
void Sumtask2(int** a, const int rowCount, const int colCount, int i, int j);
int Sumdo(int** a, const int colNo, const int rowCount, int i);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 24;
	int rowCount, colCount;
	cout << "n = "; cin >> colCount;
	cout << "k = "; cin >> rowCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	cout << "First Task" << endl;
	Sort(a, rowCount, colCount, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	cout << "Second Task" << endl;
	Sumtask2(a, rowCount, colCount, 0, 0);

	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, i, j + 1);
		}
		Create(a, rowCount, colCount, Low, High, i + 1, j);
	}
			
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;

}
int Sum(int** a, const int colNo, const int rowCount, int i)
{
	int S = 0;
	if (i < rowCount) {
		if (a[i][colNo] < 0 && a[i][colNo] % 2 != 0)
			S += a[i][colNo];
		Sum(a, colNo, rowCount, i + 1);
	}
	return S;
}
void Sort(int** a, const int rowCount, const int colCount, int j0, int j1)
{
	if (j0 < colCount - 1) {
		if (j1 < colCount - j0 - 1) {
			if (Sum(a, j1, rowCount, 0) < Sum(a, j1 + 1, rowCount, 0))
				Sort(a, rowCount, colCount, j0, j1 + 1);
		}
		Sort(a, rowCount, colCount, j0 + 1, j1);
	}
}
void change(int** a, const int col1, const int col2, const int rowCount, int i)
{
	int tmp;
	if (i < rowCount)
	{
		tmp = a[i][col1];
		a[i][col1] = a[i][col2];
		a[i][col2] = tmp;
	}
	Change(a, col1, col2, rowCount, i + 1);
}
void Sumtask2(int** a, const int rowCount, const int colCount, int j, int i)
{
	if (j < colCount) {
		if (i < rowCount)
		{
			if (a[i][j] < 0) {
				cout << "Sum = " << Sumdo(a, j, rowCount, 0) << endl;
				Sumtask2(a, rowCount, colCount, j + 1, i);
			}
			else
				Sumtask2(a, rowCount, colCount, j, i + 1);
		}
		Sumtask2(a, rowCount, colCount, j + 1, i);
	}
}
int Sumdo(int** a, const int colNo, const int rowCount, int i)
{
	int S2 = 0;
	if (i < rowCount) {
		S2 += a[i][colNo];
		Sumdo(a, colNo, rowCount, i + 1);
	}
	return S2;
}
