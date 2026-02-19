/*
Given a circular integer array arr, return the previous lesser element for every element in arr.

Example:
Input:
 arr = [1, 3, 2, 4]
Output:
 [4, 4, 3, -1]

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// TC: O(n); SC: O(n)
vector<int> circular_PGE(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> res(n);

    for (int i = 0; i < 2 * n; i++) // double the array to create a circular mechanism
    {
        while (!st.empty() && st.top() <= arr[i % n]) // modulo to find the actual-index (between 0 to n)
        {
            st.pop();
        }
        res[i % n] = !st.empty() ? st.top() : -1;
        st.push(arr[i % n]);
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    vector<int> result = circular_PGE(arr);
    cout << endl
         << "Next greater elements: ";
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}