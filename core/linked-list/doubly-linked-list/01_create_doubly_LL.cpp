#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data1, Node *prev1, Node *next1)
    {
        data = data1;
        prev = prev1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

void print_2d_LL(Node *head)
{
    Node *temp = head;

    cout << "Traverse forward: ";
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data; // the last node

    cout << endl
         << "Traverse backward: ";
    while (temp->prev != NULL)
    {
        cout << temp->data << "<-";
        temp = temp->prev;
    }
    cout << temp->data; // the first node
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(11);
    head->next->next = new Node(12);

    head->next->next->prev = head->next;
    head->next->prev = head;

    print_2d_LL(head);
}