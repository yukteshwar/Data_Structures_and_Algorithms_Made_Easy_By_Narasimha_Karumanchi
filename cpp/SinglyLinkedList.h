#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

struct Node
{
    int data;
    Node * next;
};//Node;

typedef Node Node;

class SinglyLinkedList
{
    public:
    SinglyLinkedList();
    SinglyLinkedList(const int data);
    ~SinglyLinkedList();

    std::size_t Length()const;
    void Insert(const int data, const int position);
    void Delete(const int position);
    void DeleteList();


    private:
    Node * head;
};

#endif // #define SINGLYLINKEDLIST_H