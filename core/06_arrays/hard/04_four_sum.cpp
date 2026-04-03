/*
Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
    -> 0 <= a, b, c, d < n;
    -> a, b, c, and d are distinct.
    -> nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
*/

#include <iostream>
#include <vector>
#include <set>
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
    TC: O(n*n*n*n)
    SC: O(u) // unique quadruplets
*/

vector<vector<int>> brute_4sum(vector<int> &arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];

                    if (sum == target)
                    {
                        vector<int> quad = {arr[i], arr[j], arr[k], arr[l]};
                        sort(quad.begin(), quad.end());
                        st.insert(quad);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    cout << "Given nums: ", print_arr(nums);
    cout << endl
         << "Target: " << target;
    cout << endl
         << "Brute 4-sum pairs: ";

    vector<vector<int>> brute_4sum_pairs = brute_4sum(nums, target);
    cout << "[";
    for (vector nums : brute_4sum_pairs)
    {
        print_arr(nums);
    }
    cout << "]";
    return 0;
}