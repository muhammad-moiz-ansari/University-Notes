#include <iostream>
using namespace std;

class Node
{
public:
	int val;
	Node* next;
	Node(int v = 0, Node* n = NULL)
	{
		val = v;
		next = n;
	}
};

class List
{
public:
	Node* head;

	List(Node* h = NULL)
	{
		head = h;
	}

	void insert(int val, int index)
	{
		Node* newnode = new Node(val);
		if (head == NULL)
		{
			head = newnode;
			return;
		}

		Node* temp = head;
		for (int i = 1; i < index && temp->next; ++i, temp = temp->next);

		if (index == 0)
		{
			newnode->next = head;
			head = newnode;
		}
		else
		{
			newnode->next = temp->next;
			temp->next = newnode;
		}
		temp = NULL;
		newnode = NULL;
	}

	void insert(int val)
	{
		insert(val, 99);
	}

	void remove(int val)
	{
		if (!head)
			return;

		Node* prev = NULL, * curr = head;
		for (; curr && curr->val != val; prev = curr, curr = curr->next);

		if (!curr)
			return;

		if (prev == NULL || curr == head)
		{
			head = head->next;
			delete curr;
		}
		else
		{
			prev->next = curr->next;
			delete curr;
		}
		prev = NULL;
		curr = NULL;
	}

	void print()
	{
		cout << "\nList: [ ";
		Node* temp = head;
		while (temp)
		{
			cout << temp->val << "  ";
			temp = temp->next;
		}
		cout << "]\n";
	}
	~List()
	{
		Node* temp = head;
		while (temp)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};

//int main()
//{
//	List list;
//
//	list.insert(1);
//	list.insert(2);
//	list.insert(3);
//	list.insert(4);
//	list.insert(5);
//	list.insert(6);
//
//	list.print();
//
//	list.insert(22, 2);
//	list.print();
//	list.insert(00, 0);
//	list.print();
//	list.insert(88, 8);
//	list.print();
//	list.insert(44, 4);
//	list.print();
//	list.insert(11, 1);
//	list.print();
//
//	cout << "\nRemove";
//
//	list.remove(0);
//	list.print();
//	list.remove(88);
//	list.print();
//	list.remove(44);
//	list.print();
//	list.remove(22);
//	list.print();
//	list.remove(99);
//	list.print();
//
//
//	return 0;
//}