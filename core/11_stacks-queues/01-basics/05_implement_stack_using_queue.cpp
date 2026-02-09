/*
Implement stack data-structure using queue.
*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    queue<int> q;

public:
    bool isEmpty()
    {
        return q.size() < 1;
    }

    bool isFull()
    {
        return q.size() > INT_MAX;
    }

    void push(int x)
    {
        q.push(x);

        int size = q.size();
        while (size > 1)
        {
            q.push(q.front()); // push the front to back to behave like stack(i.e, top)
            q.pop();           // pop duplicates from the front(top)
            size--;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        q.pop();
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    int size()
    {
        return q.size();
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
            st.pop();
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