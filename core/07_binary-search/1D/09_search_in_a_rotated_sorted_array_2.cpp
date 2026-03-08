/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false
if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

#include <iostream>
#include <vector>
using namespace std;

/* Brute-force
    Idea: Linear-search
    Complexity:
        - TC: O(n)
        - SC: O(1)
*/
bool brute_search(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return false;

    for (int i = 0; i < nums.size(); i++)
    {
        if (target == nums[i])
            return true;
    }

    return false;
}

/* Optimal-approach
    Idea: find the sorted half and apply Binary-search (since its rotated-sorted)
    Complexity:
        - TC: O(log n)
        - SC: O(1)
*/

bool optimized_search(vector<int> &nums, int target)
{
    if (nums.size() == 0)
        return false;

    int n = nums.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if mid == target
        if (nums[mid] == target)
            return true;

        // shift right
        if (nums[low] > nums[mid]) // left unsorted; right sorted
        {
            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // shift left
        else
        {
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> nums = {4, 5, 6, 0, 1, 2, 3};
    int target = 5;

    cout << "Input nums: [";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            cout << nums[i] << "]";
        else
            cout << nums[i] << ", ";
    }

    cout << endl
         << "Is target present? (brute) : " << boolalpha << brute_search(nums, target);
    cout << endl
         << "Is target present? (optimized): " << boolalpha << optimized_search(nums, target);
    return 0;
}