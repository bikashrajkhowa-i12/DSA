/*
Given the head of a linked list and an integer value,
find out whether the integer is present in the linked list or not.
Return true if it is present, or else return false.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

bool search_LL(Node *head, int target)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(11);
    head->next->next = new Node(12);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(14);
    head->next->next->next->next->next = new Node(15);

    cout << boolalpha << search_LL(head, 12); // op: true
}