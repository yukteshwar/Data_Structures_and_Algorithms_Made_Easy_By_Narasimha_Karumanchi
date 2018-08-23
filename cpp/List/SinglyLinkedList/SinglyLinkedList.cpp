#include <iostream>
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

  SinglyLinkedList::SinglyLinkedList(const int data[], size_t nData): head(nullptr)
  {
     Node * node = new Node;
     head = node;
     node->data = data[0];
     node->next = nullptr;
     Node * prevNode = node;
      for (size_t i = 1; i < nData; i++)
      {
          
          Node * newNode = new Node;
          prevNode->next = newNode;
          newNode->data = data[i];
          newNode->next = nullptr;
          prevNode = newNode;
      }
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

void SinglyLinkedList::Insert(const int data, const size_t position)
{
    size_t k = 1;
    Node * p = nullptr;
    Node * q = nullptr;
    Node * newNode = new Node;

    if (newNode == nullptr)
    {
        cout << "Memmory Error" << endl;
        return;
    }

    newNode->data = data;
    p = head;

    if(position == 1)
    {
        // Insert at the beginning
        newNode->next = p;
        head = newNode;
    }
    else
    {
        // Traverse the list until the position where we want to insert
        while (p != nullptr && k < position)
        {
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }

}

void SinglyLinkedList::Delete(const size_t position)
{
    size_t k = 1;
    Node * p = nullptr;
    Node * q = nullptr;

    if(head == nullptr)
    {
        cout << "List Empty" << endl;
        return;
    }

    p = head;
    
    //From the beginning
    if (position == 1)
    {
        head = head->next;
        delete p;
        return;
    }
    else
    {
        //Traverse the list until arriving at the position from which we want to delete
        while(p != nullptr && k < position)
        {
            k++;
            q = p;
            p = p->next;
        }
        if(p == nullptr) // At the end
        cout << "Position does not exist" << endl;
        else
        {
            //Somewhere in the middle
            q->next = p->next;
            delete p;
        }

    }
}

void SinglyLinkedList::DeleteList()
{
    Node * auxilaryNode = nullptr;
    Node * iterator = head;

    while (iterator != nullptr)
    {
        auxilaryNode = iterator->next;
        delete iterator;
        iterator = auxilaryNode;
    }
    head = nullptr;
}