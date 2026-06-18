#include <iostream>
using namespace std;

class Matrices
{
private:
	int** a,
		r, c;

public:
	Matrices(int** x = NULL, int p = 0, int q = 0)
	{
		a = x;
		r = p;
		c = q;
	}
	Matrices(const Matrices& obj)
	{
		for (int i = 0; i < r; ++i)
			delete[] a[i];
		delete[] a;

		this->r = obj.r;
		this->c = obj.c;

		a = new int* [r];
		for (int i = 0; i < r; ++i)
		{
			a[i] = new int[c];
			for (int j = 0; j < c; ++j)
			{
				a[i][j] = obj.a[i][j];
			}
		}
	}

	Matrices& operator*(Matrices& o)
	{
		int r1 = r, c1 = c, r2 = o.r, c2 = o.c;

		int** arr = new int* [r1];
		for (int i = 0; i < r1; ++i)
		{
			arr[i] = new int[c2];
			for (int j = 0; j < c2; ++j)
			{
				arr[i][j] = 0;
			}
		}
		Matrices* prod = new Matrices(arr, r1, c2), * n = new Matrices();

		if (c1 != r2)
		{
			cout << "Error: Matrices can not be multiplied.\n";
			return *n;
		}
		else
		{
			for (int i = 0; i < r1; ++i)
			{
				for (int j = 0; j < c2; ++j)
				{
					for (int k = 0; k < c1; ++k)
						prod->a[i][j] += this->a[i][k] * o.a[k][j];
				}
			}
			return *prod;
		}
	}
	friend ostream& operator<<(ostream&, Matrices&);

};
ostream& operator<<(ostream& out, Matrices& m)
{
	out << endl;
	for (int i = 0; i < m.r; ++i)
	{
		for (int j = 0; j < m.c; ++j)
		{
			out << m.a[i][j] << "\t";
		}
		out << endl << endl;
	}
	return out;
}

//
//int main()
//{
//	int** arr1, ** arr2, n = 1
//		, r1 = 2
//		, c1 = 3
//		, r2 = 3
//		, c2 = 2
//		;
//
//	cout << "Enter r1, c1, r2, c2: ";
//	cin >> r1 >> c1 >> r2 >> c2;
//
//	arr1 = new int* [r1];
//	for (int i = 0; i < r1; ++i)
//	{
//		arr1[i] = new int[c1];
//		for (int j = 0; j < c1; ++j)
//		{
//			arr1[i][j] = n++;
//		}
//	}
//
//	n = 1;
//	arr2 = new int* [r2];
//	for (int i = 0; i < r2; ++i)
//	{
//		arr2[i] = new int[c2];
//		for (int j = 0; j < c2; ++j)
//		{
//			arr2[i][j] = n++;
//		}
//	}
//	Matrices A(arr1, r1, c1), B(arr2, r2, c2), P;
//
//	cout << "Matrix A:\n" << A;
//	cout << "Matrix B:\n" << B;
//
//	P = A * B;
//
//	cout << "Matrix P:\n" << P;
//
//
//	return 0;
//}