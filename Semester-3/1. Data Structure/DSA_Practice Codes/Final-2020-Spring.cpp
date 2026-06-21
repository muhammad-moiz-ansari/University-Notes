#include <iostream>
#include <queue>
using namespace std;

///////////////////////////  Q - 4  ///////////////////////////

int getfromfront(queue<int>& q, int index)
{
	queue<int> temp = q;
	int size = 0, num;
	while (!temp.empty())
	{
		++size;
		temp.pop();
	}
	for (int i = 0; i < index - 1; ++i)
	{
		q.push(q.front());
		q.pop();
	}
	num = q.front();
	q.pop();
	for (int i = 0; i < size - index; ++i)
	{
		q.push(q.front());
		q.pop();
	}

	return num;
}

int getfromback(queue<int>& q, int index)
{
	queue<int> temp = q;
	int size = 0, num;
	while (!temp.empty())
	{
		temp.pop();
		++size;
	}
	for (int i = 0; i < size - index; ++i)
	{
		q.push(q.front());
		q.pop();
	}
	num = q.front();
	q.pop();
	for (int i = 0; i < index - 1; ++i)
	{
		q.push(q.front());
		q.pop();
	}
	return num;
}

void print(queue<int> q)
{
	queue<int> temp = q;
	cout << "\nQueue: (F) [ ";
	while (!temp.empty())
	{
		cout << temp.front() << "  ";
		temp.pop();
	}
	cout << "] (R)\n";
}

int main()
{
	queue<int> q;
	q.push(10);
	q.push(5);
	q.push(2);
	q.push(9);
	q.push(4);
	q.push(7);
	print(q);

	cout << endl << "From Front: " << getfromfront(q, 4);
	print(q);

	///////////////////////////////////

	queue<int> q2;
	q2.push(10);
	q2.push(5);
	q2.push(2);
	q2.push(9);
	q2.push(4);
	q2.push(7);
	print(q2);

	cout << endl << "From Back: " << getfromback(q2, 4);
	print(q2);



	return 0;
}