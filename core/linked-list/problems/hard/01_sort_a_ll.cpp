/*
Given a linked list, sort its nodes based on the data value in them. Return the head of the sorted linked list.

Example
Input: 3->4->2->1->5
Output: 1->2->3->4->5
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

// TC: O(2n + nlogn); SC: O(n)
Node *brute_sort_LL(Node *head)
{
    vector<int> dataArray;
    Node *temp = head;

    while (temp != NULL)
    {
        dataArray.push_back(temp->data);
        temp = temp->next;
    }

    sort(dataArray.begin(), dataArray.end());

    temp = head;
    for (int i = 0; i < dataArray.size(); i++)
    {
        temp->data = dataArray[i];
        temp = temp->next;
    }

    return head;
}

Node *find_middle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next; // we want the mid to point at the first middle i.e, 1,2,3,4 -> slow it points to 3(mid),
                             //  we need 2 so we keep fast 1 step ahead
    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node *merge(Node *head1, Node *head2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    if (head1)
        temp->next = head1;
    else
    {
        temp->next = head2;
    }

    return dummyNode->next;
}

// Optimized. TC: O(n)
/*
{
    if(head == NULL || head->next == NULL) return head;
    middle = findMiddle(head); // rabbit and hare algo
    left_head = head, right_head =  middle->next
    middle->next = NULL;
    left_head = ms(left_head)
    right_head = ms(right_head)
    head = merge(left_head,right_head);
    return head;
}
*/

// TC: O(nlogn); SC: O(1)
Node *optimized_sort_LL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *middle = find_middle(head);
    Node *left_head = head;
    Node *right_head = middle->next;
    middle->next = NULL;

    // recurssion
    left_head = optimized_sort_LL(left_head);
    right_head = optimized_sort_LL(right_head);

    return merge(left_head, right_head);
}

int main()
{
    vector<int> arr = {3, 4, 2, 1, 5};
    Node *head = convertToLL(arr);

    cout << "Original nodes: ";
    printLL(head);

    cout << endl
         << "Sort LL(brute): ";
    head = brute_sort_LL(head);
    printLL(head);

    cout << endl
         << "Sort LL(optimized): ";
    head = optimized_sort_LL(head);
    printLL(head);
}