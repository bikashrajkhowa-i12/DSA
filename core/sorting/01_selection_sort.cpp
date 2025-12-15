/*
## Selection sort: Picks minimum element and places it at current position.
## Repeats until n-2 element.
## Time: O(n^2)
## Space: O(1), in-place
*/

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minAddress = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minAddress])
            {
                minAddress = j; // address of smaller number
            }
        }

        int temp = arr[minAddress];

        // swapping the index value with the "i"th value
        arr[minAddress] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }

    selection_sort(arr, n);

    cout << endl
         << "The sorted elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
