/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays
such that the largest sum of any subarray is minimized. Return the minimized largest
sum of the split. (A subarray is a contiguous part of the array).

Example 1:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
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

    cout << "Given array: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

int sum(vector<int> &arr)
{
    int sum = 0;
    for (int num : arr)
        sum += num;
    return sum;
}

int canSplitIntoK(vector<int> &arr, int k, int sumLimit)
{
    int parts = 1;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > sumLimit)
            return false;

        if (currentSum + arr[i] <= sumLimit)
            currentSum += arr[i];
        else
        {
            parts++;
            currentSum = arr[i];
        }

        if (parts > k)
            return false;
    }
    return true;
}

/* brute
    limit = maxSum - minSum
    TC: O(n) + O(limit * n) => O(n * limit)
    SC: O(1)
*/
int brute_min_largest_sum(vector<int> &arr, int k)
{
    if (k > arr.size())
        return -1;

    int minSum = *max_element(arr.begin(), arr.end());
    int maxSum = sum(arr);

    for (int i = minSum; i <= maxSum; i++)
    {
        if (canSplitIntoK(arr, k, i))
            return i;
    }

    return maxSum;
}

/* optimized
    limit = maxSum - minSum
    TC: O(n) + O(log limit * n) => O(n * log limit)
    SC: O(1)
*/
int optimized_min_largest_sum(vector<int> &arr, int k)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = sum(arr);
    int res = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canSplitIntoK(arr, k, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return res;
}

int main()
{
    vector<int> arr = {7, 2, 5, 10, 8};
    int k = 2;
    print_arr(arr);
    cout << endl
         << "k: " << k;
    cout << endl
         << "Brute: " << brute_min_largest_sum(arr, k);
    cout << endl
         << "Optimized: " << optimized_min_largest_sum(arr, k);
}