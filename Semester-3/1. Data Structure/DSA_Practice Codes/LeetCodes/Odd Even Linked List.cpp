#include <iostream>
#include "Basic Codes/Single Linked List.cpp"

class Solution {
public:
    Node* oddEvenList(Node* head)
    {
        if (!head || (head && !head->next) || (head && head->next && !head->next->next))
            return head;

        Node* odd = head, * evenprev = head, * even = head->next, * eventemp = even, * last, * lasteven = NULL;
        for (; odd && odd->next && odd->next->next; odd = odd->next->next);
        last = odd;
        if (last->next)
            lasteven = last->next;

        while (even)
        {
            eventemp = even->next;
            if (eventemp == last)
                eventemp = NULL;
            else
                eventemp = eventemp->next;
            evenprev->next = even->next;
            evenprev = evenprev->next;

            odd->next = even;
            odd = odd->next;

            even = eventemp;
        }
        if (lasteven)
            odd->next = lasteven;
        else
            odd->next = NULL;
        return head;
    }
};

int main()
{
    List list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    //list.insert(6);
    list.print();

    Solution sol;
    list.head = sol.oddEvenList(list.head);

    list.print();
}