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

class DoublyCircularList
{
public:
	Node* head;
	int size;
	DoublyCircularList(Node* h = NULL, int s = 0)
	{
		head = h;
		size = s;
	}

	void insert(int val, int index)
	{
		Node* newnode = new Node(val);
		int ind = index;
		++size;
		if (!head)
		{
			head = newnode;
			newnode->prev = head;
			newnode->next = head;
			return;
		}

		if (index == 0)
			index = size + 1;
		else
			index = index % size;
		Node* temp = head;
		for (int i = 1; i < index && temp->next != head; ++i, temp = temp->next);

		if (ind == 0)
		{
			newnode->next = head;
			head->prev = newnode;
			temp->next = newnode;
			newnode->prev = temp;
			head = newnode;
		}
		else
		{
			temp->next->prev = newnode;
			newnode->prev = temp;
			newnode->next = temp->next;
			temp->next = newnode;
		}
		newnode = NULL;
		temp = NULL;
	}

	//void insert(int val)
	//{
	//	insert(val, size);
	//}

	void insert(int val)	// O(1) insertion at end
	{
		if (head == NULL)
		{
			head = new Node(val);
			head->next = head;
			head->prev = head;
		}
		else
		{
			Node* temp = head->prev;
			temp->next = new Node(val, head, temp);
			head->prev = temp->next;
		}
	}

	void remove(int val)
	{
		--size;
		if (!head)
			return;

		Node* temp = head;
		bool b = 0;
		if (temp->data == val)
			b = 1;
		if(!b)
		{
			temp = temp->next;
			for (; temp->data != val && temp != head; temp = temp->next);
			if (temp == head)
				return;
		}
		if (temp->next == temp)
		{
			delete temp;
			head = NULL;
		}
		else
		{
			if (temp == head)
				head = temp->next;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		temp = NULL;
	}

	void print()
	{
		cout << "\nList: [ ";
		Node* temp = head;
		if (head)
		{
			while (1)
			{
				cout << temp->data << "  ";
				if (temp->next == head)
					break;
				temp = temp->next;
			}
		}
		cout << "]\n";
	}
	void print(int s)
	{
		cout << "\nList: [ ";
		Node* temp = head;
		if (head)
		{
			for (int i = 0; i < s; ++i)
			{
				cout << temp->data << "  ";
				temp = temp->next;
				if ((i + 1) % size == 0)
					cout << "   ";
			}
		}
		cout << "]\n";
	}

};




int main()
{
	DoublyCircularList list;

	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);

	list.print(30);

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
	list.print(40);


	return 0;
}