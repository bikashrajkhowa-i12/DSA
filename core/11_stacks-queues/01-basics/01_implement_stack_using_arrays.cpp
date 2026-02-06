/*
Implement stack using arrays
hint: push, pop, top, size
*/

#include <bits/stdc++.h>
using namespace std;

class ImplementStack
{
    int arr[100]; // size
    int top;

public:
    ImplementStack() // constructor
    {
        top = -1;
    }

    bool isFull()
    {
        return top == 99;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow!";
            return;
        }
        else
        {
            top = top + 1;
            arr[top] = x;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!";
            return;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    int size()
    {
        return top + 1;
    }
};

int main()
{
    ImplementStack st;

    while (true)
    {
        cout << "\n\nSelect an operation:\n";
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
            st.pop();
            break;

        case 3:
            cout << st.peek();
            break;

        case 4:
            cout << boolalpha << st.isEmpty();
            break;

        case 5:
            cout << st.size();
            break;

        case 0:
            cout << "Exiting program...\n";
            return 0; // clean exit

        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}
