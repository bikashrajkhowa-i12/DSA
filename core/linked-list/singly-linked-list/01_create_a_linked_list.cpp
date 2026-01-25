#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;   // data
    Node *next; // pointer to the next Node

    // constructor with data and next
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // contructor with only data
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

int main()
{
    vector<int> arr = {3, 1, 6, 8};
    Node *head = convertToLL(arr);
    cout << "Head is: " << head->data << endl;

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}