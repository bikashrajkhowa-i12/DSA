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

    // insert specific //TODO:
}