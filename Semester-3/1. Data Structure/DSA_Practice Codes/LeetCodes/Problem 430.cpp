#include <iostream>
using namespace std;

// Definition for a Node.
class Node 
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(NULL), next(NULL), child(NULL) {}
};

class Solution 
{
public:
    /*Node* flatten(Node* head)
    {
        if (!head)
            return NULL;

        Node* temp = head, * current = head;

        while (!(current->child == NULL && current->next == NULL))
        {
            while (temp->next)
            {
                temp = temp->next;
            }
            while (current->child == NULL && current->next != NULL)
            {
                current = current->next;
            }
            if (current->child == NULL && current->next == NULL)
                break;

            current->child->prev = temp;
            temp->next = current->child;
            current->child = NULL;
        }
        return head;
    }*/

    Node* flatten(Node* head)
    {
        if (!head)
            return NULL;

        Node* temp = head, * curr = head;

        while (!(curr->next == NULL && curr->child == NULL))
        {
            if (curr->child == NULL)
            {
                curr = curr->next;
            }
            else
            {
                curr->child->prev = curr;
                curr = curr->child;
            }
        }
        temp = curr;

        while (temp->prev != NULL)
        {
            while (temp->child == NULL && temp->prev != NULL)
                temp = temp->prev;
            if (temp->child == NULL && temp->prev == NULL)
                break;
            temp->next->prev = curr;
            curr->next = temp->next;
            while (curr->next != NULL)
                curr = curr->next;
            temp->next = temp->child;
            temp->child = NULL;
        }

        return head;
    }
};

void print(Node* head)
{
    Node* temp = head;
    cout << "List: ";
    for (; temp; temp = temp->next)
        cout << temp->val << "  ";
    cout << endl;
}

int main()
{
    // Create the test case as shown in the diagram
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    // Set up the list connections
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    n3->child = n7;
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    n8->child = n11;
    n11->next = n12; n12->prev = n11;

    Solution A;

    // Flatten the list and print it
    Node* flattenedList = A.flatten(n1);

    print(flattenedList);

    return 0;

}