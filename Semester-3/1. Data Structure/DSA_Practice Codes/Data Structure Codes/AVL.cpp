#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node<T>* left;
	Node<T>* right;
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL)
	{
		data = d;
		left = l;
		right = r;
	}
};

template <typename T>
class AVL
{
public:
	Node<T>* root;
	AVL(Node<T>* r = NULL)
	{
		root = r;
	}

	int height(Node<T>* root)
	{
		if (!root)
			return -1;

		int l = height(root->left);
		int r = height(root->right);

		if (r > l)
			return r + 1;
		else
			return l + 1;
	}

	void leftRotation(Node<T>*& root)
	{
		Node<T>* K = root->right;
		root->right = K->left;
		K->left = root;
		root = K;
	}

	void rightRotation(Node<T>*& root)
	{
		Node<T>* K = root->left;
		root->left = K->right;
		K->right = root;
		root = K;
	}

	void insert(T val, Node<T>*& root)
	{
		if (!root)
		{
			root = new Node<T>(val);
		}
		else if (val < root->data)
		{
			insert(val, root->left);	//Left may be heavy
			if (height(root->left) - height(root->right) == 2)
			{
				if (height(root->left->left) - height(root->left->right) == 1)
					rightRotation(root);
				else
				{
					leftRotation(root->left);
					rightRotation(root);
				}
			}
		}
		else
		{
			insert(val, root->right);	//Right may be heavy
			if (height(root->right) - height(root->left) == 2)
			{
				if (height(root->right->right) - height(root->right->left) == 1)
					leftRotation(root);
				else
				{
					rightRotation(root->right);
					leftRotation(root);
				}
			}
		}
	}
	void insert(T val)
	{
		insert(val, root);
	}

	void make_del(Node<T>*& root)
	{
		Node<T>* temp = root;
		if (!root->right)
		{
			root = root->left;
			delete temp;
		}
		else if (!root->left)
		{
			root = root->right;
			delete temp;
		}
		else
		{
			temp = root->right;
			while (temp && temp->left)
				temp = temp->left;
			root->data = temp->data;
			remove(temp->data, root->right);
		}
	}

	void remove(T val, Node<T>*& root)
	{
		if (!root)
			return;

		if (val < root->data)
			remove(val, root->left);
		else if (val > root->data)
			remove(val, root->right);
		else
			make_del(root);

		if (root)
		{
			if (height(root->left) - height(root->right) == 2)
			{
				if (height(root->left->left) - height(root->left->right) >= 1)
					rightRotation(root);
				else
				{
					leftRotation(root->left);
					rightRotation(root);
				}
			}
			else if (height(root->right) - height(root->left) == 2)
			{
				if (height(root->right->right) - height(root->right->left) >= 1)
					leftRotation(root);
				else
				{
					rightRotation(root->right);
					leftRotation(root);
				}
			}
		}
	}

	void preorder(Node<T>* root)
	{
		if (!root)
			return;

		cout << root->data << "  ";
		if (root->left)
			preorder(root->left);
		if (root->right)
			preorder(root->right);
	}
};

int main()
{
	AVL <int> tree;

	tree.insert(14);
	tree.insert(28);
	tree.insert(18);
	tree.insert(15);
	tree.insert(10);
	tree.insert(12);
	tree.insert(3);
	tree.insert(7);
	tree.insert(6);
	tree.insert(9);
	tree.insert(2);
	tree.insert(4);

	cout << endl;
	tree.preorder(tree.root);
	cout << endl;

	tree.remove(4, tree.root);
	tree.preorder(tree.root);
	cout << endl;
	tree.remove(6, tree.root);
	tree.preorder(tree.root);
	cout << endl;
	tree.remove(2, tree.root);
	tree.preorder(tree.root);
	cout << endl;
	tree.remove(15, tree.root);
	tree.preorder(tree.root);
	cout << endl;
	tree.remove(28, tree.root);
	tree.preorder(tree.root);
	cout << endl;

}