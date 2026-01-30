/*
Given a Linked List, determine whether the linked list contains a cycle or not.

Eg: 1->2->3->4->5, and 5->3 (5 points to 3 again)
Output: True
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
// brute force is using hashmap(unordered set)
// TC: O(n); SC: O(n)

// Optimized TC: O(n); SC: O(1)
bool detect_cycle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
            return true;
    }

    return false;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // 5 pointing to 3 again

    cout << "Detected cycle: " << boolalpha << detect_cycle(head);
}