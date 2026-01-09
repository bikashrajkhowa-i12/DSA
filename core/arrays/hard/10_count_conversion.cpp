/*
 Given an array of N integers, count the inversion of the array (using merge-sort).

Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Examples
Example 1:
Input Format: N = 5, array[] = {1,2,3,4,5}
Result: 0
Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j
you will never find a pair such that A[j] < A[i].
*/

#include <bits/stdc++.h>
using namespace std;

int counter = 0;

int brute_count_pairs(vector<int> &arr, int n)
{
    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                cnt++;
        }
    }
    return cnt;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            counter += mid - left + 1;
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int optimal_count_pairs(vector<int> &arr, int low, int high)
{
    merge_sort(arr, low, high);
    return counter;
}

// i < j and arr[i] > arr[j]
int main()
{
    vector<int> arr = {5, 3, 2, 1, 4}; // op: 7

    cout << "Total pairs(Brute-force): " << brute_count_pairs(arr, arr.size()) << endl;
    cout << "Total pairs(Optimized): " << optimal_count_pairs(arr, 0, arr.size() - 1);
}
