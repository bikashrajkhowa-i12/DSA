/*
Given an array of N elements, left rotate the array by 1 place.
Eg: [1,4,2,7,3] O/P: [4,2,7,3,1]
Time: O(n)
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &arr, int n)
{
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

int main()
{
    vector<int> arr = {1, 4, 2, 7, 5, 9};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << " ";
    }

    left_rotate(arr, arr.size());

    cout << endl << "After left-rotating by 1: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
}
