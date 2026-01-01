/*
Given a sorted array: [3, 4, 6, 7, 9, 11, 13, 17], use binary search to find target = 6 and return the index.
*/

#include <bits/stdc++.h>
using namespace std;

// iterative
// TC: O(logn) SC: O(logn)
int binary_search(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target == arr[mid])
            return mid;
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// recursive binary search
int recursive_bs(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    if (target == arr[mid])
        return mid;
    else if (target > arr[mid])
        recursive_bs(arr, target, mid + 1, high);
    else
        recursive_bs(arr, target, low, mid - 1);
}

int main()
{
    int target;
    vector<int> arr = {3, 4, 6, 7, 9, 11, 13, 17, 21};

    cout << "Enter the element to be searched: ";
    cin >> target;

     cout << "The element " << target << " is at index: " << binary_search(arr, arr.size(), target);
//    cout << "The element " << target << " is at index: " << recursive_bs(arr, target, 0, arr.size() - 1);
}
