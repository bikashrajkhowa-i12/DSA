/*
Given an array of N integers, write a program to implement the Recursive Insertion Sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void recurssive_insertion_sort(int arr[], int idx, int n)
{
    if (idx > n - 1)
        return;

    for (int j = idx; j > 0 && arr[j - 1] > arr[j]; j--)
    {

        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
    }

    recurssive_insertion_sort(arr, idx + 1, n);
}

int main()
{
    int n;
    cout << "Enter total array elements: ";
    cin >> n;

    cout << "Enter " << n << " array elements: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    recurssive_insertion_sort(arr, 1, n);

    cout << "Sorted elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
