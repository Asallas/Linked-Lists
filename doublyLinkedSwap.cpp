#include "doublyLinkedSwap.h"

#include <iostream>
#include <string>
#include <sstream>
// Implement the following function:
// p and afterp are pointers to the nodes to be swapped.
void swapWithNext(Node* p)
{
    if (p == nullptr) {
        return;
    }
    else {
        Node* afterp = p->next;
        Node* temp = p->prev;

        if (afterp == nullptr || afterp->next == nullptr || temp == nullptr) {
            return;
        }

        if (afterp->next != nullptr) {
            afterp->next->prev = p;
        }
        temp->next = afterp;
        afterp->prev = temp;
        p->prev = afterp;
        p->next = afterp->next;
        afterp->next = p;
    }
    
    
}


//Converts an array to a doubly linked list
Node* arrayToList(int array[], int size)
{
    Node* head;
    Node* p;
    int pos = 0;
    if (size > 0)
    {
        head = new Node();
        head->prev = nullptr;
        head->value = 0;
        p = head;
        while (pos < size)
        {
            p->next = new Node();
            p->next->prev = p;
            p = p->next;
            p->value = array[pos];
            pos++;
        }
        p->next = new Node();
        p->next->prev = p;
        p = p->next;
        p->value = 0;
        p->next = nullptr;
    }
    else
    {
        return nullptr;
    }
    return head;
}

//Return pointer to end of the list
Node* getTail(Node* head)
{
    Node* p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p;
}

//Return pointer to node with "index"
//First node "index" 0, second node "index" 1, ...
Node* getNode(Node* head, int index)
{
    int pos = 0;
    Node* p = head->next;
    if (pos == index)
    {
        return p;
    }
    else if (index < 0)
    {
        return head;
    }
    else
    {
        while (pos < index && p->next != nullptr)
        {
            p = p->next;
            pos++;
        }
    }
    return p;
}

//Print list forwards from start
void printForwards(Node* head)
{
    Node* p = head->next;
    while (p->next != nullptr)
    {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

//Print list backwards from end
void printBackwards(Node* tail)
{
    Node* p = tail->prev;
    while (p->prev != nullptr)
    {
        cout << p->value << " ";
        p = p->prev;
    }
    cout << endl;
}