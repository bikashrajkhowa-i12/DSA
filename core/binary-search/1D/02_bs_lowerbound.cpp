/*
## Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.
## The lower bound algorithm finds the first or the smallest index in a sorted array where the value at
   that index is greater than or equal to a given key i.e. x.
## The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found,
   the lower bound algorithm returns n i.e. size of the given array.

Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

Example 2:
Input Format: N = 5, arr[] = {3,5,8,15,19}, x = 9
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
*/

// N=8 arr = [1,2,2,3,8,15,19,19], x = 2
/*
mid > = target ? high = mid - 1 : low = mid + 1;

*/
#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int idx = n;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
        {
            idx = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return idx;
}

int main()
{
    int target;
    vector<int> arr = {1, 2, 2, 3, 8, 15, 19, 19};

    cout << "Enter a target: ";
    cin >> target;

    cout << "The lowerbound of " << target << " is at index " << lowerbound(arr, arr.size(), target);
}