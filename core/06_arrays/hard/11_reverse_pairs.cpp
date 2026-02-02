/*
Given an array of numbers, you need to return the count of reverse pairs.
Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

Examples
Example 1:
Input:
 N = 5, array[] = {1,3,2,3,1}
Output
: 2
Explanation:
 The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.
*/

#include <bits/stdc++.h>
using namespace std;

// brute force
int reverse_pairs_count(vector<int> &arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && arr[i] > 2 * arr[j])
            {
                count++;
            }
        }
    }
    return count;
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

int count_pairs(vector<int> &arr, int low, int mid, int high)
{
    int counter = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
        {
            right++;
        }
        counter += (right - (mid + 1));
    }
    return counter;
}

int merge_sort(vector<int> &arr, int low, int high)
{
    int counter = 0;
    if (low >= high)
        return counter;

    int mid = low + (high - low) / 2;
    counter += merge_sort(arr, low, mid);
    counter += merge_sort(arr, mid + 1, high);
    counter += count_pairs(arr, low, mid, high); // count pairs before merge
    merge(arr, low, mid, high);
    return counter;
}

int reverse_pairs_optimized(vector<int> &arr, int low, int high)
{
    return merge_sort(arr, low, high);
}

int main()
{
    vector<int> arr = {5, 3, 2, 1, 4};
    cout << "Total pairs(Brute-force): " << reverse_pairs_count(arr, arr.size()) << endl;
    cout << "Total pairs(Optimized): " << reverse_pairs_optimized(arr, 0, arr.size() - 1);
}
