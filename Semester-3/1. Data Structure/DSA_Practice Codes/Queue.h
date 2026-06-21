#pragma once
#include <iostream>
#include "Tree.h"
using namespace std;


class Qnode
{
public:
	Node* val;
	Qnode* next;
	Qnode(Node* v = NULL, Qnode* n = NULL)
	{
		val = v;
		next = n;
	}
};

class Queue
{
public:
	Qnode* head, * tail;

	Queue(Qnode* h = NULL, Qnode* t = NULL)
	{
		head = h;
		tail = t;
	}

	bool isEmpty()
	{
		if (!head && !tail)
			return true;
		else
			return false;
	}

	void enqueue(Node* data)
	{
		if (isEmpty())
		{
			head = new Qnode(data);
			tail = head;
			head->next = NULL;
		}
		else
		{
			Qnode* temp = head;
			head = new Qnode(data);
			head->next = temp;
		}
	}

	Node* dequeue()
	{
		if (isEmpty())
			return NULL;
		else if (head == tail)
		{
			Qnode* temp = tail;
			head = tail = NULL;
			return temp->val;
		}
		else
		{
			Qnode* rem = tail, * temp = head;
			while (temp->next != tail)
				temp = temp->next;
			tail = temp;
			tail->next = NULL;
			temp = NULL;
			return rem->val;
		}
	}

	Node* getNode()
	{
		return tail->val;
	}

	void printQue()
	{
		Qnode* curr = head;
		cout << endl;
		while (curr)
		{
			cout << curr->val << "  ";
			curr = curr->next;
		}
		cout << "\n";
	}
};