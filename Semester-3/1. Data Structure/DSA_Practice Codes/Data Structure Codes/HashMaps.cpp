#include <iostream>
#include <cmath>
using namespace std;

class NodeO
{
public:
	int key;
	int val;
	NodeO* next;
	NodeO(int k = 0, int v = 0, NodeO* n = NULL)
	{
		key = k;
		val = v;
		next = n;
	}
};

class Hashmap_open
{
public:
	int capacity;
	NodeO** arr;
	Hashmap_open(int c = 5)
	{
		capacity = c;
		arr = new NodeO * [capacity];
		for (int i = 0; i < capacity; ++i)
			arr[i] = NULL;
	}
	int hashfunc(int key)
	{
		return key % capacity;
	}

	void insert(int key, int val)
	{
		int k = hashfunc(key);

		if (!arr[k])
		{
			arr[k] = new NodeO(key, val);
			return;
		}
		NodeO* temp = arr[k];

		for (; temp->next; temp = temp->next);
		temp->next = new NodeO(key, val);
		temp = NULL;
	}

	void remove(int key)
	{
		int k = hashfunc(key);
		
		NodeO* temp = arr[k], * prev = arr[k];
		for (; temp && temp->key != key; prev = temp, temp = temp->next);

		if (!temp)
			return;
		if (temp == arr[k])
		{
			arr[k] = arr[k]->next;
			delete[] temp;
		}
		else
		{
			prev->next = temp->next;
			delete[] temp;
		}
		prev = temp = NULL;
	}

	void print()
	{
		NodeO* temp = NULL;
		for (int i = 0; i < capacity; ++i)
		{
			cout << endl << i << ": ";
			temp = arr[i];
			for (; temp; temp = temp->next)
				cout << temp->val << "  ";
		}
		cout << endl;
	}
};



class NodeC
{
public:
	int val;
	bool isfill;
	NodeC(int v = 0, bool fill = 0)
	{
		val = v;
		isfill = fill;
	}
};

class Hashmap_closed
{
public:
	int capacity;
	int count;
	NodeC* arr;
	Hashmap_closed(int c = 5)
	{
		capacity = c;
		arr = new NodeC [c];
		count = 0;
	}
	int hashfunc(int key)
	{
		return key % capacity;
	}
	int hashprobequad(int key, int& i)
	{
		return hashfunc(key + pow(2, i++));
	}
	int hashprobelin(int key, int& i)
	{
		return hashfunc(key + i++);
	}
	void insert(int key, int val)
	{
		if (count >= capacity)
		{
			NodeC* temp = arr;
			capacity *= 2;
			arr = new NodeC[capacity];
			for (int i = 0; i < capacity / 2; ++i)
			{
				arr[i].val = temp[i].val;
				arr[i].isfill = temp[i].isfill;
			}
			delete[] temp;
			temp = NULL;
		}

		int i = 0, k = hashfunc(key), qcount = 0;
		while (arr[k].isfill == 1)
		{
			if (qcount > capacity * 2)
				break;
			k = hashprobequad(key, i);
			++qcount;
		}
		while (arr[k].isfill == 1)
			k = hashprobelin(key, i);
		arr[k].val = val;
		arr[k].isfill = 1;
		++count;
	}

	void remove(int key)
	{
		key = hashfunc(key);
		if (arr[key].isfill)
		{
			arr[key].isfill = 0;
			--count;
		}
	}

	void print()
	{
		for (int i = 0; i < capacity; ++i)
		{
			if (arr[i].isfill)
				cout << endl << i << ": " << arr[i].val;
		}
		cout << endl;
	}
};


int main()
{
	Hashmap_closed hash(5);

	hash.insert(0, 1);
	hash.insert(0, 2);
	hash.insert(0, 3);
	hash.insert(0, 4);
	hash.insert(0, 5);
	hash.insert(0, 6);
	hash.insert(0, 3);
	hash.insert(0, 4);
	hash.insert(0, 5);
	hash.insert(0, 6);
	hash.insert(0, 7);
	hash.insert(232, 8);
	hash.insert(4, 5);

	hash.print();

	cout << "\nRemove";
	hash.remove(9);
	hash.print();
	hash.remove(34);
	hash.print();
	hash.remove(3);
	hash.print();
	hash.remove(7);
	hash.print();
}