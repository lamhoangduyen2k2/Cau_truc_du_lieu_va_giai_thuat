// LinkList_Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node* pNext;

};
struct LIST
{
    Node* pHeap;
    Node* pTail;
};
Node* CreateNode(int x)
{
    Node* p = new Node;
    p->info = x;
    p->pNext = NULL;
    return p;
}
int main()
{
    Node* p1 = CreateNode(9);
    Node* p2 = CreateNode(7);
    Node* p3 = CreateNode(1);
    Node* p4 = CreateNode(2);
    LIST myList;
    myList.pHeap = p1;
    p1->pNext = p2;
    p2->pNext = p3;
    p3->pNext = p4;
    p4->pNext = NULL;
    myList.pTail = p4;
    cout << myList.pHeap->info << endl << ", " << myList.pHeap->pNext->info << endl << ", " << myList.pHeap->pNext->pNext->info << endl << ", " << myList.pHeap->pNext->pNext->pNext->info << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
