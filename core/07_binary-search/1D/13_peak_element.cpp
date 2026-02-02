/*
Given an array of length N, peak element is defined as the element
greater than both of its neighbors. Formally, if arr[i] is the peak
element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i]. Find the index(0-based)
of a peak element in the array. If there are multiple peak numbers,
return the index of any peak number.

Examples
Input: arr[] = {1,2,3,4,5,6,7,8,5,1}
Output: 7
Explanation: There is only 1 peak element, 8,  that is at index 7.
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n); SC: O(1)
int brute_peak(vector<int> &arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        if ((i == 0 || arr[i] > arr[i - 1]) && (i == N - 1 || arr[i] > arr[i + 1]))
            return i;
    }
    return -1;
}

// TC: O(logn); SC: (1)
int optimized_peak(vector<int> &arr, int N)
{
    if ((N == 1) || arr[0] > arr[1])
        return 0;
    else if (arr[N - 1] > arr[N - 2])
        return N - 1;
    else
    {
        int low = 1;
        int high = N - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] > arr[mid - 1])
            {
                low = mid + 1;
            }
            else if (arr[mid] > arr[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    cout << "Peak element is(brute-force): " << brute_peak(arr, arr.size()) << endl;
    cout << "Peak element is(optimized-force): " << optimized_peak(arr, arr.size());
}
