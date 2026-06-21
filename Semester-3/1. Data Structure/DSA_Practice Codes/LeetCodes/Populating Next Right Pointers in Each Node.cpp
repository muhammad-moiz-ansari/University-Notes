#include <iostream>
//#include "Basic Codes/Queue.cpp";
#include "Basic Codes/BinaryTree.cpp";
#include <queue>

//#include "Print Tree.cpp"
using namespace std;


NodeT<int>* connect(NodeT<int>* root)
{
	if (!root)
		return NULL;
	queue<NodeT<int>*> Q;
	Q.push(root);
	NodeT<int>* temp = root, * t1 = root, * t2 = root;
	int i = 1, m = 0;

	bool b = 0, wait = 0;
	while (temp)
	{
		if (!Q.empty())
		{
			temp = Q.front();
			Q.pop();

			if (temp->left)
				Q.push(temp->left);
			if (temp->right)
				Q.push(temp->right);
		}
		else
			temp = NULL;

		if (i == pow(2, m) && m >= 1)
		{
			++m;
			wait = 1;
		}
		else if (m == 0)
			++m;

		if (b)
			t1->next = t2;
		else if (m >= 2 && i >= 4)
			b = 1;
		if (wait)
		{
			wait = 0;
			b = 0;
		}

		++i;
		t1 = t2;
		t2 = temp;
		if (m == 2 && i == 4)
			b = 1;
	}
	return root;
}

int main()
{
	Tree <int> tree;

	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.print();

	tree.root = connect(tree.root);
	tree.print();
	cout << endl;

	////////////////////////////////////////////
}