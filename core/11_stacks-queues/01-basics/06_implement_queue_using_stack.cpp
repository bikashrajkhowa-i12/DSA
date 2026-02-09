/*
Implement Queue data structure using Stack
(Tricky version – lazy transfer, amortized O(1))
*/

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> st1; // input stack
    stack<int> st2; // output stack

public:
    bool isEmpty()
    {
        return st1.empty() && st2.empty();
    }

    // TC: O(1)
    void push(int x)
    {
        st1.push(x);
    }

    // TC: Amortized O(1)
    int pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        // Transfer only if needed
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        int front = st2.top();
        st2.pop();
        return front;
    }

    // TC: Amortized O(1)
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        // Transfer only if needed
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }

    int size()
    {
        return st1.size() + st2.size();
    }
};

int main()
{
    Queue q;

    while (true)
    {
        cout << "\n******************* QUEUE USING STACK *******************\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Front\n";
        cout << "4. IsEmpty\n";
        cout << "5. Size\n";
        cout << "0. Exit\n";
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
            cout << "Popped: " << q.pop() << endl;
            break;

        case 3:
            cout << "Front: " << q.front() << endl;
            break;

        case 4:
            cout << boolalpha << q.isEmpty() << endl;
            break;

        case 5:
            cout << "Size: " << q.size() << endl;
            break;

        case 0:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}
