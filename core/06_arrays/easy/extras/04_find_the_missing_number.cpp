/*
Given an array arr[] of size n with distinct integers in the range of [1, n].
This array represents a permutation of the integers from 1 to n with one element missing.
Find the missing element in the array.

Example 1:
Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.

Example 1:
Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: Here the size of the array is 4, so the range will be [1, 5]. The missing number between 1 to 5 is 4
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// TC: O(n*n); SC: O(1)
int brute_missing_no(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;

    for (int i = 1; i <= n; i++) // problem states `i` from 1 to n
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            return i;
    }

    return -1;
}

// TC: O(n); SC: O(n)
int better_missing_no(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return -1;

    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
    {
        ump[arr[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (ump.find(i) == ump.end())
            return i;
    }
    return -1;
}

// TC: O(n); SC: O(1)
int optimal_missing_no(vector<int> &arr)
{
    int n = arr.size() + 1; // since one number is missing so size + 1.
    if (n == 0)
        return -1;

    int sum = 0;
    for (int i = 0; i < n - 1; i++) // since we added size + 1
    {
        sum += arr[i];
    }

    int expectedSum = (n * (n + 1)) / 2;

    return expectedSum - sum;
}

int main()
{
    vector<int> arr = {8, 2, 6, 9, 11, 4, 5, 3, 7, 1};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    cout << endl
         << "The missing number is:";
    cout << endl
         << "Brute-force: " << brute_missing_no(arr);
    cout << endl
         << "Better: " << better_missing_no(arr);
    cout << endl
         << "Optimal: " << optimal_missing_no(arr);
}