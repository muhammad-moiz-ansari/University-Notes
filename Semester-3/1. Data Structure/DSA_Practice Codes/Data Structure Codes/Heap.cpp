#include <iostream>
#include <cmath>
#include "D:\Documents\Semester-3\1. Data Structure\DSA_Practice Codes\Basic Codes\Queue.cpp";
using namespace std;


class Heap
{
public:
	int* arr;
	int size;
	int current;
	bool type;
	Heap(bool b = 0, int hsize = 50)	//Type = 0 for Min heap & Type = 1 for Max heap
	{
		arr = new int[hsize];
		size = hsize;
		current = -1;
		type = b;
	}

	void insert(int val)
	{
		if (current + 1 >= size)
			return;
		
		arr[++current] = val;
		int ind = current;
		while (ind > 0)
		{
			if (type == 0 && arr[ind] < arr[parent(ind)])
				swap(arr[ind], arr[parent(ind)]);
			else if (type == 1 && arr[ind] > arr[parent(ind)])
				swap(arr[ind], arr[parent(ind)]);
			ind = parent(ind);
		}
	}

	void remove()
	{
		if (current == -1)
			return;

		arr[0] = arr[current--];
		int ind = 0, minind = 0;
		while (ind < current && left(ind) <= current)
		{
			if (right(ind) <= current)
			{
				if (type == 0)
					minind = minindex(left(ind), right(ind));
				else
					minind = maxindex(left(ind), right(ind));
			}
			else
				minind = left(ind);
			if (type == 0 && arr[ind] > arr[minind])
				swap(arr[ind], arr[minind]);
			else if (type == 1 && arr[ind] < arr[minind])
				swap(arr[ind], arr[minind]);
			ind = minind;
		}
	}

	void heapify(int*& tarr, int curr)
	{
		int ind = 0, tempind = 0, minind = 0, hindex = 0, sum = 0, p = 0;
		for (int i = 0; ; ++i)
		{
			sum = 0;
			for (int j = 0; j <= i; ++j)
				sum += pow(2, j);
			--sum;
			if (sum > curr)
			{
				sum = p;
				break;
			}
			p = sum;
		}
		ind = sum;
		bool doit = 0;		////////////////////#note: check if to remove
		while (ind >= 0)
		{
			doit = 1;				//////////////#note: check if to remove or write doit = 0;   ????
			if (right(ind) <= curr)
			{
				doit = 1;
				minind = minindex(tarr, left(ind), right(ind));
			}
			else if (left(ind) <= curr)
			{
				doit = 1;
				minind = left(ind);
			}

			if (doit && tarr[ind] > tarr[minind])
			{
				swap(tarr[ind], tarr[minind]);
				tempind = minind;
				while (tempind < sum && left(tempind) <= curr)
				{
					if (right(tempind) <= curr)
						minind = minindex(tarr, left(tempind), right(tempind));
					else
						minind = left(tempind);
					if (tarr[tempind] > tarr[minind])
						swap(tarr[tempind], tarr[minind]);
					tempind = minind;
				}
			}
			--ind;
		}
	}

	void swap(int& a, int& b)
	{
		int hehe = a;
		a = b;
		b = hehe;
	}
	int minindex(int*tarr, int a, int b)
	{
		return tarr[a] < tarr[b] ? a : b;
	}

	int minindex(int a, int b)
	{
		return arr[a] < arr[b] ? a : b;
	}
	int maxindex(int a, int b)
	{
		return arr[a] > arr[b] ? a : b;
	}

	int left(int i)
	{
		return (2 * i) + 1;
	}
	int right(int i)
	{
		return (2 * i) + 2;
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}

	void print()
	{
		cout << endl;
		for (int i = 0; i <= current && i < size; ++i)
			cout << arr[i] << "  ";
		cout << endl;
	}
};

int main()
{
	/*int hindex = 0, sum = 0, p = 0, pp = 0;
	for (int i = 0; ; ++i)
	{
		sum = 0;
		for (int j = 0; j < i; ++j)
			sum += pow(2, j);
		--sum;
		if (sum > ind)
		{
			sum = p;
			break;
		}
		pp = p;
		p = sum;
	}
	ind = sum;
	tree.heapify(tree.size, ind, pp);*/

	Heap h(1);

	h.insert(2);
	h.insert(3);
	h.insert(9);
	h.insert(10);
	h.insert(8);
	h.insert(4);
	h.insert(1);
	h.insert(0);
	h.print();

	h.remove();
	h.print();
	h.remove();
	h.print();
	h.remove();
	h.print();
	h.remove();
	h.print();
	h.remove();
	h.print();
	h.remove();
	h.print();
	h.remove();
	h.print();
	h.remove();
	h.print();
	h.remove();
	h.print();

	h.insert(0);
	h.print();

	cout << "Heapify:\n";
	int size = 10;
	int* arr = new int[size];
	int initialValues[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	for (int i = 0; i < size; ++i)
		arr[i] = initialValues[i];

	h.heapify(arr, size - 1);
	for (int i = 0; i < size; ++i)
		cout << arr[i] << "  ";
	cout << endl;
}