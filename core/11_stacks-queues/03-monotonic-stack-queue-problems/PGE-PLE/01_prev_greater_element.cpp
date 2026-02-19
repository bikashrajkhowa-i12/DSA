/*
 Given an integer array A, return the previous greater element for every element in A.

Examples
Input: arr = [1, 3, 2, 4]
Output: [-1, -1, 3, -1]
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// TC: O(n); SC: O(n)
vector<int> PGE(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();

    vector<int> res(n); // important

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() < arr[i])
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

    vector<int> result = PGE(arr);
    cout << endl
         << "Next greater elements: ";
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}