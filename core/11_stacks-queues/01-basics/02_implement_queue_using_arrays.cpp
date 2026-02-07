/*
Implement Queue using Array (Circular Queue)
*/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    static const int SIZE = 100;
    int arr[SIZE];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % SIZE == front;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Queue-overflow!";
            return;
        }

        // first insertion
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue-underflow!";
            return;
        }

        // only one element
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!";
            return -1;
        }
        return arr[front];
    }

    int size()
    {
        if (isEmpty())
            return 0;

        if (rear >= front)
            return rear - front + 1;

        return SIZE - (front - rear - 1);
    }
};

int main()
{
    Queue q;

    while (true)
    {
        cout << "\n\nSelect a queue operation:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. Size\n0. Exit\n";
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
            cout << "Pushed!";
            break;
        }

        case 2:
            q.pop();
            cout << "Popped!";
            break;

        case 3:
            cout << q.peek();
            break;

        case 4:
            cout << boolalpha << q.isEmpty();
            break;

        case 5:
            cout << q.size();
            break;

        case 0:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}
