#pragma once
/*
 * Name: Armando Sallas
 * Date Submitted: 1/28/2023
 * Lab Section: 005
 * Assignment Name: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List {

private:
    Node<T>* start; //pointer to the first node in this list
    int mySize;  //size (or length) of this list

public:
    List();
    ~List();
    int size();
    bool empty();
    void insertStart(T);
    void insertEnd(T);
    void insertAt(T, int);
    void removeStart();
    void removeEnd();
    void removeAt(int);
    T getFirst();
    T getLast();
    T getAt(int);
    int find(T);

    //Print the name and this list's size and values to stdout
    //This function is already implemented (no need to change it)
    void print(string name) {
        cout << name << ": ";
        cout << "size = " << size();
        cout << ", values = ";
        Node<T>* iterator = start;
        while (iterator != nullptr) {
            cout << iterator->value << ' ';
            iterator = iterator->next;
        }
        cout << endl;
    }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List() {
    start = nullptr;
    mySize = 0;

}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List() {
    Node<T>* temp = start;
    if (temp != nullptr) {
        while (temp->next != nullptr) {
            Node<T>* prev = temp;
            temp = temp->next;
            delete prev;
        }
    }
    
    delete temp;

}

//Return the size of this list
template <class T>
int List<T>::size() {
    Node<T>* temp = start;
    int count = 1;

    if (temp == nullptr) {
        return 0;
    }
    else {
        while (temp->next != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    

}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty() {
    if (start == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value) {
    Node<T>* i = new Node<T>(value);

    i->next = start;

    start = i;

    return;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value) {
    Node<T>* i = new Node<T>(value);
    Node<T>* temp = start;

    if (temp == nullptr) {
        start = i;
        return;
    }
    i->next = nullptr;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = i;

    return;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j) {
    Node<T>* i = new Node<T>(value);
    Node<T>* temp = start;
    if (j == 0) {
        i->next = start;

        start = i;

        return;
    }
    for (int k = 0; k < j - 1; k++) {
        temp = temp->next;
    }

    i->next = temp->next;

    temp->next = i;

    return;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart() {
    Node<T>* temp = start;

    start = start->next;
    delete temp;

    return;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd() {
    Node<T>* last = start;
    Node<T>* secondLast = start;

    while (last->next != nullptr) {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = nullptr;
    delete last;

    return;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j) {
    Node<T>* temp = start;
    Node<T>* temp2 = start;
    for (int i = 0; i < j; i++) {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;

    delete temp;
    return;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst() {
    return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast() {
    Node<T>* temp = start;

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp->value;
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j) {
    Node<T>* temp = start;

    for (int i = 0; i < j; i++) {
        temp = temp->next;
    }

    return temp->value;
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key) {
    Node<T>* temp = start;
    int count = 0;
    while (temp->next != nullptr) {
        if (temp->value == key) {
            return count;
        }
        else {
            count++;
            temp = temp->next;
        }
    }
    return -1;
}