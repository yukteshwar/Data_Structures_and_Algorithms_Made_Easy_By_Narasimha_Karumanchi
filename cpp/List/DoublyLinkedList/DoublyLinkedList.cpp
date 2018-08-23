#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr)
{
}

DoublyLinkedList::DoublyLinkedList(const int data) : head(nullptr)
{
    Node *node = new Node;
    head = node;
    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList(const int data[], size_t nData) : head(nullptr)
{
    Node *node = new Node;
    head = node;
    node->data = data[0];
    node->next = nullptr;
    node->prev = nullptr;
    Node *prevNode = node;
    for (size_t i = 1; i < nData; i++)
    {

        Node *newNode = new Node;
        prevNode->next = newNode;
        newNode->data = data[i];
        newNode->next = nullptr;
        newNode->prev = prevNode;
        prevNode = newNode;
    }
}

DoublyLinkedList::~DoublyLinkedList()
{
    if (head != nullptr)
        DeleteList();
}

size_t DoublyLinkedList::Length() const
{
    Node *current = head;
    size_t length = 0;

    while (current != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}

void DoublyLinkedList::Insert(const int data, const size_t position)
{
    size_t k = 1;
    Node *tempNode = nullptr;
    Node *newNode = new Node;

    if (newNode == nullptr)
    {
        cout << "Memmory Error" << endl;
        return;
    }

    newNode->data = data;

    if (position == 1)
    {
        // Insert at the beginning
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr)
            head->prev = newNode;

        head = newNode;
        return;
    }

    tempNode = head;

    while (k < (position - 1) && tempNode->next != nullptr)
    {
        tempNode = tempNode->next;
        k++;
    }

    if (k != (position - 1))
    {
        cout << "Position does not exist" << endl;
        return;
    }

    newNode->next = tempNode->next;
    newNode->prev = tempNode;

    if (tempNode->next != nullptr) // Skipped in case of last node
        tempNode->next->prev = newNode;

    tempNode->next = newNode;
    return;
}

void DoublyLinkedList::Delete(const size_t position)
{
    size_t k = 1;
    Node * tempNode1 = head;
    Node * tempNode2 = nullptr;

    if (head == nullptr)
    {
        cout << "List Empty" << endl;
        return;
    }

    //From the beginning
    if (position == 1)
    {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;

        delete tempNode1;
        return;
    }
    while (k < position && tempNode1->next != nullptr)
    {
        tempNode1 = tempNode1->next;
        k++;
    }
    if(k != position)
    {
        cout << "Position does not exist" << endl;
        return;
    }

    tempNode2 = tempNode1->prev;
    tempNode2->next = tempNode1->next;

    if(tempNode1->next != nullptr) // Deletion from intermediate node
    tempNode1->next->prev = tempNode2;

    delete tempNode1;
    return;
}

void DoublyLinkedList::DeleteList()
{
    Node *auxilaryNode = nullptr;
    Node *iterator = head;

    while (iterator != nullptr)
    {
        auxilaryNode = iterator->next;
        iterator->prev = nullptr;
        delete iterator;
        iterator = auxilaryNode;
    }
    head = nullptr;
}
