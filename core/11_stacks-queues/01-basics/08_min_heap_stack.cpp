/*
Design a stack that supports the following operations in constant time: push, pop, top, and retrieving the minimum element.

Implement the MinStack class:

MinStack(): Initializes the stack object.
void push(int val): Pushes the element val onto the stack.
void pop(): removes the element on the top of the stack.
int top(): gets the top element of the stack.
int getMin(): retrieves the minimum element in the stack.

Example 1:
Input:
 ["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
[ [], [-2], [0], [-3], [ ], [ ], [ ], [ ] ]
Output:
 [null, null, null, null, -3, null, 0, -2]

Example 2:
Input:
 ["MinStack", "push", "push", "getMin", "push", "pop", "getMin", "top"]
[ [ ], [5], [1], [ ], [3], [ ], [ ], [ ] ]
Output:
 [null, null, null, 1, null, null, 1, 1]
*/
#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

class MyStack
{
    stack<pair<int, int>> st;
    // pair <new, min(new, old)>
public:
    void push(int data)
    {
        if (st.empty())
        {
            st.push({data, data});
        }
        else
        {

            st.push({data, min(data, st.top().second)});
        }
    }

    int pop()
    {
        if (st.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int topElement = st.top().first;
        st.pop();
        return topElement;
    }

    int top()
    {
        if (st.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return st.top().first;
    }

    int getMin()
    {
        if (st.empty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return st.top().second;
    }
};

int main()
{
    MyStack st;
    while (true)
    {
        cout << "\n\nSelect a stack operation:\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Get-Min\n0. Exit\n";
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
            cout << "Popped: " << st.pop() << endl;
            break;

        case 3:
            cout << st.top() << endl;
            break;

        case 4:
            cout << st.getMin() << endl;
            break;

        case 0:
            cout << "Exiting program...\n";
            return 0; // clean exit

        default:
            cout << "Invalid option! Try again.\n";
        }
    }
}