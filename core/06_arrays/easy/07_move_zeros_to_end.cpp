/*
You are given an array of integers, your task is to move all the zeros in the array
to the end of the array and move non-negative integers to the front by maintaining their order.
Input: 1, 0, 2, 3, 0, 0, 4, 0, 1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0, 0

**brute force**
temp = [non-zeros],
d = counter for 0's
push_back or push to the end of the array
push the entire elements to the original array
*/

#include <bits/stdc++.h>
using namespace std;

// brute force TC: O(2n); SC: O(n);
// void move_zeros_to_end(vector<int> &arr, int n)
// {
//     vector<int> temp;

//     // move non-zeros to temp;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > 0)
//         {
//             temp.push_back(arr[i]);
//         }
//     }

//     // reassign the array starting with non-digits first
//     for (int i = 0; i < n; i++)
//     {
//         if (i >= temp.size())
//         {
//             arr[i] = 0; // push zeros if temp is empty
//         }
//         else
//         {
//             arr[i] = temp[i];
//         }
//     }
// }

// using two-pointer
void move_zeros_to_end(vector<int> &arr, int n)
{

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

int main()
{
    vector<int> arr = {6, 0, 0, 2, 0, 3, 3, 0, 3, 0, 0, 4, 0, 0, 1};

    move_zeros_to_end(arr, arr.size());

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
