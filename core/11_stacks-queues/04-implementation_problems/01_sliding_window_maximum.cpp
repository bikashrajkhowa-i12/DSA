/*
Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array
to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window..

Examples
Input: arr = [4,0,-1,3,5,3,6,8], k = 3
Output: [4,3,5,5,6,8]
Explanation:

Window position                   Max
------------------------         -----
[4  0  -1] 3  5  3  6  8           4
 4 [0  -1  3] 5  3  6  8           3
 4  0 [-1  3  5] 3  6  8           5
 4  0  -1 [3  5  3] 6  8           5
 4  0  -1  3 [5  3  6] 8           6
 4  0  -1  3  5 [3  6  8]          8

For each window of size k=3, we find the maximum element in the window and add it to our output array.

Input: arr= [20,25], k = 2
Output: [25]
Explanation: There’s just one window is size 2 that is possible and the maximum of the two elements is our answer.
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// TC: O((n-k)*k); SC: O(n-k);
// At worst: O(n*n); SC: O(n-k)
vector<int> sliding_window_max(vector<int> &arr, int k)
{
    vector<int> res;
    int start = 0;
    int end = k - 1;

    while (end < arr.size())
    {
        int maxValue = INT_MIN;
        for (int i = start; i <= end; i++)
        {
            maxValue = max(maxValue, arr[i]);
        }
        res.push_back(maxValue);
        start++;
        end++;
    }
    return res;
}

/* Optimal approach********************
    CORE IDEA: When a bigger number comes, smaller numbers before it are useless forever.
    Steps:
        1. Iterate through array.
        2. Remove indices from front if they are out of current window (i - k).
        3. Remove indices from back while their values are smaller than current element
            (they can never become max again).
        4. Push current index to back.
        5. If window size reached (i >= k-1), record arr[dq.front()] as max.
*/
vector<int> optimized_sliding_max(vector<int> &arr, int k)
{
    deque<int> dq; // stores indices
    vector<int> res;

    for (int i = 0; i < arr.size(); i++)
    {
        // remove out of window range from left
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // remove smaller elements
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        // add current index (basically the max)
        dq.push_back(i);

        // form at least k-1 elements to form the window size and start pushing max
        if (i >= k - 1)
            res.push_back(arr[dq.front()]);
    }
    return res;
}

int main()
{
    int k = 3;
    vector<int> arr = {4, 0, -1, 3, 5, 3, 6, 8};
    vector<int> res;

    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    cout << endl
         << "Given k: " << k;
    // res = sliding_window_max(arr, k);
    res = optimized_sliding_max(arr, k);
    cout << endl
         << "Sliding window max: [";
    for (int i = 0; i < res.size(); i++)
    {
        if (i == res.size() - 1)
            cout << res[i] << "]";
        else
            cout << res[i] << ", ";
    }
    return 0;
}