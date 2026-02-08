/*
Implement a First-In-First-Out (FIFO) queue using a singly linked list.
The implemented queue should support the following operations: push, pop, peek, and isEmpty.

Implement the LinkedListQueue class:

void push(int x): Adds element x to the end of the queue.
int pop(): Removes and returns the front element of the queue.
int peek(): Returns the front element of the queue without removing it.
boolean isEmpty(): Returns true if the queue is empty, false otherwise.
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

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    };

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    int pop()
    {
        if (isEmpty())
            return -1;

        int newTop = head->data; // top element
        Node *delNode = head;
        head = head->next;
        delete delNode;

        if (head == nullptr) // queue is now empty
            tail = nullptr;

        return newTop;
    }

    int top()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }

    int size()
    {
        if (isEmpty())
            return 0;

        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main()
{
    Queue q;

    while (true)
    {
        cout << "*******************STACK USING LINKED-LIST******************\n";
        cout << "\n\nSelect a stack operation:\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. IsEmpty\n5. Size\n0. Exit\n";
        cout << "Your option: ";

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            int element;
            cout << "Enter element to push: ";
            cin >> element;
            q.push(element);
            break;
        }

        case 2:
            cout << q.pop() << endl;
            break;

        case 3:
            cout << q.top() << endl;
            break;

        case 4:
            cout << boolalpha << q.isEmpty() << endl;
            break;

        case 5:
            cout << q.size() << endl;
            break;

        case 0:
            cout << "Exiting program...\n";
            return 0; // clean exit

        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}