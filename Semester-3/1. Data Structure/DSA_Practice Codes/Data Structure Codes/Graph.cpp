#include <iostream>
using namespace std;
//												//
// Graph with chaining with two types of nodes	//
//												//

//class Node
//{
//public:
//	int data;
//	Node* next;
//	Node(int d = 0, Node* n = NULL)
//	{
//		data = d;
//		next = n;
//	}
//};
//
//class Nodeg
//{
//public:
//	int data;
//	int size;
//	Node* head;
//	Nodeg(int d = 0)
//	{
//		head = NULL;
//		data = d;
//		size = 0;
//	}
//
//	void insert(int val)
//	{
//		++size;
//		Node* newnode = new Node(val);
//		if (head == NULL)
//		{
//			head = newnode;
//			return;
//		}
//
//		Node* temp = head;
//		for (; temp->next; temp = temp->next);
//
//		newnode->next = temp->next;
//		temp->next = newnode;
//		temp = NULL;
//		newnode = NULL;
//	}
//
//	void remove(int val)
//	{
//		if (!head)
//			return;
//
//		Node* temp = head, * prev = NULL;
//		for (; temp && temp->data != val; prev = temp, temp = temp->next);
//		if (!temp)
//			return;
//
//		if (temp == head)
//		{
//			head = temp->next;
//			delete temp;
//			--size;
//		}
//		else
//		{
//			if (prev)
//				prev->next = temp->next;
//			delete temp;
//			--size;
//		}
//		prev = NULL;
//		temp = NULL;
//	}
//
//	int find(int val)
//	{
//		if (!head)
//			return -1;
//
//		int ind = 0;
//		Node* temp = head, * prev = NULL;
//		for (; temp && temp->data != val; ++ind, prev = temp, temp = temp->next);
//		
//		if (!temp)
//			return -1;
//		else
//			return ind;
//	}
//
//	void print()
//	{
//		Node* temp = head;
//		while (temp)
//		{
//			cout << temp->data << "  ";
//			temp = temp->next;
//		}
//	}
//};
//
//class Graph
//{
//public:
//	int max;
//	int n;
//	Nodeg* adj;
//	Graph(int m = 10, Nodeg* ADJ = NULL)
//	{
//		max = m;
//		adj = new Nodeg[max];
//		for (int i = 0; i < max; ++i)
//		{
//			adj[i].data = i;
//		}
//		n = 0;
//	}
//
//	void insert_edge(int a, int b)
//	{
//		if (a >= max || b >= max)
//			return;
//
//		if (adj[a].find(b) == -1)
//			adj[a].insert(b);
//		if (adj[b].find(a) == -1)
//			adj[b].insert(a);
//	}
//
//	void remove_edge(int a, int b)
//	{
//		if (a >= max || b >= max)
//			return;
//
//		adj[a].remove(b);
//		adj[b].remove(a);
//	}
//
//	void print()
//	{
//		cout << endl;
//		for (int i = 0; i < max; ++i)
//		{
//			cout << adj[i].data << ": ";
//			adj[i].print();
//			cout << endl;
//		}
//	}
//};

//												//
// Graph with chaining with one types of nodes	//
//												//


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

class Graph
{
public:
	int max;
	int n;
	Node** adj;
	Graph(int m = 10)
	{
		max = m;
		adj = new Node*[max];
		for (int i = 0; i < max; ++i)
			adj[i] = NULL;
		n = 0;
	}

	//void insert(Node*& head, int val)
	//{
	//	//++size;
	//	Node* newnode = new Node(val);
	//	if (head == NULL)
	//	{
	//		head = newnode;
	//		return;
	//	}
	//	Node* temp = head;
	//	for (; temp->next; temp = temp->next);
	//
	//	newnode->next = temp->next;
	//	temp->next = newnode;
	//	temp = NULL;
	//	newnode = NULL;
	//}

	void insert(Node*& head, int val)	// O(1) insertion	(as there is no need of sequence in storing nodes of graph)
	{
		head = new Node(val, head);
	}

	void remove(Node*& head, int val)
	{
		if (!head)
			return;

		Node* temp = head, * prev = NULL;
		for (; temp && temp->data != val; prev = temp, temp = temp->next);
		if (!temp)
			return;

		if (temp == head)
		{
			head = temp->next;
			delete temp;
			//--size;
		}
		else
		{
			if (prev)
				prev->next = temp->next;
			delete temp;
			//--size;
		}
		prev = NULL;
		temp = NULL;
	}

	int find(Node* head, int val)
	{
		if (!head)
			return -1;

		int ind = 0;
		Node* temp = head, * prev = NULL;
		for (; temp && temp->data != val; ++ind, prev = temp, temp = temp->next);

		if (!temp)
			return -1;
		else
			return ind;
	}

	void printl(Node* head)
	{
		Node* temp = head;
		while (temp)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}

	void insert_edge(int a, int b)
	{
		if (a >= max || b >= max)
			return;

		if (find(adj[a], b) == -1)
			insert(adj[a], b);
		if (find(adj[b], a) == -1)
			insert(adj[b], a);
	}

	void remove_edge(int a, int b)
	{
		if (a >= max || b >= max)
			return;

		remove(adj[a], b);
		remove(adj[b], a);
	}

	void print()
	{
		cout << endl;
		for (int i = 0; i < max; ++i)
		{
			cout << i << ": ";
			printl(adj[i]);
			cout << endl;
		}
	}
};




class Grapharr
{
public:
	int** adj;
	int max;
	int* size;
	Grapharr(int m = 10)
	{
		max = m;
		adj = new int* [max + 1];
		for (int i = 0; i < max + 1; ++i)
		{
			adj[i] = new int[max + 1];
			for (int j = 0; j < max + 1; ++j)
				adj[i][j] = -1;
		}
		size = new int[max];
		for (int i = 0; i < max; ++i)
			size[i] = 0;
	}

	void insert_edge(int a, int b)
	{
		if (a >= max || b >= max)
			return;

		if (size[a] <= max && find(a, b) == -1)
			adj[a][size[a]++] = b;

		if (size[b] <= max && find(b, a) == -1)
			adj[b][size[b]++] = a;
	}

	void remove_edge(int a, int b)
	{
		if (a >= max || b >= max)
			return;

		int ind = find(a, b);
		if (ind != -1)
		{
			for (; (ind + 1) < max; ++ind)
				adj[a][ind] = adj[a][ind + 1];
			adj[a][ind + 1] = -1;
			--size[a];
		}
		ind = find(b, a);
		if (ind != -1)
		{
			for (; (ind + 1) < max; ++ind)
				adj[b][ind] = adj[b][ind + 1];
			adj[b][ind + 1] = -1;
			--size[b];
		}
	}

	int find(int a, int b)
	{
		if (a >= max || b >= max)
			return -1;

		for (int i = 0; i < max; ++i)
			if (adj[a][i] == b)
				return i;
		return -1;
	}

	void print()
	{
		cout << endl;
		for (int i = 0; i < max; ++i)
		{
			cout << i << ": ";
			for (int j = 0; j < size[i]; ++j)
				cout << adj[i][j] << "  ";
			cout << endl;
		}
	}

	void make_adj_matrix(int**& arr)
	{
		arr = new int* [max];
		for (int i = 0; i < max; ++i)
			arr[i] = new int[max];

		int ind;
		cout << endl << "Matrix:\n";
		for (int i = 0; i < max; ++i)
		{
			ind = 0;
			for (int j = 0; j < max; ++j)
			{
				if (ind < max && adj[i][ind] == j)
				{
					arr[i][j] = 1;
					ind++;
				}
				else
					arr[i][j] = 0;
			}
		}
	}

	void printarr(int** arr)
	{
		cout << endl;
		for (int i = 0; i < max; ++i)
		{
			for (int j = 0; j < max; ++j)
				cout << arr[i][j] << "  ";
			cout << endl;
		}
	}

	void print_adj_matrix()
	{
		int ind;
		cout << endl << "Matrix:\n";
		for (int i = 0; i < max; ++i)
		{
			ind = 0;
			for (int j = 0; j < max; ++j)
			{
				if (ind < max && adj[i][ind] == j)
				{
					cout << 1 << "  ";
					ind++;
				}
				else
					cout << 0 << "  ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph g;

	g.insert_edge(0, 1);
	g.insert_edge(0, 2);
	g.insert_edge(0, 3);
	g.insert_edge(2, 1);
	g.insert_edge(3, 0);
	g.insert_edge(2, 4);
	g.insert_edge(0, 10);
	g.print();

	g.remove_edge(0, 1);
	g.print();

	Grapharr arr;

	arr.insert_edge(0, 1);
	arr.insert_edge(0, 2);
	arr.insert_edge(0, 3);
	arr.insert_edge(2, 1);
	arr.insert_edge(3, 0);
	arr.insert_edge(2, 4);
	arr.insert_edge(0, 10);
	arr.print();

	arr.remove_edge(0, 1);
	arr.print();

	arr.print_adj_matrix();

	int** adjmat;
	arr.make_adj_matrix(adjmat);
	arr.printarr(adjmat);
}