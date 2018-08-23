#include <iostream>
#include <memory>
#include "SinglyLinkedList.h"

using namespace std;


SinglyLinkedList::SinglyLinkedList() : head(nullptr)
{
}

 SinglyLinkedList::SinglyLinkedList(const int data): head(nullptr)
 {
     Node * node = new Node;
     head = node;
     node->data = data;
     node->next = nullptr;
 }

SinglyLinkedList::~SinglyLinkedList()
{
    if (head != nullptr)
        DeleteList();
}

size_t SinglyLinkedList::Length() const
{
    Node * current = head;
    size_t length = 0;

    while (current != nullptr)
    {
        length++;
        current = current->next;
    }
    return length;
}

void SinglyLinkedList::Insert(const int data, const int position)
{

}

void SinglyLinkedList::DeleteList()
{

}