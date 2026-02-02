/**
 * Builds sorted parts one element at a time.
 * Inserts current element into its correct position.
 * Time: O(n^2) (Best case: O(n) if nearly sorted).
 * Space: O(1), in-place.
 * Stable, efficient for small or nearly sorted arrays.
 */

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element-" << i + 1 << ": ";
        cin >> arr[i];
    }

    insertion_sort(arr, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
