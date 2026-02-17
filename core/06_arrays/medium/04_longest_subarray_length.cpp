/*
Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k.
If no such sub-array exists, return 0.

Example:
Input: nums = [10, 5, 2, 7, 1, 9], k = 15
Output: 4
Explanation:
 The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4.
 This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15.
 Therefore, the length of this sub-array is 4.
*/

#include <iostream>
#include <vector>

using namespace std;

// brute; TC: O(n*n); SC: O(1)
int longest_subarray_sum_length(vector<int> &arr, int k)
{
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum > k)
                break;
            else if (sum == k)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

/* APPROACH
for each right:
    include arr[right]

    while sum too big:
        remove from left

    if sum perfect:
        record length
*/
// TC: O(n); SC: O(1)
int optimal_longest_subarray_sum_length(vector<int> &arr, int k)
{
    int left = 0;
    int maxLen = 0;
    long long sum = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        sum += arr[right];
        while (sum > k && left <= right)
        {
            sum = sum - arr[left];
            left++;
        }

        if (sum == k)
            maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main()
{
    int k = 15;
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << ", ";
    }
    cout << endl
         << "Sum(k): " << k;
    cout << endl
         << "Result(brute): " << longest_subarray_sum_length(arr, k);
    cout << endl
         << "Result(optimized): " << optimal_longest_subarray_sum_length(arr, k);
}