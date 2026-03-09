/*
You are given a sorted array consisting of only integers where every element appears exactly twice,
except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*  Brute-force approach
    - TC: O(n) + O(n) = O(2n) => O(n)
    - SC: O(n)
*/
int brute_single_element(vector<int> &arr)
{
    if (arr.size() == 0)
        return -1;

    int n = arr.size();
    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
    {
        ump[arr[i]]++;
    }

    for (auto &it : ump)
    {
        if (it.second < 2)
            return it.first;
    }
    return -1;
}

/* Better approach
    - TC: O(n)
    - SC: O(1)
*/
int better_single_element(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;

    int count = 0;
    for (int i = 0; i < n - 1; i += 2)
    {
        if (arr[i] != arr[i + 1])
            return arr[i];
    }
    return arr[n - 1];
}

/* Optimal-approach
    Key insight:
        - before the single element, pairs start at EVEN indices [0,1][2,3]...
        - after the single element, pairs shift to ODD indices.
        - So snap mid to even, if nums[mid]==nums[mid+1] → pair intact → go right, else go left.
    Complexity:
        - TC: O(logn)
        - SC: O(1)
 */
int optimized_single_element(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;

    int low = 0, high = n - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        // before single element: pairs start at even indices
        // after single element: pairs start at odd indices

        if (mid % 2 == 1)
            mid--; // ensure mid points to start of a pair

        if (arr[mid] == arr[mid + 1])
            low = mid + 2;
        else
            high = mid;
    }

    return arr[low];
}

int main()
{
    vector<int> arr = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    cout << endl
         << "Single element(brute): " << brute_single_element(arr);
    cout << endl
         << "Single element(better): " << better_single_element(arr);
    cout << endl
         << "Single element(optimized): " << optimized_single_element(arr);
}