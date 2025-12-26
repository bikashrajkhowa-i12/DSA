/*
Given an array of N elements, left rotate the array by D places.
*/

#include <bits/stdc++.h>
using namespace std;

// brute force
//  void left_rotate_by_n(vector<int> &arr, int n, int &d)
//  {
//      d = d % n; // core

//     if (d <= 0)
//         return;

//     while (d > 0)
//     {
//         int temp = arr[0];

//         for (int j = 1; j < n; j++)
//         {
//             arr[j - 1] = arr[j];
//         }
//         arr[n - 1] = temp;
//         d--;
//     }
// }

// optimal using reversal
// void left_rotate_by_n(vector<int> &arr, int n, int d)
// {
//     d = d % n;

//     reverse(arr.begin(), arr.begin() + d);
//     reverse(arr.begin() + d, arr.end());
//     reverse(arr.begin(), arr.end());
// }

// optimal with an temp memory of size of 'd'
void left_rotate_by_n(vector<int> &arr, int n, int d)
{
    d = d % n;
    vector<int> temp;

    // copy d elements from arr to temp
    for (int i = 0; i < d; i++)
    {
        temp.push_back(arr[i]);
    }

    // shift the elements from d'th places in original array
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    // arr [1,2,3,4,5]
    // d = 2
    // arr [3,4,5,4,5]
    // temp [1,2]
    // i = n - d = 5 - 2 = 3
    //  i - n - d
    //  3 - (5 - 2) = 0
    //  4 - (5 - 2) = 1

    //  push the temp elements back of the original array
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }
}

int main()
{
    int d;
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    cout << endl
         << "Enter no of left-rotate places: ";
    cin >> d;

    left_rotate_by_n(arr, arr.size(), d);

    cout << endl
         << "After left-rotating by " << d << " places: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
