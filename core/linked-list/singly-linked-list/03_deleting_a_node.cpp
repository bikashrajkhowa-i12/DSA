/*
Given a Linked List, delete the tail of the list and print the updated list.

Examples
Input: 0->1->2
Output: 0->1
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

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *delete_head(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *delete_tail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return head;
}

Node *delete_specific(Node *head, int data)
{
    if (head == NULL)
        return NULL;

    if (head->data == data)
    {
        return delete_head(head);
    }

    Node *temp = head;

    // 11 12 13 14
    while (temp->next != NULL && temp->next->data != data)
    {
        temp = temp->next;
    }

    // incase data not found
    if (temp->next == NULL)
        return head;

    Node *del = temp->next;
    temp->next = del->next;
    delete del;

    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(11);
    head->next->next = new Node(12);
    head->next->next->next = new Node(13);
    head->next->next->next->next = new Node(14);
    head->next->next->next->next->next = new Node(15);

    // original LL
    cout << "Original LL: ";
    printLL(head);

    // delete head
    cout << endl
         << "Delete head: ";
    head = delete_head(head);
    printLL(head);

    // delete tail
    cout << endl
         << "Delete tail: ";
    head = delete_tail(head);
    printLL(head);

    // delete  specific
    cout << endl
         << "Delete specific: ";
    head = delete_specific(head, 12);
    printLL(head);
}