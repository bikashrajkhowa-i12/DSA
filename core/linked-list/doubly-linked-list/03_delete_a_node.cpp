#include <bits/stdc++.h>
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

Node *convert_to_2d_LL(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *curr = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }

    return head;
}

void print_doubly_LL(Node *head)
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

Node *delete_head(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    head = head->next;
    head->prev = nullptr;
    delete curr;

    return head;
}

Node *delete_tail(Node *head)
{

    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    Node *lastNode = curr->next;
    curr->next = nullptr;
    lastNode->prev = nullptr;
    delete lastNode;

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

    Node *curr = head;
    // 11 12 13 14
    while (curr->next != NULL && curr->next->data != data)
    {
        curr = curr->next;
    }

    // incase data not found
    if (curr->next == NULL)
        return head;

    Node *deleteNode = curr->next;
    curr->next = deleteNode->next;
    if (deleteNode->next != NULL)
        curr->next->prev = curr;

    deleteNode->prev = nullptr;
    deleteNode->next = nullptr;
    delete deleteNode;

    return head;
}

int main()
{
    vector<int> arr = {10, 11, 12, 13, 14, 15};
    Node *head = convert_to_2d_LL(arr);
    ;

    cout << "Original doubly-LL:" << endl;
    print_doubly_LL(head);

    // delete head
    cout << endl
         << "\nDelete head: \n";
    head = delete_head(head);
    print_doubly_LL(head);

    // delete tail
    cout << endl
         << "\nDelete tail: \n";
    head = delete_tail(head);
    print_doubly_LL(head);

    // delete tail
    cout << endl
         << "\nDelete specific: \n";
    head = delete_specific(head, 13);
    print_doubly_LL(head);
}