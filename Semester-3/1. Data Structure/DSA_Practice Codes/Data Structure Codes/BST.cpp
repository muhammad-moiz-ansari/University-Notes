#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T val;
	Node<T>* left;
	Node<T>* right;
	Node(T d = 0, Node<T>* l = NULL, Node<T>* r = NULL)
	{
		val = d;
		left = l;
		right = r;
	}
};

template <typename T>
class BST
{
public:
	Node<T>* root;
	BST(Node<T>* r = NULL)
	{
		root = r;
	}

	void insert(T val, Node<T>*& root)
	{
		if (!root)
		{
			root = new Node<T>(val);
			return;
		}
		else if (val < root->val)
			insert(val, root->left);
		else
			insert(val, root->right);
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
			root->val = temp->val;
			remove(temp->val, root->right);
		}
	}

	void remove(T val, Node<T>*& root)
	{
		if (!root)
			return;

		if (val < root->val)
			remove(val, root->left);
		else if (val > root->val)
			remove(val, root->right);
		else
			make_del(root);
	}

	Node<T>* find(T val, Node<T>*& root)
	{
		if (!root || root->val == val)
			return root;
		else if (val < root->val)
			find(val, root->left);
		else
			find(val, root->right);
	}

	void preorder(Node<T>* root)
	{
		if (!root)
			return;

		cout << root->val << "  ";
		if (root->left)
			preorder(root->left);
		if (root->right)
			preorder(root->right);
	}
	void printpre()
	{
		cout << endl;
		preorder(root);
		cout << endl;
	}

	void inorder(Node<T>* root)
	{
		if (!root)
			return;

		if (root->left)
			inorder(root->left);
		cout << root->val << "  ";
		if (root->right)
			inorder(root->right);
	}
	void printin()
	{
		cout << endl;
		inorder(root);
		cout << endl;
	}
};

//int main()
//{
//	BST <int> tree;
//
//	tree.insert(10);
//	tree.insert(20);
//	tree.insert(5);
//	tree.insert(30);
//	tree.insert(25);
//	tree.insert(6);
//	tree.insert(4);
//	tree.insert(22);
//	tree.insert(27);
//	tree.insert(3);
//
//	tree.printpre();

//	tree.remove(4, tree.root);
//	tree.preorder(tree.root);
//	cout << endl;
//	tree.remove(5, tree.root);
//	tree.preorder(tree.root);
//	cout << endl;
//	tree.remove(20, tree.root);
//	tree.preorder(tree.root);
//	cout << endl;
//	tree.remove(10, tree.root);
//	tree.preorder(tree.root);
//	cout << endl;
//	tree.remove(22, tree.root);
//	tree.preorder(tree.root);
//	cout << endl;
//	
//  return 0;
//}