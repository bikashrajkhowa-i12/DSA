/*
Given a circular integer array arr, return the next greater element for every element in arr.
The next greater element for an element x is the first element greater than x that we come
across while traversing the array in a clockwise manner.
If it doesn't exist, return -1 for that element element.

Examples
Example 1:
Input:
 arr = [3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9]
Output:
 [10, -1, 6, 6, 2, 6, 7, 7, 9, 9, 10]

 */

/*APPROACH
## Circular Next Greater Element — Approach Based on Given Code

- Treat array as **circular** (after last element, continue from start).

- Traverse **2 × n − 1 → 0** to simulate wrapping around.

- Use `i % n` to map index back into original array.

- Use a **stack to store candidate greater elements** (values).

- For each index `i`:
  - Let current element = `arr[i % n]`
  - Pop all elements from stack that are **less than or equal to current**
    (they cannot be next greater for this position)
  - If stack not empty → stack top is next greater → store it
  - Else → store `-1`

- Push current element into stack
  (it may serve as next greater for earlier elements)

- First pass (extra traversal) helps fill answers using elements from the “right side” of circular array.

- Return result array.

*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> circular_NGE(vector<int> &arr)
{
    stack<int> st;
    int n = arr.size();
    vector<int> res(n);

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
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
    vector<int> arr = {3, 10, 4, 2, 1, 2, 6, 1, 7, 2, 9};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    vector<int> result = circular_NGE(arr);
    cout << endl
         << "Next greater elements: ";
    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}