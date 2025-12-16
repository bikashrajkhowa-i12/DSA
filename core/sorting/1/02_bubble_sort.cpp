/*
Bubble sort: Repeatedly compares adjacent elements.
Swaps if they are in wrong order.
Largest element buddles to the end.
Time: O(n^2)
Space: O(1), in-place
*/

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }

        // if sorted, early terminate
        // say input array is 1,2,3,4,5,7,6 -> only one swap, while for the next time iteration it will terminate
        // also if already sorted array is passed
        if (!swapped)
            break;
    }
}

int main()
{
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(arr, n);

    cout << endl
         << "Sorted elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
