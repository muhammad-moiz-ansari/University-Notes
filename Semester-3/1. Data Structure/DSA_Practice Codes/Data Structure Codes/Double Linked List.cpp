#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next, * prev;
	Node(int d = 0, Node* n = NULL, Node* p = NULL)
	{
		data = d;
		next = n;
		prev = p;
	}
};

class DoublyList
{
public:
	Node* head;
	DoublyList(Node* h = NULL)
	{
		head = h;
	}

	void insert(int val, int index)
	{
		Node* newnode = new Node(val);
		if (!head)
		{
			head = newnode;
			return;
		}

		Node* temp = head;
		for (int i = 1; i < index && temp->next; ++i, temp = temp->next);

		if (index == 0)
		{
			newnode->next = head;
			newnode->next->prev = newnode;		//head->prev = newnode;
			head = newnode;
		}
		else
		{
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next = newnode;
			if (newnode->next)
				newnode->next->prev = newnode;
		}
		newnode = NULL;
		temp = NULL;
	}
	void insert(int val)
	{
		insert(val, 99);
	}

	void remove(int val)
	{
		if (!head)
			return;

		Node* temp = head;
		for (; temp && temp->data != val; temp = temp->next);

		if (!temp)
			return;

		if (temp->next)
			temp->next->prev = temp->prev;
		if (temp->prev)
			temp->prev->next = temp->next;
		if (temp == head)
			head = temp->next;
		delete temp;
		temp = NULL;
	}

	void print()
	{
		cout << "\nList: [ ";
		Node* temp = head;
		while (temp)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << "]\n";
	}
};


int main()
{
	DoublyList list;

	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);

	list.print();

	list.insert(22, 2);
	list.print();
	list.insert(00, 0);
	list.print();
	list.insert(88, 8);
	list.print();
	list.insert(44, 4);
	list.print();
	list.insert(11, 1);
	list.print();

	cout << "\nRemove";

	list.remove(0);
	list.print();
	list.remove(88);
	list.print();
	list.remove(44);
	list.print();
	list.remove(22);
	list.print();
	list.remove(99);
	list.print();




	return 0;
}