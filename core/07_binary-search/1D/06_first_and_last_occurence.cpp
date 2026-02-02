/*
 Given a sorted array of N integers, write a program to find the index
 of the first and last occurrence of the target key. If the target is not found
 then return -1. Note: Consider 0 based indexing

Examples
Example 1:
Input:
 N = 7, target = 13, array[] = {3, 4, 13, 13, 13, 20, 40}
Output:
 { 2, 4 }
*/

#include <bits/stdc++.h>
using namespace std;

int first_occurence(vector<int> &arr, int N, int target)
{
    int low = 0;
    int high = N - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return first;
}

int last_occurence(vector<int> &arr, int N, int target)
{
    int low = 0;
    int high = N - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return last;
}

pair<int, int> first_and_last_occurence(vector<int> &arr, int N, int target)
{
    int first = first_occurence(arr, N, target);
    if (first == -1)
        return {-1, -1};
    int last = last_occurence(arr, N, target);
    return {first, last};
}
int main()
{
    int target;
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};

    cout << "Enter an element: ";
    cin >> target;

    pair<int, int> result = first_and_last_occurence(arr, arr.size(), target);

    cout << result.first << ", " << result.second;
    return 0;
}