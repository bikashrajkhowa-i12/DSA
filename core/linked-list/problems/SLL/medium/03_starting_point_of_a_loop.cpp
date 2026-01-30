/*
Given the head of a linked list that may contain a cycle,
return the starting point of that cycle. If there is no cycle
in the linked list return null.

Examples
Input: LL: 1  2  3  4  5 -> 3
Output: 3
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
// brute force. TC: O(n); SC: O(n)
Node *brute_starting_of_loop(Node *head)
{
    unordered_set<Node *> visited;

    while (head != NULL)
    {
        if (visited.find(head) != visited.end())
        {
            return head;
        }

        visited.insert(head);
        head = head->next;
    }

    return NULL;
}

// Optimized TC: O(n); SC: O(1)
Node *starting_of_loop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            slow = head;
            while (slow != fast) // important
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // 5 pointing to 3 again

    cout << "Starting of a loop(brute-force): " << brute_starting_of_loop(head)->data << endl;
    cout << "Statring of loop(optimized): " << starting_of_loop(head)->data;
}