#include <iostream>
#include <vector>
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    vector<int> data{1,2,3,4,5,6};
    DoublyLinkedList dll(data.data(), data.size());
    cout << dll.Length() << endl;
    dll.Insert(3, 5);
    cout << dll.Length() << endl;
    dll.Delete(4);
    cout << dll.Length() << endl;
    dll.DeleteList();
    cout << dll.Length() << endl;
    return 0;
}