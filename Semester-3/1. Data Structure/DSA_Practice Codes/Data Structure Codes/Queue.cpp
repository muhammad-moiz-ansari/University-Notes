#include <iostream>
using namespace std;

template <typename T>
class Qnode
{
public:
	T data;
	Qnode<T>* next;
	Qnode(T d = 0, Qnode<T>* n = NULL)
	{
		data = d;
		next = n;
	}
};

template <typename T>
class Queue
{
public:
	Qnode<T>* front;
	Qnode<T>* rear;
	Queue(Qnode<T>* f = NULL, Qnode<T>* r = NULL)
	{
		front = f;
		rear = r;
	}

	void enque(T val)
	{
		Qnode<T>* newnode = new Qnode<T>(val);
		if (isempty())
			rear = front = newnode;
		else
		{
			rear->next = newnode;
			rear = rear->next;
		}
	}

	void deque()
	{
		if (isempty())
			return;

		if (front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			Qnode<T>* temp = front;
			front = front->next;
			delete temp;
			temp = NULL;
		}
	}

	Qnode<T>* fronte()
	{
		return front;
	}

	bool isempty()
	{
		if (!rear && !front)
			return true;
		else
			return false;
	}

	void print()
	{
		Qnode<T>* temp1 = rear, * temp2 = front;
		cout << "\nQueue: [ ";
		while (temp1)
		{
			cout << temp1->data << "  ";
			if (temp1 == front)
				break;
			for (temp2 = front; temp2->next != temp1; temp2 = temp2->next);
			temp1 = temp2;
		}
		cout << "]\n";
		temp1 = NULL;
		temp2 = NULL;
	}

	void printN()
	{
		Qnode<T>* temp1 = rear, * temp2 = front;
		cout << "\nQueue: [ ";
		while (temp1)
		{
			cout << temp1->data->data << "  ";
			if (temp1 == front)
				break;
			for (temp2 = front; temp2->next != temp1; temp2 = temp2->next);
			temp1 = temp2;
		}
		cout << "]\n";
		temp1 = NULL;
		temp2 = NULL;
	}

	void printdef()
	{
		Qnode<T>* temp = front;
		cout << "\nQueue: (F) [ ";
		while (temp)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << "] (R)\n";
	}

	~Queue()
	{
		while (rear)
		{
			deque();
		}
	}
};


//
//int main()
//{
//	Queue<int> st;
//
//	st.enque(1);
//	st.enque(2);
//	st.enque(3);
//	st.enque(4);
//	st.enque(5);
//	st.printdef();
//
//	cout << st.front->data << endl;
//	st.deque();
//	cout << st.front->data << endl;
//	st.deque();
//	cout << st.front->data << endl;
//	st.deque();
//
//	st.printdef();
//
//	Queue<Qnode<char>*> stn;
//
//	stn.enque(new Qnode<char>('z'));
//	stn.enque(new Qnode<char>('z'));
//	stn.enque(new Qnode<char>('i'));
//	stn.enque(new Qnode<char>('o'));
//	stn.enque(new Qnode<char>('M'));
//	stn.printN();
//
//	cout << stn.front->data->data << endl;
//	stn.deque();
//	cout << stn.front->data->data << endl;
//	stn.deque();
//	cout << stn.front->data->data << endl;
//	stn.deque();
//
//	stn.printN();
//
//
//}