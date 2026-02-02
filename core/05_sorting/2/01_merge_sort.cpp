/*
## Split till single element, then merger in sorted order
## Divide and merge.
## Divide arrays into halves, recurssively sort each half, finally merge two sorted halves
## Time complexity: O(nlogn)
## Space complexity: O(n) extra array.
## When to use: for large datasets,guranteed performance matters, sorting linked lists.
*/

#include <bits/stdc++.h>
using namespace std;

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

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high) // base case
        return;

    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);      // left
    merge_sort(arr, mid + 1, high); // right
    merge(arr, low, mid, high);
}

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr, 0, arr.size() - 1);

    for (int x : arr)
    {
        cout << x << " ";
    }
}
