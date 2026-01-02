/*
You are given a sorted array arr of distinct values and a target value x.
You need to search for the index of the target value in the array.

Examples
Example 1:
Input Format: arr[] = {1,2,4,7}, x = 6
Result: 3
Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

Example 2:
Input Format: arr[] = {1,2,4,7}, x = 2
Result: 1
Explanation: 2 is present in the array and so we will return its index i.e. 1.
*/

/*
approach: similar to lowerbound
*/

#include <bits/stdc++.h>
using namespace std;

int insert_position(vector<int> &arr, int n, int target)
{
    if (target <= arr[0])
        return 0;
    else if (target >= arr[n - 1])
        return n;

    int low = 0;
    int high = n - 1;
    int position = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            high = mid - 1;
            position = mid;
        }
        else
            low = mid + 1;
    }

    return position;
}

int main()
{
    int target;
    vector<int> arr = {1, 2, 4, 8, 15, 19};

    cout << "Enter the element to be entered: ";
    cin >> target;

    cout << "The insertion index for " << target << " is: " << insert_position(arr, arr.size(), target);
}
