#include <iostream>
#include <vector>
using namespace std;

//template <typename T>
struct Node
{
//public:
	int val;
	Node* next;

	Node(int d = 0, Node* n = NULL)
	{
		val = d;
		next = n;
	}
};

//template <typename T>
class List
{
public:
	Node* head;

	List()
	{
		head = NULL;
	}
	~List();

	void print()
	{
		Node* temp = head;
		cout << "List: ";
		for (; temp; temp = temp->next)
			cout << temp->val << "  ";
		cout << endl;
	}

	Node* insert(int val, int index)
	{
		if (index < 0)
			return NULL;

		Node* temp = head;

		if (temp != NULL)
			for (int i = 0; temp->next && i < index; ++i, temp = temp->next);

		Node* newnode = new Node;
		newnode->val = val;
		if (temp != NULL)
		{
			newnode->next = temp->next;
			temp->next = newnode;
		}
		else
		{
			newnode->next = temp;
			temp = newnode;
		}
		if (head == NULL)
			head = temp;
		temp = NULL;
		newnode = NULL;

		return head;
	}

	Node* insert(int val)
	{
		Node* temp = head;

		if (temp != NULL)
			while (temp->next)
				temp = temp->next;

		Node* newnode = new Node;
		newnode->val = val;
		if (temp != NULL)
		{
			newnode->next = temp->next;
			temp->next = newnode;
		}
		else
		{
			newnode->next = temp;
			temp = newnode;
		}
		if (head == NULL)
			head = temp;
		temp = NULL;
		newnode = NULL;

		return head;
	}

	//Node* find(int val)
	int find(int val)
	{
		Node* temp = head;
		int index = 0;

		if (temp != NULL)
			for (; temp && temp->val != val; temp = temp->next, index++);

		if (temp == NULL)
			return -1;
		return index;
	}

	Node* deletenode(int val)
	{
		if (head == NULL)
			return NULL;

		Node* t1 = NULL, * current = head;

		for (; current && current->val != val; t1 = current, current = current->next);

		if (current == NULL)
			return NULL;

		if (t1 != NULL)
		{
			t1->next = current->next;
		}
		else
		{
			head = current->next;
		}
		delete current;
		current = NULL;
		t1 = NULL;

		return head;
	}

	void reverse()
	{
		head = reverse(this->head);
	}

	/*Node* reverse(Node* head1)
	{
		if (head1 == NULL)
			return NULL;

		Node* temp = head1;
		int index = 0;
		for (; temp->next; temp = temp->next, ++index);

		Node* thead = head1;

		thead = temp;
		temp = head1;
		Node* slow = head1;

		for (int i = index; i > 0; --i)
		{
			slow = head1;
			temp = head1;
			for (int j = 0; j < i; ++j, slow = temp, temp = temp->next);
			temp->next = slow;
		}
		head1->next = NULL;
		head1 = thead;
		thead = NULL;
		temp = NULL;
		slow = NULL;

		return head1;
	}*/
	Node* reverse(Node*& head1) 
	{
		Node* prev = NULL;
		Node* curr = head1;
		Node* next = NULL;

		while (curr) 
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head1 = prev;
		return head1;
	}

	Node* reverseBetween(Node* head1, int left, int right)
	{
		Node* temp1 = head1, * temp2 = head1, * temp3 = head1, * curr = head1;

		for (int i = 0; i < right; ++i, temp1 = temp2, temp2 = temp2->next);

		temp1->next = NULL;

		for (int i = 1; i < left; ++i, curr = curr->next);

		curr = reverse(curr);
		
		if (left > 1)
		{
			for (int i = 1; i < left - 1; ++i, temp3 = temp3->next);
			temp3->next = curr;
		}
		else
			head1 = curr;

		temp1 = head1;
		for (int i = 1; i < right; ++i, temp1 = temp1->next);
		temp1->next = temp2;

		temp1 = NULL;
		temp2 = NULL;
		curr = NULL;

		return head1;
	}

	Node* rotateRight(Node*& head, int k)
	{
		if (head)
		{
			Node* last = head, * prev = NULL;
			while (last->next)
			{
				prev = last;
				last = last->next;
			}

			if (k >= 2000000000)
				k /= 10;

			for (int i = 0; i < k; ++i)
			{
				last->next = head;
				head = last;
				if (prev)
					prev->next = NULL;
			}
		}
		return head;
	}

	Node* deleteMiddle(Node* head)
	{
		Node* slow = head;
		Node* fast = head;
		Node* prev = slow;

		while (fast)
		{
			if (!fast->next)
				break;
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (head == slow)
			head = slow->next;

		if (prev->next)
		{
			prev->next = slow->next;
			delete slow;
		}

		return head;
	}

	Node* addTwoNumbers(Node* l1, Node* l2)
	{
		Node* curr1 = l1;
		Node* curr2 = l2;
		Node* mainptr;

		//Setting curr pointer:
		while (curr1 && curr2)
		{
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		if (curr1)
		{
			mainptr = l1;
			curr1 = l1;
			curr2 = l2;
		}
		else
		{
			mainptr = l2;
			curr2 = l1;
			curr1 = l2;
		}
		int carry = 0;
		//Adding now:
		while (curr1)
		{
			if (curr2)
				curr1->val += curr2->val + carry;
			else
				curr1->val += carry;

			carry = 0;
			if (curr1->val > 9)
			{
				curr1->val -= 10;
				carry = 1;
			}
			if (curr2)
				curr2 = curr2->next;
			if (curr1->next == NULL && carry)
			{
				curr1->next = new Node(0, NULL);
			}
			curr1 = curr1->next;
		}
		return mainptr;
	}

	/*ListNode* partition(ListNode* head, int x)
	{
		ListNode* curr = head;
		while (curr->val != x && curr)
			curr = curr->next;

	}*/

	Node* mergeInBetween(Node* list1, int a, int b, Node* list2)
	{
		if (!list1)
			return list1;

		Node* prev = list1;
		Node* curra = list1;
		Node* currb = list1;
		Node* curr2 = list2;

		int i = 0;
		while (curra->next && currb->next)
		{
			if (i < a)
			{
				prev = curra;
				curra = curra->next;
			}
			if (i == b)
				break;
			currb = currb->next;
			++i;
		}
		//Joining sec list
		if (list2)
		{
			while (curr2->next)
				curr2 = curr2->next;
			prev->next = list2;
			curr2->next = currb->next;
		}
		//Removing list
		prev = curra;
		while (curra != currb)
		{
			curra = curra->next;
			delete prev;
			prev = curra;
		}
		delete prev;

		return list1;
	}

	/*Node* mergeKLists(vector<Node*>& lists)
	{
		int size = lists.size();
		if (size == 0)
			return NULL;

		Node* head;
		Node* temp, * temp2;
		int index = 0, ind = 0;
		bool b = 0;
		for (int i = 0; i < size; ++i)
		{
			if (lists[i] && lists[index])
			{
				if (lists[i]->val < lists[index]->val)
					index = i;
				b = 1;
			}
			else if (index == i)
				++index;
		}
		if (!b)
			return NULL;

		head = lists[index];

		bool empty = 1;
		while (b)
		{
			empty = 1;
			ind = 0;
			if (ind == index)
				++ind;
			if (ind >= size)
				return head;

			for (int i = 0; i < size; ++i)
			{
				if (i == index)
					continue;
				if (lists[i])
				{
					if (!lists[ind] || ind == index)
					{
						++ind;

						if (ind >= size)
						{
							empty = 1;
							break;
						}
						--i;
						continue;
					}
					if (lists[i]->val < lists[ind]->val)
						ind = i;
					empty = 0;
				}
			}
			if (empty)
				break;
			if (lists[index]->next)
				while (lists[index]->next->val <= lists[ind]->val)
				{
					lists[index] = lists[index]->next;
					if (!lists[index]->next)
						break;
				}
			temp = lists[index]->next;
			temp2 = lists[ind]->next;
			lists[index]->next = lists[ind];
			lists[ind]->next = temp;
			lists[index] = lists[index]->next;
			lists[ind] = temp2;
		}
		return head;
	}*/
	Node* bubblesort(Node* curr, int size)
	{
		Node* temp = curr;
		bool b;
		for (int i = 0; i < size; ++i)
		{
			temp = curr;
			b = 1;
			for (int j = 0; j < size - i - 1; ++j, temp = temp->next)
			{
				if (temp->val > temp->next->val)
				{
					int t = temp->val;
					temp->val = temp->next->val;
					temp->next->val = t;
					b = 0;
				}
			}
			if (b)
				break;
		}
		return curr;
	}

	Node* mergeKLists(vector<Node*>& lists)
	{
		int size = lists.size(), s = 0;

		if (size == 0)
			return NULL;

		bool empty = 1, lempty = 1, done = 0;
		Node* head = NULL;
		for (int i = 0; i < size; ++i)
		{
			if (!done && lists[i])
			{
				head = lists[i];
				done = 1;
			}
			lempty = 1;
			if (lists[i])
			{
				while (lists[i]->next)
				{
					lists[i] = lists[i]->next;
					++s;
				}
				empty = 0;
				lempty = 0;
			}
			if (lempty)
				continue;
			if (i < size - 1)
			{
				if (lists[i + 1])
					lists[i]->next = lists[i + 1];
				++s;
			}
			else
			{
				lists[i]->next = NULL;
				++s;
			}
		}
		if (empty)
			return NULL;

		head = bubblesort(head, s);

		return head;
	}
};




int main()
{
	List A;

	A.insert(1);
	A.insert(4);
	A.insert(5);
	A.insert(6, 3);
	A.insert(9, 4);
	A.insert(5, 5);
	//A.insert(7, 6);
	A.print();
	A.rotateRight(A.head, 1);
	cout << "\nA ";
	A.print();

	List B;

	B.insert(1);
	B.insert(3);
	B.insert(4);
	//B.insert(9, 3);
	cout << "\nB ";
	B.print();

	List C;
	C.insert(2);
	C.insert(6);
	//C.insert(2);
	//C.insert(3);
	cout << "\nC ";
	C.print();

	//cout << "Val 1 is at " << A.find(1) << endl;

	//A.reverse();
	
	//int left = 1, right = 2;
	//A.head = A.reverseBetween(A.head, left, right);

	//A.deleteMiddle(A.head);

	//C.head = C.addTwoNumbers(A.head, B.head);
	vector<Node*> lists = { A.head, B.head, C.head };

	A.head = A.mergeKLists(lists);
	B.head = NULL;
	C.head = NULL;

	cout << "Merged: ";
	A.print();
}
//
//int main() {
//	//// Creating the first list [-8,-7,-7,-5,1,1,3,4]
//	List list1;
//	//list1.insert(-8);
//	//list1.insert(-7);
//	//list1.insert(-7);
//	//list1.insert(-5);
//	//list1.insert(1);
//	//list1.insert(1);
//	//list1.insert(3);
//	//list1.insert(4);
//
//	//// Creating the second list [-2]
//	List list2;
//	//list2.insert(-2);
//
//	//// Creating the third list [-10,-10,-7,0,1,3]
//	//List list3;
//	//list3.insert(-10);
//	//list3.insert(-10);
//	//list3.insert(-7);
//	//list3.insert(0);
//	//list3.insert(1);
//	//list3.insert(3);
//
//	//// Creating the fourth list [2]
//	//List list4;
//	//list4.insert(2);
//
//	list1.insert(2);
//	list2.insert(-1);
//
//	// For debugging: print all lists
//	cout << "List 1: "; list1.print();
//	cout << "List 2: "; list2.print();
//	//cout << "List 3: "; list3.print();
//	//cout << "List 4: "; list4.print();
//
//	// You can now use these lists in the mergeKLists function
//	//vector<Node*> lists = { list1.head, list2.head, list3.head, list4.head };
//	vector<Node*> lists = { list1.head, NULL, list2.head };
//
//	// Optionally, call your merge function here (if implemented)
//	list1.head = list1.mergeKLists(lists);
//
//	cout << "List: "; list1.print();
//
//	list2.head = NULL;
//	//list3.head = NULL;
//	//list4.head = NULL;
//
//	return 0;
//}

List::~List()
{
	if (head != NULL)
	{
		do {
			Node* temp = head->next;
			delete head;
			head = temp;
		} while (head);
	}
}