/*
 Given an integer array A, return the next smaller element for every element in A.

Examples
Input: arr = [1, 3, 2, 4]
Output: [-1, 2, -1, -1]
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// TC: O(n); SC: O(n)
vector<int> NLE(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();

    vector<int> res(n); // important

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() > arr[i])
        {
            st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
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

    vector<int> result = NLE(arr);
    cout << endl
         << "Next greater elements: ";
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}