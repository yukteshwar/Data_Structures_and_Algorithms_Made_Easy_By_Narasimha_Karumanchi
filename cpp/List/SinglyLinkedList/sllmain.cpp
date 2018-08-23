#include <iostream>
#include <vector>
#include "SinglyLinkedList.h"

using namespace std;

int main()
{
    vector<int> data{1,2,3,4,5,6};
    SinglyLinkedList sll(data.data(), data.size());
    cout << sll.Length() << endl;
    sll.Insert(3, 5);
    cout << sll.Length() << endl;
    sll.Delete(4);
    cout << sll.Length() << endl;
    sll.DeleteList();
    cout << sll.Length() << endl;
    return 0;
}