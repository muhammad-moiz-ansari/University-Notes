#include <iostream>
#include <cmath>
//#include "Tree.h"
#include "Basic Codes/BinaryTree.cpp";
//#include "Basic Codes/Queue.cpp"
using namespace std;

template <typename T>
void temptree(NodeT<T>*& root)
{
	root = new NodeT<T>("41", new NodeT<T>("30", new NodeT<T>("21", NULL, new NodeT<T>("27")), new NodeT<T>("36")), new NodeT<T>("65", new NodeT<T>("59")));
}

template <typename T>
void makelargeTree(NodeT<T>*& root)
{
	root = new NodeT<T>("a");

	root->left = new NodeT<T>("b",
		new NodeT<T>("d",
			new NodeT<T>("g"),
			new NodeT<T>("h",
				new NodeT<T>("m"),
				new NodeT<T>("n")
			)
		),
		new NodeT<T>("e",
			new NodeT<T>("i",
				new NodeT<T>("o"),
				new NodeT<T>("p")
			),
			new NodeT<T>("j",
				new NodeT<T>("q"),
				new NodeT<T>("r", new NodeT<T>("g"))
			)
		)
	);

	root->right = new NodeT<T>("c",
		new NodeT<T>("f",
			new NodeT<T>("k",
				new NodeT<T>("s"),
				new NodeT<T>("t")
			),
			new NodeT<T>("l",
				new NodeT<T>("u"),
				new NodeT<T>("v")
			)
		),
		new NodeT<T>("g",
			new NodeT<T>("w"),
			new NodeT<T>("x",
				new NodeT<T>("y"),
				new NodeT<T>("z")
			)
		)
	);
}

template <typename T>
void maketree(NodeT<T>*& root)
{
	root = new NodeT<T>("a");
	root->left = new NodeT<T>("b", new NodeT<T>("d", new NodeT<T>("g")), new NodeT<T>("e", new NodeT<T>("h"), new NodeT<T>("i", new NodeT<T>("l"))));
	root->right = new NodeT<T>("k", NULL, new NodeT<T>("f", new NodeT<T>("j"), new NodeT<T>("c")));
}

template <typename T>
int findHeight(NodeT<T>* root)
{
	if (!root)
		return -1;

	int l = findHeight(root->left);
	int r = findHeight(root->right);

	if (r > l)
		return r + 1;
	else
		return l + 1;
}

string star = "*";

template <typename T>
NodeT<T>* star_tree = new NodeT<T>(star, new NodeT<T>(" "), new NodeT<T>(" "));
template <typename T>
NodeT<T>* space_tree = new NodeT<T>(" ", new NodeT<T>(" "), new NodeT<T>(" "));

void printspaces(int n)
{
	for (int i = 0; i < n; ++i)
		cout << " ";
}

template <typename T>
void printTree(NodeT<T>* root)
{
	Queue<T> Q;
	Q.enqueue(root);
	NodeT<T>* temp = NULL;
	int i = 1, m = 0;
	int h = findHeight(root);
	int H = pow(2, h) - 1;
	H *= 1;			//For double spaces (multiply with larger number)

	while (i < pow(2, h + 1))
	{
		temp = Q.front->data;
		Q.dequeue();

		if (temp->left == NULL)
			Q.enqueue(star_tree);
		else if (temp->left->data == " ")
			Q.enqueue(space_tree);
		else if (temp->left)
			Q.enqueue(temp->left);

		if (temp->right == NULL)
			Q.enqueue(star_tree);
		else if (temp->right->data == " ")
			Q.enqueue(space_tree);
		else if (temp->right)
			Q.enqueue(temp->right);

		if (i == pow(2, m) && m >= 1)
		{
			cout << "\n\n";
			if (m >= 2)
				H /= 2;
			printspaces(H / 2);
			
			++m;
		}
		else
		{
			if (m == 0)
				++m;
			printspaces(H);
		}

		++i;
		cout << temp->data;
	}
}

template <typename T>
NodeT<T>* findInOrderSuccessor(NodeT<T>* root, string target, NodeT<T>*& prev) 
{
	if (!root) return nullptr;

	// Traverse the left subtree
	NodeT<T>* left = findInOrderSuccessor(root->left, target, prev);
	if (left) return left; // Return if found in left subtree

	// Check if previous node is the target (finding successor)
	if (prev->data == target) return root;

	// Mark this node as previous for the next recursion
	prev = root;

	// Traverse the right subtree
	return findInOrderSuccessor(root->right, target, prev);
}
template <typename T>
NodeT<T>* findInOrderPredecessor(NodeT<T>* root, NodeT<T>* target, NodeT<T>*& prev) {
	if (!root) 
		return nullptr;

	// Traverse the left subtree
	NodeT<T>* left = findInOrderPredecessor(root->left, target, prev);
	if (left) 
		return left; // Return if found in left subtree

	// Check if the current node is the target (finding predecessor)
	if (root == target) 
		return prev;

	// Mark this node as previous for the next recursion
	prev = root;

	// Traverse the right subtree
	return findInOrderPredecessor(root->right, target, prev);
}
template <typename T>
string inordersuccessor(NodeT<T>* root, string target)
{
	NodeT<T>* temp = findInOrderSuccessor(root, target, root);
	return temp->data;
}

template <typename T>
void printpreorder(NodeT<T>* root)
{
	if (!root)
		return;

	cout << root->data << "  ";
	printpreorder(root->left);
	printpreorder(root->right);
}

template <typename T>
NodeT<T>* UpdateTree(NodeT<T>* curr, NodeT<T>* pre)
{
	if (curr->left == NULL && curr->right == NULL)
		return curr;

	NodeT<T>* r1 = NULL;
	NodeT<T>* r2 = NULL;
	if (curr->left != NULL)
		r1 = UpdateTree(curr->left, curr);
	if (curr->right != NULL)
		r2 = UpdateTree(curr->right, curr);
	if (r1 == NULL)
		return curr;
	if (r1->left != NULL)
	{
		r1->left->right = r1;
		r1 = r1->left->right;
		r1->left = NULL;
	}

	NodeT<T>* tmp = r1;
	while (tmp->right != NULL)
		tmp = tmp->right;
	tmp->right = curr;
	curr->right = r2;
	curr->left = NULL;
	return r1;
}
template <typename T>
void UpdateTree(NodeT<T>*& root)
{
	if (root != NULL)
	{
		NodeT<T>* pre = NULL;
		root = UpdateTree(root, pre);
	}
}

//
//int main()
//{
//	Tree<char> tree;
//	//maketree(T.root);
//	//makelargeTree(T.root);
//	temptree(tree.root);
//
//	cout << "\nTree:\n";
//	printTree(tree.root);
//	cout << "\n\n";
//
//	//cout << "Inorder Successor: " << inordersuccessor(T.root, "i") << endl;
//
//	UpdateTree(tree.root);
//	cout << "\nUpdated Tree:\n";
//	printTree(tree.root);
//	cout << "\n";
//	printpreorder(tree.root);
//	cout << "\n\n";
//
//
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Previous Code (Working)

//
//#include <iostream>
//#include <cmath>
//#include "Tree.h"
//#include "Queue.h"
//using namespace std;
//
//void temptree(Node*& root)
//{
//	root = new Node("41", new Node("30", new Node("21", NULL, new Node("27")), new Node("36")), new Node("65", new Node("59")));
//}
//
//void makelargeTree(Node*& root)
//{
//	root = new Node("a");
//
//	root->left = new Node("b",
//		new Node("d",
//			new Node("g"),
//			new Node("h",
//				new Node("m"),
//				new Node("n")
//			)
//		),
//		new Node("e",
//			new Node("i",
//				new Node("o"),
//				new Node("p")
//			),
//			new Node("j",
//				new Node("q"),
//				new Node("r", new Node("g"))
//			)
//		)
//	);
//
//	root->right = new Node("c",
//		new Node("f",
//			new Node("k",
//				new Node("s"),
//				new Node("t")
//			),
//			new Node("l",
//				new Node("u"),
//				new Node("v")
//			)
//		),
//		new Node("g",
//			new Node("w"),
//			new Node("x",
//				new Node("y"),
//				new Node("z")
//			)
//		)
//	);
//}
//
//void maketree(Node*& root)
//{
//	root = new Node("a");
//	root->left = new Node("b", new Node("d", new Node("g")), new Node("e", new Node("h"), new Node("i", new Node("l"))));
//	root->right = new Node("k", NULL, new Node("f", new Node("j"), new Node("c")));
//}
//
//int findHeight(Node* root)
//{
//	if (!root)
//		return -1;
//
//	int l = findHeight(root->left);
//	int r = findHeight(root->right);
//
//	if (r > l)
//		return r + 1;
//	else
//		return l + 1;
//}
//
//string star = "*";
//
//Node* star_tree = new Node(star, new Node(" "), new Node(" "));
//
//Node* space_tree = new Node(" ", new Node(" "), new Node(" "));
//
//void printspaces(int n)
//{
//	for (int i = 0; i < n; ++i)
//		cout << " ";
//}
//
//void printTree(Node* root)
//{
//	Queue Q;
//	Q.enqueue(root);
//	Node* temp = NULL;
//	int i = 1, m = 0;
//	int h = findHeight(root);
//	int H = pow(2, h) - 1;
//	H *= 1;			//For double spaces
//
//	while (i < pow(2, h + 1))
//	{
//		temp = Q.dequeue();
//
//		if (temp->left == NULL)
//			Q.enqueue(star_tree);
//		else if (temp->left->data == " ")
//			Q.enqueue(space_tree);
//		else if (temp->left)
//			Q.enqueue(temp->left);
//
//		if (temp->right == NULL)
//			Q.enqueue(star_tree);
//		else if (temp->right->data == " ")
//			Q.enqueue(space_tree);
//		else if (temp->right)
//			Q.enqueue(temp->right);
//
//		if (i == pow(2, m) && m >= 1)
//		{
//			cout << "\n\n";
//			if (m >= 2)
//				H /= 2;
//			printspaces(H / 2);
//
//			++m;
//		}
//		else
//		{
//			if (m == 0)
//				++m;
//			printspaces(H);
//		}
//
//		++i;
//		cout << temp->data;
//	}
//}
//
//Node* findInOrderSuccessor(Node* root, string target, Node*& prev)
//{
//	if (!root) return nullptr;
//
//	// Traverse the left subtree
//	Node* left = findInOrderSuccessor(root->left, target, prev);
//	if (left) return left; // Return if found in left subtree
//
//	// Check if previous node is the target (finding successor)
//	if (prev->data == target) return root;
//
//	// Mark this node as previous for the next recursion
//	prev = root;
//
//	// Traverse the right subtree
//	return findInOrderSuccessor(root->right, target, prev);
//}
//
//Node* findInOrderPredecessor(Node* root, Node* target, Node*& prev) {
//	if (!root)
//		return nullptr;
//
//	// Traverse the left subtree
//	Node* left = findInOrderPredecessor(root->left, target, prev);
//	if (left)
//		return left; // Return if found in left subtree
//
//	// Check if the current node is the target (finding predecessor)
//	if (root == target)
//		return prev;
//
//	// Mark this node as previous for the next recursion
//	prev = root;
//
//	// Traverse the right subtree
//	return findInOrderPredecessor(root->right, target, prev);
//}
//
//string inordersuccessor(Node* root, string target)
//{
//	Node* temp = findInOrderSuccessor(root, target, root);
//	return temp->data;
//}
//
//void printpreorder(Node* root)
//{
//	if (!root)
//		return;
//
//	cout << root->data << "  ";
//	printpreorder(root->left);
//	printpreorder(root->right);
//}
//
//Node* UpdateTree(Node* curr, Node* pre)
//{
//	if (curr->left == NULL && curr->right == NULL)
//		return curr;
//
//	Node* r1 = NULL;
//	Node* r2 = NULL;
//	if (curr->left != NULL)
//		r1 = UpdateTree(curr->left, curr);
//	if (curr->right != NULL)
//		r2 = UpdateTree(curr->right, curr);
//	if (r1 == NULL)
//		return curr;
//	if (r1->left != NULL)
//	{
//		r1->left->right = r1;
//		r1 = r1->left->right;
//		r1->left = NULL;
//	}
//
//	Node* tmp = r1;
//	while (tmp->right != NULL)
//		tmp = tmp->right;
//	tmp->right = curr;
//	curr->right = r2;
//	curr->left = NULL;
//	return r1;
//}
//
//void UpdateTree(Node*& root)
//{
//	if (root != NULL)
//	{
//		Node* pre = NULL;
//		root = UpdateTree(root, pre);
//	}
//}
//
//int main()
//{
//	Tree T;
//	//maketree(T.root);
//	//makelargeTree(T.root);
//	temptree(T.root);
//
//	cout << "\nTree:\n";
//	printTree(T.root);
//	cout << "\n\n";
//
//	//cout << "Inorder Successor: " << inordersuccessor(T.root, "i") << endl;
//
//	UpdateTree(T.root);
//	cout << "\nUpdated Tree:\n";
//	printTree(T.root);
//	cout << "\n";
//	printpreorder(T.root);
//	cout << "\n\n";
//
//
//
//	return 0;
//}