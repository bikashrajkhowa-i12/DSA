/*
Given the head of a linked list of integers, determine the middle node of the linked list.
However, if the linked list has an even number of nodes, return the second middle node.

Eg:
LL = 1,2,3,4,5
Output: 3

LL = 11,12,13,14
Output: 13

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
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// brute; TC: O(n); SC: O(1)
Node *brute_find_middle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = (count / 2) + 1;

    temp = head;
    while (temp->next != NULL)
    {
        mid--; // decrement back
        if (mid == 0)
        {
            break;
        }
        else
        {
            temp = temp->next;
        }
    }

    return temp;
}

// fast & slow pointers (tortoise & hare algorithm)
// TC: O(n/2); SC: O(1)
Node *optimized_find_middle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = convertToLL(arr);
    cout << "Middle element (brute): " << brute_find_middle(head)->data << endl;
    cout << "Middle element (optimized): " << optimized_find_middle(head)->data << endl;
}