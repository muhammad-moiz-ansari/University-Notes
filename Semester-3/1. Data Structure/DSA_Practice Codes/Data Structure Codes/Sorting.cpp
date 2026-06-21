#include <iostream>
using namespace std;

void bubblesort(int*& arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		bool swap = 0;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swap = 1;
			}
		}
		if (!swap)
			break;
	}
}

void insertionsort(int*& arr, int size)
{
	int temp, j;
	for (int i = 1; i < size; ++i)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (temp < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = temp;
	}
}

void selectionsort(int*& arr, int size)
{
	int temp, maxind;
	for (int i = size - 1; i > 0; --i)
	{
		maxind = i;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[maxind])
				maxind = j;
		}
		if (arr[maxind] > arr[i])
		{
			temp = arr[i];
			arr[i] = arr[maxind];
			arr[maxind] = temp;
		}
	}
}

void print(int* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; ++i)
		cout << arr[i] << "  ";
	cout << endl;
}
//
//int main()
//{
//	int size = 9;
//	int arr1[] = { 0,8,7,6,4,5,3,1,2 };
//	int arr2[] = { 8,0,7,6,4,5,3,1,2 };
//	int arr3[] = { 0,8,7,6,4,5,3,1,2 };
//
//	int* ptr1 = arr1;
//	int* ptr2 = arr2;
//	int* ptr3 = arr3;
//
//
//	print(arr1, size);
//	print(arr2, size);
//	print(arr3, size);
//
//	cout << "\nSort:";
//	bubblesort(ptr1, size);
//	insertionsort(ptr2, size);
//	selectionsort(ptr3, size);
//
//	print(arr1, size);
//	print(arr2, size);
//	print(arr3, size);
//
//	return 0;
//}