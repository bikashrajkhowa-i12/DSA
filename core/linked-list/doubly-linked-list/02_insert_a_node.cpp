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

Node *insert_head(Node *head, int data)
{
    if (head == NULL)
        return new Node(data);

    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return head;
}

Node *insert_tail(Node *head, int data)
{
    if (head == NULL)
        return new Node(data);

    Node *cur = head;
    // 11 12 13 14 []
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    Node *newNode = new Node(data);
    cur->next = newNode;
    newNode->prev = cur;

    return head;
}

Node *insert_specific(Node *head, int index, int data)
{
    if (head == NULL)
        return new Node(data);

    if (index == 0)
    {
        return insert_head(head, data);
    }

    int idx = 0;
    Node *curr = head;
    // 11 12 13 14 15
    while (curr->next != NULL && index != idx + 1)
    {
        curr = curr->next;
        idx++;
    }

    Node *newNode = new Node(data);

    if (curr->next == NULL)
    {
        if (idx + 1 != index) // if index out of bounds
        {
            cout << endl
                 << "Index out of bound!" << endl;
            return head;
        }
        else // if its the last node, insert at tail
        {
            curr->next = newNode;
            newNode->prev = curr;
            return head;
        }
    }

    newNode->next = curr->next;
    curr->next->prev = newNode;
    curr->next = newNode;
    newNode->prev = curr;

    return head;
}

int main()
{
    // Node *head = nullptr;
    Node *head = new Node(11);

    head->next = new Node(12);
    head->next->prev = head;

    head->next->next = new Node(13);
    head->next->next->prev = head->next;

    cout << "Original linked-list: " << endl;
    print_doubly_ll(head);

    // insert head
    cout << endl
         << "\nInsert head: " << endl;
    head = insert_head(head, 10);
    print_doubly_ll(head);

    // insert tail
    cout << endl
         << "\nInsert Tail: " << endl;
    head = insert_tail(head, 14);
    print_doubly_ll(head);

    // insert specific
    cout << endl
         << "\nInsert Specific: " << endl;
    head = insert_specific(head, 0, 99);
    print_doubly_ll(head);
}