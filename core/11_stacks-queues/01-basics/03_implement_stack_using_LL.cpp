/*
Implement a Last-In-First-Out (LIFO) stack using a singly linked list.
The implemented stack should support the following operations: push, pop, head, and isEmpty.

Implement the LinkedListStack class:

void push(int x): Pushes element x onto the stack.
int pop(): Removes and returns the head element of the stack.
int head(): Returns the head element of the stack without removing it.
boolean isEmpty(): Returns true if the stack is empty, false otherwise.
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

class Stack
{
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    };

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    int pop()
    {
        if (head == nullptr)
            return -1;

        int newTop = head->data; // top element
        Node *delNode = head;
        head = head->next;
        delete delNode;

        return newTop;
    }

    int top()
    {
        if (head == NULL)
            return -1;
        return head->data;
    }

    bool isEmpty()
    {
        return head == NULL;
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
    Stack st;

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
            st.push(element);
            break;
        }

        case 2:
            cout << st.pop() << endl;
            break;

        case 3:
            cout << st.top() << endl;
            break;

        case 4:
            cout << boolalpha << st.isEmpty() << endl;
            break;

        case 5:
            cout << st.size() << endl;
            break;

        case 0:
            cout << "Exiting program...\n";
            return 0; // clean exit

        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}