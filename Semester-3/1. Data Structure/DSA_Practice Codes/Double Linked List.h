#pragma once

using namespace std;

template <typename T>
struct Node
{
	// Try adding an index too
	T value;
	Node* next = NULL;
	Node* prev = NULL;
};

//Doubly Linked List

template <typename T>
class CustomList
{
public:

	CustomList()
	{
		Node<T>* head = NULL;
		int capacity = 0;
	}

	void insert_object(T val) 
	{
		if(head!=NULL)
		{
			Node<T>* temp = head;
			while (1)
			{
				if (temp->next == NULL)
				{
					temp->next = new Node<T>;
					temp->next->value = val;
					temp->next->prev = temp;
					capacity += 1;
					break;
				}
				temp = temp->next;
			}
		}
		else 
		{
			head = new Node<T>;
			head->next = new Node<T>;
			head->next->value = val;
			head->next->prev = head;

			capacity += 1;
		}
	
	}

	void InsertBefore(T val,T adder) 
	{
		Node<T>* ptr = head;
		while(1)
		{
			if (ptr->next == NULL)
				break;
			else if (ptr->next->value == val)
			{
				Node<T>* to_be_inserted = new Node<T>;
				to_be_inserted->value = adder;
				to_be_inserted->next = ptr->next;
				to_be_inserted->prev = ptr;
				ptr->next = to_be_inserted;
				to_be_inserted->next->prev = to_be_inserted;
				capacity += 1;
				break;
			}
	
			ptr = ptr->next;
		}
		
	}

	void InsertAfter(T val,T adder) 
	{
		bool b = false;
		Node<T>* ptr = head;
		while (1)
		{
			if (ptr->next == NULL)
			{
				if(ptr->value == val)
				{
					insert_object(adder);
				}
				break;
			}
			else if (ptr->value == val)
			{
				if(ptr->next != NULL)
				{
					Node<T>* to_be_inserted = new Node<T>;
					to_be_inserted->value = adder;
					to_be_inserted->next = ptr->next;
					to_be_inserted->prev = ptr;
					ptr->next = to_be_inserted;
					to_be_inserted->next->prev = to_be_inserted;
					capacity += 1;
				}

				break;
			}

			ptr = ptr->next;
		}
	}

	void Remove(T val) 
	{
		Node<T>* ptr = head;
		while (1) 
		{
			if (ptr->next == NULL)
			{
				break;
			}
			else if (ptr->next->value == val)
			{
				Node<T>* temp = NULL;
				temp = ptr->next;
				
				if(ptr->next->next != NULL)
				{
					ptr->next = ptr->next->next;
					ptr->next->prev = ptr;
				}
				else 
				{
					ptr->next = NULL;
				}
				delete temp;
				capacity -= 1;
				break;
			}
			ptr = ptr->next;
		}
		
	
	}

	void RemoveBefore(T val) 
	{
		Node<T>* temp = head;
		while (1) 
		{
			if (temp->next == NULL)
				break;
		
			if (temp->next->value == val)
			{
				Remove(temp->value);
				break;
			}
		
			temp = temp->next;
		}
	
	}

	void RemoveAfter(T val) 
	{
		Node<T>* temp = head;
		while (1)
		{
			if (temp->next == NULL)
				break;

			if (temp->value == val)
			{
				Remove(temp->next->value);
				break;
			}

			temp = temp->next;
		}
	}

	//removes all duplicates of every element
	void RemoveDup() 
	{
		bool b = false;
		Node<T>* outer_temp = head;
		while (1) 
		{
			b = false;
			if (outer_temp->next == NULL)break;

			Node<T>* inner_temp = head;
			while (1)
			{
				if (inner_temp->next == NULL)break;

				if((outer_temp->next->value == inner_temp->next->value) && (outer_temp != inner_temp))
				{
					T yes = inner_temp->next->value;
					Remove(yes);
					b = true;
					break;
				}
				inner_temp = inner_temp->next;
			}
			if(!b)
			outer_temp = outer_temp->next;
		}	
	}

	//returns the # of instances of val
	int CheckInstance(T val) 
	{
		int count = 0;
		Node<T>* temp = head;
		while (1)
		{
			if (temp->next == NULL)break;

			if (val == temp->next->value)
			{
				count += 1;
			}
				temp = temp->next;
		}
		cout << '\n' << '\"' << val << '\"' << " has occured " << count << " time(s).\n";
		return count;
	}

	//removes all duplicates of val
	void RemoveDup(T val) 
	{
		int count = CheckInstance(val);
		int check = count;
		bool b = false;
		Node<T>* temp = head;
		while (1)
		{
			b = false;
			if (temp->next == NULL)break;

			if (val == temp->next->value)
			{
				if (count == 1)break;

				T yes = temp->next->value;
				Remove(yes);
				b = true;
				count -= 1;

			}
			if (!b)
				temp = temp->next;

		}
	}

	void print_forward() 
	{
	
		cout << "\nCapacity : " << capacity;
		cout << "\nForward Printing initiated : \n";

		if (head == NULL)
		{
			cout << "\nEmpty List!!\n";
			return;
		}
		int cap = capacity;
		Node<T>* ptr = head;
		while (cap>0) 
		{
			cout << ptr->value<<'\n';
			ptr = ptr->next;
			cap -= 1;
		}
	
	}

	void print_backward()
	{
		cout << "\nCapacity : " << capacity;
		cout << "\nBackward Printing initiated : \n";
		Node<T>* save = head;

		if (head == NULL)
		{
			cout << "\nEmpty List!!\n";
			return;
		}

		while (save->next != NULL)
		{
			save = save->next;
		}

		int cap = capacity;
		Node<T>* temp = save;
		while (cap>0)
		{
			cout << temp->value << '\n';
			temp = temp->prev;
			cap -= 1;
		}
	}

	void Erase_From_Memory_front()
	{
		Node<T>* temp = NULL;
		Node<T>* temp2 = NULL;
		temp = head;
		temp2 = head->next;
		while (capacity>0)
		{
			temp = temp2;
			temp2 = temp2->next;
			delete temp;
			capacity -= 1;
		}
		head = NULL;
		cout << "\nForward Deletion Completed!\n";
	}

	void Erase_From_Memory_back()
	{
		Node<T>* save = head;
		int cap = capacity;
		while (cap > 0)
		{
			save = save->next;
			cap -= 1;
		}


		Node<T>* temp = NULL;
		Node<T>* temp2 = NULL;
		temp = save;
		temp2 = save->prev;
		while (capacity > 0)
		{
			temp = temp2;
			temp2 = temp2->prev;
			delete temp;
			capacity -= 1;
		}

		head = NULL;
		cout << "\nBackward Deletion Completed!\n";
	}


};