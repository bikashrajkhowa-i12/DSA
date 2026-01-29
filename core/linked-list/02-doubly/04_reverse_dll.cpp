/*
Given a doubly linked list of size ‘N’ consisting of positive integers,
your task is to reverse it and return the head of the modified doubly linked list.
*/

/*APPROACH
Given: 10->11->12->13
Op: 13->12->11->10

traverse tail to last element (tail->next!=NULL -> tail = tail->next)
curr->next = head->prev (11<-10->null)

while head->prev !=null
    *temp = head;
    head->next = temp->prev;
    head->prev = temp->next;
    head = head->prev;
return curr;
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

void print_doubly_ll(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node *temp = head;
    Node *tail = NULL;

    cout << "Traverse forward: ";
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next)
            cout << "->";
        tail = temp; // save last valid node
        temp = temp->next;
    }

    cout << endl
         << "Traverse backward: ";
    temp = tail; // restore from tail
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->prev)
            cout << "->";
        temp = temp->prev;
    }
}

Node *reverse_dll(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    Node *temp = NULL;

    while (curr != NULL)
    {
        // swap prev and next
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // move forward (which is prev now)
        curr = curr->prev;
    }

    // temp will be at (old head)'s prev
    return temp->prev;
}

int main()
{
    Node *head = new Node(11);

    head->next = new Node(12);
    head->next->prev = head;

    head->next->next = new Node(13);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(14);
    head->next->next->next->prev = head->next->next;

    cout << "Original doubly-LL" << endl;
    print_doubly_ll(head);

    cout << endl
         << "\nReversed doubly-LL: \n";
    head = reverse_dll(head);
    print_doubly_ll(head);
}