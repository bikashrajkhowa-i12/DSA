/*
You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Examples
Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output
: 4
*/

#include <bits/stdc++.h>
using namespace std;

// brute force; TC: O(n) SC: O(n)
int count_frequency(vector<int> &arr, int N, int target)
{
    unordered_map<int, int> ump;

    for (int i = 0; i < N; i++)
    {
        ump[arr[i]] += 1;
    }

    if (ump.find(target) != ump.end())
    {
        return ump[target];
    }
    return 0;
}

// optimal; TC: O(2logn) SC: O(1);
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

int count_occurences(vector<int> &arr, int N, int target)
{
    int first = first_occurence(arr, N, target);
    if (first == -1)
        return -1;
    int last = last_occurence(arr, N, target);
    return (last - first) + 1; // +1 is for the 0 based indexing
}

int main()
{
    int target;
    vector<int> arr = {2, 2, 3, 3, 3, 3, 4};
    cout << "Enter an element: ";
    cin >> target;

    // brute force
    // cout << "Total occurences of " << target << " is " << count_frequency(arr, arr.size(), target);

    // optimal
    cout << "Total occurences of " << target << " is " << count_occurences(arr, arr.size(), target);
    return 0;
}