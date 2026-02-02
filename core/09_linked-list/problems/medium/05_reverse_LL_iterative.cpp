/*
Reverse a LL (interative)
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

Node *convertToLL(vector<int> &arr)
{
    if (arr.size() == 0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); // pushing new elements into LL
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty!";
        return;
    }

    Node *temp = head;
    while (temp)
    {
        cout << temp->data;
        if (temp->next)
            cout << "->";
        temp = temp->next;
    }
}

// TC: O(2n); O(n)
Node *brute_reverse_LL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    stack<int> st;
    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }

    return head;
}

// TC: O(n); SC: O(1)
Node *optimized_reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    cout << "Original linked-list: ";
    printLL(head);

    // cout << endl
    //      << "Reverse LL(brute): ";
    // head = brute_reverse_LL(head);
    // printLL(head);

    cout << endl
         << "Reverse LL(optimized): ";
    head = optimized_reverseLL(head);
    printLL(head);
}