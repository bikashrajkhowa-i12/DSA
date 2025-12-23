/*
Given an array of N elements. Find the second-smallest and second-largest without sorting.
Print '-1' if doesn't exists.
Time complexity: O(n) for both.
*/

#include <bits/stdc++.h>
using namespace std;

int second_smallest(vector<int> &arr, int n)
{
    if (n < 2)
        return -1;
    int smallest = arr[0];
    int sSmallest = INT_MAX; // highest limit

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            sSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < sSmallest)
        {
            sSmallest = arr[i];
        }
    }

    if (sSmallest == INT_MAX)
        return -1;
    else
        return sSmallest;
}

int second_largest(vector<int> &arr, int n)
{
    if (n < 2)
        return -1;
    int largest = arr[0];
    int sLargest = -1; // considering the array contains only positive integers or use INT_MIN

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            sLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > sLargest)
        {
            sLargest = arr[i];
        }
    }

    return sLargest;
}

int main()
{
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Second-smallest element in the array is: " << second_smallest(arr, n) << endl;
    cout << "Second-largest element in the array is: " << second_largest(arr, n);
    return 0;
}
