/*
Given a linked list and an integer value val, insert a new node
with that value at the beginning (before the head) of the list
and return the updated linked list.

Examples
Input: 0->1->2, val = 5
Output: 5->0->1->2
Explanation: We need to insert the value 5 before the head of the given Linked List.
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

Node *insert_head(Node *head, int data)
{
    // if no head, make this the head
    if (head == NULL)
        return new Node(data);

    Node *newHead = new Node(data, head);
    head = newHead;
    return head;
}

Node *insert_tail(Node *head, int data)
{
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data, nullptr);

    return head;
}

Node *insert_specific(Node *head, int index, int data)
{
    if (head == NULL)
        return new Node(data);

    if (index == 0)
        return insert_head(head, data);

    int cur_idx = 0;
    Node *temp = head;

    // 10 11 12 13 14
    while (temp->next != NULL && cur_idx + 1 != index)
    {
        temp = temp->next;
        cur_idx++;
    }

    Node *rest = temp->next; // never delete a node while insertion
    Node *curr = new Node(data, rest);
    temp->next = curr;

    return head;
}

int main()
{
    Node *head = new Node(11);
    head->next = new Node(12);
    head->next->next = new Node(13);

    cout << "Original Linked-List: ";
    printLL(head);

    // insert at head of linked-list;
    cout << endl
         << "Insert at head: ";
    head = insert_head(head, 10);
    printLL(head);

    // insert at tail of linked-list;
    cout << endl
         << "Insert at tail: ";
    head = insert_tail(head, 14);
    printLL(head);

    // insert at specific position;
    cout << endl
         << "Insert at specific: ";
    head = insert_specific(head, 4, 20);
    printLL(head);
}