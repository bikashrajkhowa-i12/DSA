/*
Given the head of a singly linked list representing a positive integer number.
Each node of the linked list represents a digit of the number, with the 1st node
containing the leftmost digit of the number and so on. Check whether the linked list
values form a palindrome or not. Return true if it forms a palindrome, otherwise, return false. .

A palindrome is a sequence that reads the same forward and backwards.

Example:
Input: head -> 3 -> 7 -> 5 -> 7 -> 3
Output: true
Explanation: 37573 is a palindrome.
*/

/*Brute Approach
1->2->3->4->NULL
push into array(vector)
left(arr[0]) and right(arr[n-1])
while(left < right)
return false if it doesn't match
left++ and right--;
return true;
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

// TC: O(2n); SC: O(n)
bool brute_check_palindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

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
        if (temp->data != st.top())
            return false;

        temp = temp->next;
        st.pop();
    }

    return true;
}

Node *reverse_LL(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *new_head = reverse_LL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return new_head;
}

// TC: O(n); SC: O(1)
bool optimized_check_palindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    // safe traversal
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverse_LL(slow->next);
    Node *first = head;
    Node *second = newHead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverse_LL(newHead);
            return false;
        }

        first = first->next;
        second = second->next;
    }

    // reverse the right half back to original
    reverse_LL(newHead);
    return true;
}

int main()
{
    vector<int> arr = {3, 7, 3, 5, 3, 7, 3};
    Node *head = convertToLL(arr);
    cout << "Original linked-list: ";
    printLL(head);

    cout << endl
         << "Is palindrome(brute)? : " << boolalpha << brute_check_palindrome(head);

    cout << endl
         << "Is palindrome(optimized)? : " << boolalpha << optimized_check_palindrome(head);
}