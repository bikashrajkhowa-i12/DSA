/*
 Given an integer array A, return the next greater element for every element in A.
 The next greater element for an element x is the first element greater than x that
 we come across while traversing the array in a clockwise manner. If it doesn't exist, return -1 for this element.

Examples
Input: arr = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
*/

/*APPROACH
## Next Greater Element (Right Side) — Approach Based on Given Code

- Traverse array **from right → left**.

- Use a **stack to store candidate greater elements** (values).

- For each element `arr[i]`:
  - Pop all elements from stack that are **smaller than current element**
    (they can never be the next greater for this or any earlier element).
  - If stack is empty → no greater element → store `-1`
  - Else → stack top is the **next greater element** → store it

- Push current element into stack
  (it may become next greater for elements on the left)

- Continue until all elements processed.

- Return result array.
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// TC: O(n); SC: O(n)
vector<int> NGE(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();

    vector<int> res(n); // important

    for (int i = n - 1; i >= 0; i--)
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
    vector<int> arr = {1, 3, 5, 2, 4};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    vector<int> result = NGE(arr);
    cout << endl
         << "Next greater elements: ";
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}