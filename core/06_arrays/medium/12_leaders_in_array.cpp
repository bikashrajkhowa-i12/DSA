/*
Given an array arr[] of size n, the task is to find all the Leaders in the array.
An element is a Leader if it is greater than or equal to all the elements to its right side.
Note: The rightmost element is always a leader.

Example 1:
Input: arr[] = [16, 17, 4, 3, 5, 2]
Output: [17 5 2]
Explanation: 17 is greater than all the elements to its right i.e., [4, 3, 5, 2],
therefore 17 is a leader. 5 is greater than all the elements to its right i.e., [2],
therefore 5 is a leader. 2 has no element to its right, therefore 2 is a leader.

Input: arr[] = [1, 2, 3, 4, 5, 2]
Output: [5 2]
Explanation: 5 is greater than all the elements to its right i.e., [2], therefore 5 is a leader.
2 has no element to its right, therefore 2 is a leader.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_arr(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        cout << "[]";
        return;
    }

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

/* brute-force
    TC: O(n*n)
    SC: O(n)
*/
vector<int> brute_array_leaders(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return {};

    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                isLeader = false;
                break;
            }
        }

        if (isLeader)
            res.push_back(arr[i]);
    }

    return res;
}

/* Optimized
    TC: O(n) + O(n) => O(2n) => O(n),
    SC: O(n) // for the result
*/
vector<int> optimized_array_leaders(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return {};

    vector<int> res;
    int max_from_right = arr[n - 1];
    res.push_back(max_from_right); // since last element is always a leader

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max_from_right)
        {
            // cout << arr[i] << ", "; // print in place for SC: O(1)
            res.push_back(arr[i]);
            max_from_right = arr[i];
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    cout << "Given array: ";
    print_arr(arr);
    cout << endl
         << "Leaders in array(brute): ";
    print_arr(brute_array_leaders(arr));
    cout << endl
         << "Leaders in array(optimized): ";
    print_arr(optimized_array_leaders(arr));
    return 0;
}