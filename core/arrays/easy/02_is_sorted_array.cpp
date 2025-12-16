/**
 * Given an array nums of n integers, return true if the array nums is sorted in
 * non-decreasing order or else false.
 */

#include <bits/stdc++.h>
using namespace std;

bool check_sorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << endl << "Is sorted array?: " << boolalpha << check_sorted(arr, n);
}
