/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/

#include <iostream>
#include <vector>
#include <unordered_map>

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
    TC: O(n*n*n)
    SC: O(1)
*/
int brute_total_subarrays(vector<int> &nums, int target)
{
    int n = nums.size();
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += nums[k];
            if (sum == target)
                total++;
        }
    }
    return total;
}

/* better-approach
    TC: O(n*n)
    SC: O(1)
*/
int better_total_subarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                total++;
        }
    }
    return total;
}
/* optimal
    - Idea intuition: Keep a running sum; whenever you’ve seen an earlier sum
        that is current sum − k, the numbers between them add up to k.
    - TC: O(n)
    - SC: O(n)
*/
int optimal_total_subarrays(vector<int> &nums, int k)
{
    unordered_map<int, int> ump;
    ump[0] = 1; // base: one way to have prefix sum 0 (empty prefix)

    int total = 0;
    int prefix = 0; // running prefix sum

    for (int x : nums)
    {
        prefix += x; // update prefix sum up to current index

        // if (prefix - k) seen before,
        // those many subarrays end here with sum = k
        if (ump.count(prefix - k))
            total += ump[prefix - k];

        // record this prefix for future subarrays
        ump[prefix]++;
    }

    return total; // total subarrays with sum = k
}

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 3;
    cout << "Given array nums: ";
    print_arr(nums);
    cout << endl
         << "k: " << k;
    cout << endl
         << "Total subarrays (brute): " << brute_total_subarrays(nums, k);
    cout << endl
         << "Total subarrays (better): " << better_total_subarrays(nums, k);
    cout << endl
         << "Total subarrays (optimal): " << optimal_total_subarrays(nums, k);
}