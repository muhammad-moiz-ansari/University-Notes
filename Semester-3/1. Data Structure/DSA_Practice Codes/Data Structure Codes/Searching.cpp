#include <iostream>
using namespace std;

int linearsearch(int* arr, int size, int val)
{
	for (int i = 0; i < size; ++i)
		if (arr[i] == val)
			return i;
	return -1;
}

int binarysearch(int* arr, int size, int val)
{
	int start = 0, end = size - 1, mid;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		if (val == arr[mid])
			return mid;

		if (val < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

int main()
{
	int arr1[] = { 2,5,7,9,5,3 };
	int arr2[] = { 2,5,7,9,11,13,16,16,18,20,21 };

	cout << "Linear search: " << linearsearch(arr2, 11, 18);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 18);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 14);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 14);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 21);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 21);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 2);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 2);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 5);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 5);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 7);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 7);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 9);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 9);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 11);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 11);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 20);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 20);

	cout << "\nLinear search: " << linearsearch(arr2, 11, 16);
	cout << "\nBinary search: " << binarysearch(arr2, 11, 16);


	return 0;
}