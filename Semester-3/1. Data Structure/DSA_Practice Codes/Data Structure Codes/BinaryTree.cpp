#include <iostream>
#include "Basic Codes/Queue.cpp";
//#include "Print Tree.cpp";
using namespace std;

template <typename T>
class NodeT
{
public:
	T data;
	NodeT<T>* left;
	NodeT<T>* right;
	NodeT<T>* next;
	NodeT(T d = 0, NodeT<T>* l = NULL, NodeT<T>* r = NULL)
	{
		data = d;
		left = l;
		right = r;
	}
};

template <typename T>
class Tree
{
public:
	NodeT<T>* root;
	Tree(NodeT<T>* r = NULL)
	{
		root = r;
	}

	void insert(T val)
	{
		NodeT<T>* newnode = new NodeT<T>(val);
		if (!root)
		{
			root = newnode;
			return;
		}
		Queue<NodeT<T>*> q;
		q.enque(root);

		while (!q.isempty())
		{
			if (q.front->data->left == NULL)
			{
				q.front->data->left = newnode;
				return;
			}
			else if (q.front->data->right == NULL)
			{
				q.front->data->right = newnode;
				return;
			}
			else
			{
				q.enque(q.front->data->left);
				q.enque(q.front->data->right);
				q.deque();
			}
		}
	}

	//void make_array(TreeNode * root, vector<int>&arr, int& ind)
	void make_array(NodeT<T>* root, int*& arr, int& ind)
	{
		Queue<NodeT<T>*> que;
		que.enque(root);
		ind = 0;

		while (!que.isempty())
		{
			NodeT<T>* temp = que.fronte()->data;
			que.deque();

			if (temp)
			{
				if (temp->left)
					que.enque(temp->left);
				if (temp->right)
					que.enque(temp->right);
				arr[ind++] = temp->data;
				//arr.push_back(temp->data);
			}
		}
	}

	void print()
	{
		if (!root)
			return;

		Queue<NodeT<T>*> q;
		q.enque(root);
		NodeT<T>* temp = NULL;
		cout << endl;
		while (!q.isempty())
		{
			temp = q.front->data;
			q.deque();

			if (temp->left)
				q.enque(temp->left);
			if (temp->right)
				q.enque(temp->right);

			cout << temp->data << "  ";
		}
		cout << endl;
	}

	void preorderp(NodeT<T>* root)
	{
		if (!root)
			return;

		cout << root->data << "  ";
		if (root->left)
			preorderp(root->left);
		if (root->right)
			preorderp(root->right);
	}
	void printpre()
	{
		cout << endl;
		preorderp(root);
		cout << endl;
	}

	void inorderp(NodeT<T>* root)
	{
		if (!root)
			return;

		if (root->left)
			inorderp(root->left);
		cout << root->data << "  ";
		if (root->right)
			inorderp(root->right);
	}
	void printin()
	{
		cout << endl;
		inorderp(root);
		cout << endl;
	}
};

//int main()
//{
//	Tree<char> tree;
//
//	tree.insert('a');
//	tree.insert('b');
//	tree.insert('c');
//	tree.insert('d');
//	tree.insert('e');
//	tree.insert('f');
//	tree.insert('g');
//	tree.insert('h');
//	tree.insert('\0');
//	tree.insert('i');
//	tree.insert('\0');
//	tree.insert('j');
//
//
//	tree.print();
//}