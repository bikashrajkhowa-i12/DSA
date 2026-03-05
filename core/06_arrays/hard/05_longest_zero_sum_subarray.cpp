/*
Given an array containing both positive and negative integers, we have to find the length of the
longest subarray with the sum of all elements equal to zero.

Examples
Example 1:
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result:
 5
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.

Example 2:
Input:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result:
 8
Explanation:
 Subarrays with sum zero:
- {-2, 2}
- {-8, 1, 7}
- {-2, 2, -8, 1, 7}
- {6, -2, 2, -8, 1, 7, 4, -10}
The length of the longest subarray with sum zero is 8.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Brute-force
 TC: O(n*n*n); SC: O(n)
*/
int brute(vector<int> &arr)
{
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                vector<int> res;
                for (int k = i; k <= j; k++)
                {
                    res.push_back(arr[k]);
                }
                int newLen = res.size();
                maxLen = max(maxLen, newLen);
            }
        }
    }
    return maxLen;
}

/* Better approach
    TC: O(n*n); SC: O(1);
*/

int better(vector<int> &arr)
{
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                maxLen = max(j - i + 1, maxLen);
            }
        }
    }
    return maxLen;
}

/* Optimized-approach
    Core-Intuition:
        - "Seeing the same sum again means somewhere in between, the numbers added and subtracted canceled out to 0."

    Complexity:
        - TC: O(n logn)
        - SC: O(n)
*/

int optimized(vector<int> &arr)
{
    int maxLen = 0;
    int sum = 0;
    unordered_map<int, int> ump;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = max(maxLen, i + 1);
        }
        else
        {
            if (ump.find(sum) != ump.end())
            {
                maxLen = max(maxLen, i - ump[sum]);
            }
            else
            {
                ump[sum] = i;
            }
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    cout << endl
         << "Longest zero-sum subarray length(brute): " << brute(arr);

    cout << endl
         << "Longest zero-sum subarray length(better): " << better(arr);

    cout << endl
         << "Longest zero-sum subarray length(optimized): " << optimized(arr);
}