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

Node *covert_to_2d_LL(vector<int> &arr)
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

void print_2d_LL(Node *head)
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

int main()
{
    // Node *head = new Node(10);
    // head->next = new Node(11);
    // head->next->next = new Node(12);
    // head->next->next->prev = head->next;
    // head->next->prev = head;

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = covert_to_2d_LL(arr);

    print_2d_LL(head);
}