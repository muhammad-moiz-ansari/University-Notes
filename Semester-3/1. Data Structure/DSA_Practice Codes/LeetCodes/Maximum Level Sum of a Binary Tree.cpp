#include <iostream>
//#include "Basic Codes/Queue.cpp";
//#include "Basic Codes/BinaryTree.cpp";
#include "D:\Documents\Semester-3\1. Data Structure\DSA_Practice Codes\Basic Codes\BinaryTree.cpp"
#include <queue>
#include <cmath>

//#include "Print Tree.cpp"
using namespace std;

//template <typename T>
//int maxLevelSum(NodeT<T>* root)
//{
//	Queue<NodeT<T>*> Q;
//	Q.enque(root);
//	NodeT<T>* temp = NULL;
//	int i = 1, m = 0, sum1 = 0, sum2 = 0, level = 1;
//	while (!Q.isempty())
//	{
//		temp = Q.front->data;
//		Q.deque();
//
//		if (temp->left)
//			Q.enque(temp->left);
//		if (temp->right)
//			Q.enque(temp->right);
//
//		
//		if (i == pow(2, m) && m >= 1)
//		{
//			if (sum2 < sum1)
//			{
//				sum2 = sum1;
//				level = m;
//			}
//			++m;
//			sum1 = 0;
//		}
//		else if (m == 0)
//			++m;
//		
//		++i;
//		sum1 += temp->data;
//	}
//	return level;
//}


int findHeight(NodeT<int>* root)
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

//int maxLevelSum(NodeT<int>* root)
//{
//	queue<NodeT<int>*> Q;
//	Q.push(root);
//	NodeT<int>* temp = NULL;
//	int i = 1, m = 0, h = findHeight(root), sum = 0, maxsum = root->data, level = 1;
//	bool summed = 0;
//	//while (!Q.empty())
//	while (i < pow(2, h) + h + 1)
//	{
//		temp = Q.front();
//		Q.pop();
//
//		if (temp && temp->left)
//			Q.push(temp->left);
//		else
//			Q.push(NULL);
//		if (temp && temp->right)
//			Q.push(temp->right);
//		else
//			Q.push(NULL);
//
//		
//		if (i == pow(2, m) && m >= 1)
//		{
//			if (sum > maxsum)
//			{
//				maxsum = sum;
//				level = m;
//			}
//			++m;
//			summed = 0;
//			sum = 0;
//		}
//		else if (m == 0)
//			++m;
//		
//		++i;
//		if (temp)
//		{
//			sum += temp->data;
//			summed = 1;
//		}
//	}
//	if (sum > maxsum && summed)
//		level = m;
//	
//	return level;
//}

////////////////////////////////  BFS Approach (Depth Calculate)  //////////////////////////////////

//void findDepth(NodeT<int>* curr, NodeT<int>*& target, int level, int size, bool& b, int& ans)
//{
//	if (!curr)
//		return;
//	if (curr == target)
//	{
//		b = 0;
//		ans = level;
//		return;
//	}
//
//	if (size == level && b)
//		++size;
//
//	if (b)
//		findDepth(curr->left, target, level + 1, size, b, ans);
//	if (b)
//		findDepth(curr->right, target, level + 1, size, b, ans);
//}
//
//int maxLevelSum(NodeT<int>* root)
//{
//	queue<NodeT<int>*> Q;
//	Q.push(root);
//	NodeT<int>* temp = NULL;
//	int currl = 0, lvlc = 0, H = findHeight(root), sum = 0, maxsum = root->data, level = 1;
//	bool b = 1;
//	while (!Q.empty())
//	{
//		temp = Q.front();
//		Q.pop();
//
//		if (temp && temp->left)
//			Q.push(temp->left);
//		if (temp && temp->right)
//			Q.push(temp->right);
//
//		b = 1;
//		findDepth(root, temp, 0, 0, b, currl);
//		if (currl == lvlc && lvlc > 0)
//		{
//			if (sum > maxsum)
//			{
//				maxsum = sum;
//				level = currl;
//			}
//			++lvlc;
//			sum = 0;
//		}
//		else if (lvlc == 0)
//			++lvlc;
//
//		sum += temp->data;
//	}
//	if (sum > maxsum)
//		level = lvlc;
//
//	return level;
//}

///////////////////////////////  BFS Approach  //////////////////////////////////

int maxLevelSum(NodeT<int>* root)
{
	queue<NodeT<int>*> Q;
	Q.push(root);
	NodeT<int>* temp = NULL;
	int num = 1, sum = 0, maxsum = root->data, level = 1, currl = 1;
	bool b = 1;

	while (!Q.empty())
	{
		num = Q.size();
		sum = 0;
		for (int i = 0; i < num; ++i)
		{
			temp = Q.front();
			Q.pop();

			if (temp && temp->left)
				Q.push(temp->left);
			if (temp && temp->right)
				Q.push(temp->right);
			
			sum += temp->data;
		}
		if (sum > maxsum)
		{
			maxsum = sum;
			level = currl;
		}
		++currl;
	}
	return level;
}

///////////////////////////////  DFS Approach  //////////////////////////////////

//void dfs(NodeT<int>* root, int level, vector<int>& sums)
//{
//	if (!root)
//		return;
//
//	if (sums.size() == level)
//		sums.push_back(root->data);
//	else
//		sums[level] += root->data;
//
//	dfs(root->left, level + 1, sums);
//	dfs(root->right, level + 1, sums);
//}
//
//int maxLevelSum(NodeT<int>* root)
//{
//	if (!root)
//		return 0;
//	int level = 1, maxsum = 0;
//	vector<int> sums;
//
//	dfs(root, 0, sums);
//
//	maxsum = sums[0];
//	for (int i = 0; i < sums.size(); ++i)
//		if (sums[i] > maxsum)
//		{
//			maxsum = sums[i];
//			level = i + 1;
//		}
//
//	return level;
//}


int main()
{
	Tree <int> tree;

	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	//tree.insert(4);
	//tree.insert(5);
	//tree.insert(6);
	//tree.insert(7);
	//tree.insert(8);
	//tree.insert(9);
	//tree.insert(10);
	//tree.insert(11);
	//tree.insert(12);

	//delete tree.root->left->left;
	//delete tree.root->left->right;
	//tree.root->left->left = NULL;
	//tree.root->left->right = NULL;

	tree.print();

	cout << "Level: " << maxLevelSum(tree.root) << endl;

	////////////////////////////////////////////

	Tree <int> tree2;

	tree2.insert(1);
	tree2.insert(1);
	tree2.insert(0);
	tree2.insert(7);
	tree2.insert(-8);
	tree2.insert(-7);
	tree2.insert(9);
	//tree2.insert(8);
	tree2.print();

	cout << "Level: " << maxLevelSum(tree2.root) << endl;

}