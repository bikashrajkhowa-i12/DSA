/*
Reverse a LL (recursive)
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

//*******************RECURSIVE TRACING***************************/
// 1->2->3->4
/*

reverse(1) {
    reverse(2){
        reverse(3){
            reverse(4)
            }
        }
    }
}

reverse(1) {
    if head == nul return head;
    new head = reverse(2); // 4
    Node *front = head->next; // 2
    front->next = head; // 2->1
    head->next = NULL; // 2->1->NULL
    return new_head; //4->...
}



reverse(2) {
    if head == nul return head;
    new head = reverse(3); // 4
    Node *front = head->next; // 3
    front->next = head; // 3->2
    head->next = NULL; // 3-2->NULL
    return new_head; //4->...
}

reverse(3) {
    if head == nul return head;
    new head = reverse(4); // 4
    Node *front = head->next; // 4
    front->next = head; // 4->3
    head->next = NULL; // 4->3->NULL
    return new_head; //4->...
}
*/
//*************************************************************/
// TC: O(n); SC: O(1)
Node *optimized_recursive_reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *new_head = optimized_recursive_reverseLL(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return new_head;
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
         << "Reverse LL(recursive-optimized): ";
    head = optimized_recursive_reverseLL(head);
    printLL(head);
}