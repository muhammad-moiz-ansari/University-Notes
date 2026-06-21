 #include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int d = 0, Node* n = NULL)
	{
		data = d;
		next = n;
	}
};

class CircularList
{
public:
	Node* head;
	int size;
	CircularList(Node* h = NULL)
	{
		head = h;
		size = 0;
	}

	void insert(int val, int index)
	{
		Node* newnode = new Node(val);
		int ind = index;
		++size;
		if (!head)
		{
			head = newnode;
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
			temp->next = newnode;
			head = newnode;
		}
		else
		{
			newnode->next = temp->next;
			temp->next = newnode;
		}
		newnode = NULL;
		temp = NULL;
	}
	void insert(int val)
	{
		insert(val, size);
	}

	void remove(int val)
	{
		--size;
		if (!head)
			return;

		Node* temp = head, * prev = NULL;
		for (; temp->data != val && temp->next != head; prev = temp, temp = temp->next);
		if (prev == NULL)
		{
			prev = temp;
			temp = temp->next;
			for (; temp != head; prev = temp, temp = temp->next);
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
			prev->next = temp->next;
			delete temp;
		}
		temp = NULL;
		prev = NULL;
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
	CircularList list;

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