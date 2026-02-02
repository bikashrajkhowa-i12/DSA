/*
Given an array of n integers, sort the array using the Quicksort method.
Steps:
1. Pick a pivot(an element from the array to compare the rest)
2. Swap all elements lesser < pivot < higher.
3. Recursively perform the same until base condition.
4. Type: Divide and conquer
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        // finds the first element index from left and stops
        while (arr[i] <= pivot && i < high)
        {
            i++;
        }

        // finds the first element index from right and stops
        while (arr[j] >= pivot && j > low)
        {
            j--;
        }

        // swap the less <= pivot <= higher
        if (i < j)
            swap(arr[i], arr[j]);
    }

    // Final swap of pivot to its correct place (i.e center)
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        quick_sort(arr, low, pIndex - 1);
        quick_sort(arr, pIndex + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quick_sort(arr, 0, arr.size() - 1);

    cout << "The quick sorted elements are: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
