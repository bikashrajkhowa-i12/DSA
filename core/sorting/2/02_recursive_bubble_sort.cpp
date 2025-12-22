/*
Problem Statement: Given an array of N integers, write a program to implement the Recursive Bubble Sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void rbs(int arr[], int n)
{
    if (n == 1)
        return;

    bool swapped = false;

    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            swapped = true;
        }
    }

    if (!swapped)
        return;
    else
        rbs(arr, n - 1);
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    rbs(arr, n); // rbs=> recurssive bubble sort

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
