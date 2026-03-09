/*
Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated
between 1 to N times which is unknown. Find how many times the array has been rotated.

Pre-requisites: Find minimum in Rotated Sorted Array,  Search in Rotated Sorted Array II & Binary Search algorithm

Examples
Input : arr = [4,5,6,7,0,1,2,3]
Result: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Input : arr = [3,4,5,1,2]
Output : 3
Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.
*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// TC: O(n); SC: O(2)
int brute_total_rotations(vector<int> &arr)
{
    if (arr.size() == 0)
        return -1;
    /*
    find min, -> store as pair<int int> (min, index);
    return index;
    */
    int n = arr.size();
    pair<int, int> min;

    min.first = arr[0];
    min.second = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min.first)
        {
            min.first = arr[i];
            min.second = i;
        }
    }
    return min.second;
}

// TC: O(logn); SC: O(1)
int optimized_total_rotations(vector<int> &arr)
{
    if (arr.size() == 0)
        return -1;
    /*
        - target is find min and return its index
        - sorted -> binary search on the sorted part
        - check which part is sorted
        - return low
    */

    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
        }
        else if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    cout << endl
         << "Total rotations(brute): " << brute_total_rotations(arr);
    cout << endl
         << "Total rotations(optimal): " << optimized_total_rotations(arr);
}