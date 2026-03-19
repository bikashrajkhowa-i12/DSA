/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

## Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

## Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_arr(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        cout << "[]";
        return;
    }

    cout << "Given arr: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

/* brute-force
    TC: O(n * k)
    SC: O(1)

*/
int brute_missing_no(vector<int> &arr, int k)
{
    int num = 1;
    int missingCount = 0;

    while (true)
    {
        // check if num is NOT in array
        if (find(arr.begin(), arr.end(), num) == arr.end())
        {
            missingCount++;
            if (missingCount == k)
                return num;
        }
        num++;
    }
}

/* better
    TC: O(n)
    SC: O(1)
*/
int better_missing_no(vector<int> &arr, int k)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            k++;
        else
            break;
    }
    return k;
}

/*
    Optimal:
    - missing = arr[i] - (i + 1)
    - Find first index where missing ≥ k using binary search
        - If missing < k → go right
        - Else → go left
    - Answer = low + k

    TC: O(log n)
    SC: O(1)
*/
int optimal_missing_no(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missingNum = arr[mid] - (mid + 1); // arr[i] - index + 1
        if (missingNum < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low + k;
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    print_arr(arr);
    cout << endl
         << "k: " << k;
    cout << endl
         << "The " << k << "th missing +ve number is:";
    cout << endl
         << "Brute: " << brute_missing_no(arr, k);
    cout << endl
         << "Better: " << better_missing_no(arr, k);
    cout << endl
         << "Optimal: " << optimal_missing_no(arr, k);
}