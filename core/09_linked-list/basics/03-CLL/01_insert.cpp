#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convert_to_CLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    // Make it circular for ALL cases (including single node)
    temp->next = head;

    return head;
}

void print_CLL(Node *head)
{
    if (!head)
    {
        cout << "List is empty";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data;
        temp = temp->next;
        cout << "->";
    } while (temp != head);
}

Node *insert_head(Node *head, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = newNode;
        return newNode;
    }

    Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    Node *newNode = new Node(data);
    newNode->next = head;
    tail->next = newNode;
    head = newNode;

    return head;
}

Node *insert_tail(Node *head, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = newNode;
        return newNode;
    }

    Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    Node *newNode = new Node(data);
    tail->next = newNode;
    newNode->next = head;

    return head;
}

Node *insert_specific(Node *head, int index, int data)
{
    if (head == NULL)
    {
        if (index == 0)
        {
            Node *head = new Node(data);
            head->next = head;
            return head;
        }
        else
        {
            return NULL;
        }
    }

    if (index == 0)
    {
        return insert_head(head, data);
    }

    // 10 11 12 13 14
    int idx = 0;
    Node *cur = head;

    while (cur->next != head && idx + 1 != index)
    {
        idx++;
        cur = cur->next;
    }

    if (cur->next == head && idx + 1 != index)
    {
        cout << "Index out of bound!\n";
        return head;
    }

    Node *newNode = new Node(data);
    newNode->next = cur->next;
    cur->next = newNode;

    return head;
}

int main()
{
    vector<int> arr = {3, 4};
    Node *head = convert_to_CLL(arr);
    cout << "Original circular linked-list: ";
    print_CLL(head);

    // insert head
    cout << endl
         << "\nInsert head: ";
    head = insert_head(head, 1);
    print_CLL(head);

    // insert tail
    cout << endl
         << "\nInsert tail: ";
    head = insert_tail(head, 6);
    print_CLL(head);

    // insert specific
    cout << endl
         << "\nInsert specific: ";
    head = insert_specific(head, 3, 7);
    print_CLL(head);
}