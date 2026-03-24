/*
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

#include <iostream>
#include <vector>

using namespace std;

void print_arr(const vector<int> &arr1, const vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr1.size();

    if (n == 0 || m == 0)
    {
        cout << "[]";
        return;
    }

    cout << "Given array-1: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr1[i] << "]";
        else
            cout << arr1[i] << ", ";
    }

    cout << endl
         << "Given array-2: [";
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
            cout << arr2[i] << "]";
        else
            cout << arr2[i] << ", ";
    }

    return;
}

/* brute
    TC: O(n+m)
    SC: O(n+m)
*/

double brute_median(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int d = m + n;
    vector<int> merged_arr;

    int first = 0;  // for arr1
    int second = 0; // for arr2

    while (first < n && second < m)
    {
        if (arr1[first] < arr2[second])
        {
            merged_arr.push_back(arr1[first]);
            first++;
        }
        else
        {
            merged_arr.push_back(arr2[second]);
            second++;
        }
    }

    while (first < n)
    {
        merged_arr.push_back(arr1[first]);
        first++;
    }

    while (second < m)
    {
        merged_arr.push_back(arr2[second]);
        second++;
    }

    if (d % 2 == 1)
        return merged_arr[d / 2];
    else
        return (merged_arr[d / 2 - 1] + merged_arr[d / 2]) / 2.0;
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    print_arr(nums1, nums2);
    cout << endl
         << "Median (brute): " << brute_median(nums1, nums2);
}