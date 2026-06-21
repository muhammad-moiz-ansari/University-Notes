#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	string data;
	Node* left;
	Node* right;

	Node(string d = "", Node* l = NULL, Node* r = NULL)
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
	Node* root;
	Tree(Node* r = NULL)
	{
		root = r;
	}
};