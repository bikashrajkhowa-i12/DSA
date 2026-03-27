/*
Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.

Example 1:
Input:
 a = [2, 3, 6, 7, 9], b = [1, 4, 8, 10], k = 5
Output:
 6
Explanation:
 The final sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

Example 2:
Input:
 a = [100, 112, 256, 349, 770], b = [72, 86, 113, 119, 265, 445, 892], k = 7
Output:
 256
Explanation:
 The final sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_arr(const vector<int> &arr1, const vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    cout << "Given array-1: [";
    if (n == 0)
        cout << "]";
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << arr1[i] << "]";
            else
                cout << arr1[i] << ", ";
        }
    }

    cout << endl
         << "Given array-2: [";
    if (m == 0)
        cout << "]";
    else
    {
        for (int i = 0; i < m; i++)
        {
            if (i == m - 1)
                cout << arr2[i] << "]";
            else
                cout << arr2[i] << ", ";
        }
    }
    return;
}

/* brute
    z = m + n
    TC: O(z)
    SC: O(z)
*/
int brute_kth_element(vector<int> &arr1, vector<int> &arr2, int k)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> res;

    int i = 0, j = 0;

    while (i < n)
        res.push_back(arr1[i++]);
    while (j < m)
        res.push_back(arr2[j++]);

    sort(res.begin(), res.end());

    return res[k - 1];
}

/* Optimized
    range: k
    TC: O(log k)
    SC: O(1)
*/
// Core intuition: Left partition must contain k elements total.
int optimized_kth_element(vector<int> &arr1, vector<int> &arr2, int k)
{
    int n = arr1.size();
    int m = arr2.size();

    // Make sure arr1 is the smaller array
    if (n > m)
        return optimized_kth_element(arr2, arr1, k);

    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int L1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int L2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];

        int R1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int R2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (L1 <= R2 && L2 <= R1)
        {
            return max(L1, L2);
        }
        else if (L1 > R2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }

    return -1; // This should never happen if k is valid
}

int main()
{
    vector<int> nums1 = {100, 112, 256, 349, 770};
    vector<int> nums2 = {72, 86, 113, 119, 265, 445, 892};
    int k = 7;
    print_arr(nums1, nums2);
    cout << endl
         << "k: " << k;
    cout << endl
         << "kth element(brute): " << brute_kth_element(nums1, nums2, k);
    cout << endl
         << "kth element(optimized): " << optimized_kth_element(nums1, nums2, k);
}