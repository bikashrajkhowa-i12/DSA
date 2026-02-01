/*
Given the head of a linked list of integers, delete the middle node
of the linked list and return the modified head. However, if the linked list
has an even number of nodes, delete the second middle node.

Examples
Input: 1->2->3->4->5 delete-3
Output: 1->2->4->5
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

// TC: O(n); SC: O(n)
Node *brute_delete_mid(Node *head)
{
    if (!head || !head->next)
        return head;

    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int mid = arr[(arr.size() / 2)]; // since array.size starts with 0
    temp = head;
    Node *pre_mid = NULL;
    Node *mid_node = NULL;

    while (temp != NULL)
    {
        if (temp->next != NULL && temp->next->data == mid)
        {
            pre_mid = temp;
        }
        if (temp->data == mid)
        {
            mid_node = temp;
            break;
        }
        temp = temp->next;
    }

    pre_mid->next = mid_node->next;
    delete mid_node;

    return head;
}

// TC: O(n/2); SC: O(1)
Node *delete_mid(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;
    Node *pre_mid = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        pre_mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    pre_mid->next = slow->next;
    delete slow;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);

    cout << "Original Linked-list: ";
    printLL(head);

    // cout << endl
    //      << "Deleted mid(brute): ";
    // head = brute_delete_mid(head);
    // printLL(head);

    cout << endl
         << "Deleted mid(optimized): ";
    head = delete_mid(head);
    printLL(head);
}