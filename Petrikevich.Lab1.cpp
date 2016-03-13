//№5
#include <iostream>
using namespace std;

int* EnterArray(int);
int FindMinEllement(int*, int);
int SizeOfNewArray(int*, int, int);
int* NewArray(int*, int, int, int);
void DisplayArray(int*, int);
void InTheBinarySystem(int*, int);
void SortByTheNumberOfUnits(int*, int);
void DeleteEllementsOfArray(int*, int&, int);

int main()
{
	int size;
	while (true)
	{
		cout << "Please, enter size of array : " << endl;
		cin >> size;
		if (size > 0) break;
		cout << "Error!";
	}
	system("cls");
	int* array = EnterArray(size);
	cout << "Source arrays: " << endl;
	DisplayArray(array, size);
	cout << endl;

	int min = FindMinEllement(array, size);
	cout << endl << "Min: " << min << endl;
	int newSize = SizeOfNewArray(array, size, min);
	cout << endl << "New size: " << newSize << endl;


	int* newArray = NewArray(array, size, min, newSize);
	cout << endl << "New array:" << endl;
	DisplayArray(newArray, newSize);
	cout << endl;

	DeleteEllementsOfArray(array, size, min);
	cout << endl << "Old array:" << endl;
	DisplayArray(array, size);
	cout << endl;

	cout << endl << "In binary system:" << endl;
	InTheBinarySystem(newArray, size);
	DisplayArray(newArray, newSize);
	cout << endl << endl << "After sort:" << endl;
	SortByTheNumberOfUnits(newArray, newSize);
	DisplayArray(newArray, newSize);
	system("pause");
	return 0;
}

int* EnterArray(int n)
{
	int* a = new int[n];
	cout << "Please, enter ellements of array: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "array[" << (i + 1) << "] = ";
		cin >> a[i];
	}
	system("cls");
	return a;
}

int FindMinEllement(int* a, int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

int SizeOfNewArray(int* a, int n, int min)
{
	int k = 0;
	int* p = a;
	for (; p < a + n; p++)
	{
		if ((*p % min) == 0)
		{
			k++;
		}
	}
	if (*(p + n) % min == 0)
	{
		k--;
	}
	return k;
}

int* NewArray(int* a, int n, int min, int k)
{
	int* b = new int[k];
	int* q = b;
	for (int* p = a; p < a + n; p++)
		if ((*p % min) == 0)
		{
			*q = *(p + 1);
			q++;
		}

	return b;
}

void DeleteEllementsOfArray(int* a, int& n, int min)
{
	for (int* p = a; p < a + n; p++)
	{
		if ((*p % min) == 0)
		{
			*(p + 1) = *(p + 2);
			n--;
		}

	}
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
}

void InTheBinarySystem(int* a, int n)
{
	int t, d;
	for (int *p = a; p < a + n; p++)
	{
		t = 0, d = 1;
		while (*p)
		{
			t += (*p % 2)*d;
			*p = *p / 2;
			d = d * 10;
		}
		*p = t;
	}
}

void SortByTheNumberOfUnits(int* a, int n)
{

	for (int i = 0; i < n; i++)
	{
		int s = 0, p = 0;
		int k = a[i];
		while (k)
		{
			if (k % 10 == 1)
				s++;
			k = k / 10;
		}
		for (int j = i + 1; j < n; j++)
		{
			int t = a[j];
			while (t)
			{
				if (t % 10 == 1)
					p++;
				t = t / 10;
			}
			if (p < s)
				swap(a[j], a[j - 1]);
			if (a[i] != a[j]) break;
		}
	}
}
