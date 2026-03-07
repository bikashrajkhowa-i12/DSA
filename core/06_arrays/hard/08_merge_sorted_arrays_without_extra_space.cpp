/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside
the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements
denote the elements that should be merged, and the last n elements are set to 0 and should be
ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* brute-force approach
    TC: O(m+n) + O(n log n)
    SC: O(m+n)
*/
void brute_merge_arrays(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    vector<int> temp;

    for (int i = 0; i < m; i++)
    {
        temp.push_back(arr1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        temp.push_back(arr2[i]);
    }

    sort(temp.begin(), temp.end());
    for (int i = 0; i < m + n; i++) // since problem stats that nums1.length = m+n
    {
        arr1[i] = temp[i];
    }
}

/* optimal approach
    core idea:  Write from the back — compare the largest elements of both arrays and place the
                bigger one at the end of arr1, moving inward.
                This works because arr1 has empty slots at the end, so you never overwrite data
                you still need.
    complexity:
        - TC: O(m+n)
        - SC: O(1)
*/
void optimized_merge_arrays(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = (m + n) - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
        {
            arr1[k] = arr1[i];
            i--;
        }
        else
        {
            arr1[k] = arr2[j];
            j--;
        }
        k--;
    }

    while (j >= 0)
    {
        arr1[k] = arr2[j];
        j--;
        k--;
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    cout << "nums1: [";
    for (int i = 0; i < nums1.size(); i++)
    {
        if (i == nums1.size() - 1)
            cout << nums1[i] << "]";
        else
            cout << nums1[i] << ", ";
    }

    cout << endl
         << "nums2: [";
    for (int i = 0; i < nums2.size(); i++)
    {
        if (i == nums2.size() - 1)
            cout << nums2[i] << "]";
        else
            cout << nums2[i] << ", ";
    }

    // brute_merge_arrays(nums1, m, nums2, n);
    optimized_merge_arrays(nums1, m, nums2, n);
    cout << endl
         << "Merged: [";
    for (int i = 0; i < nums1.size(); i++)
    {
        if (i == nums1.size() - 1)
            cout << nums1[i] << "]";
        else
            cout << nums1[i] << ", ";
    }
}