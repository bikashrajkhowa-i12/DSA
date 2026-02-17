/*
 Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k.
 If no such sub-array exists, return 0.

Example :
Input:
 nums = [-3, 2, 1], k = 6
Output:
 0
Explanation:
 There is no sub-array in the array that sums to 6. Therefore, the output is 0.

 */
#include <iostream>
#include <vector>
#include <unordered_map>

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
            // avoid since array includes 0's, negatives and positives
            // if (sum > k)
            //     break;

            if (sum == k)
                maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}

// optimized: O(n); SC: O(n)
int optimized_longest_subarray_sum_length(vector<int> &arr, int k)
{
    unordered_map<long long, int> prefixIndex;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        // case 1: subarray from 0 to i
        if (sum == k)
            maxLen = i + 1;

        // case 2: subarray in between
        if (prefixIndex.find(sum - k) != prefixIndex.end())
        {
            int len = i - prefixIndex[sum - k];
            maxLen = max(maxLen, len);
        }

        // store first occurrence only
        if (prefixIndex.find(sum) == prefixIndex.end())
            prefixIndex[sum] = i;
    }

    return maxLen;
}

int main()
{
    int k = 3;
    vector<int> arr = {-3, 2, 1};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << ", ";
    }
    cout << endl
         << "k: " << k;
    cout << endl
         << "Result(brute): " << longest_subarray_sum_length(arr, k);
    cout << endl
         << "Result(optimized): " << optimized_longest_subarray_sum_length(arr, k);
}