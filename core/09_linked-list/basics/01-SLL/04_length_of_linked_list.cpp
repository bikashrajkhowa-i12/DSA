/*
Given a Linked list, find its length(traverse)
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

int print_length(Node *head)
{
    if (head == NULL)
        return 0;

    int length = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(11);
    head->next->next = new Node(12);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(14);
    head->next->next->next->next->next = new Node(15);

    cout << "Length of linked-list: " << print_length(head);
}