#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

struct Node
{
    int data;
    Node * prev;
    Node * next;
};//Node;

typedef Node Node;

class DoublyLinkedList
{
    public:
    DoublyLinkedList();
    DoublyLinkedList(const int data);
    DoublyLinkedList(const int data[], std::size_t nData);
    ~DoublyLinkedList();

    std::size_t Length()const;
    void Insert(const int data, const std::size_t position);
    void Delete(const std::size_t position);
    void DeleteList();

    private:
    Node * head;
};

#endif // #define DOUBLYLINKEDLIST_H