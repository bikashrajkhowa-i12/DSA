/*
Given an array of integers A and an integer B. Find the total number of subarrays having
bitwise XOR of all elements equal to k.

Example 1:
Input: A = [4, 2, 2, 6, 4] , k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

Example 2:
Input: A = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
*/

#include <iostream>
#include <vector>
using namespace std;

void print_arr(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        cout << "[]";
        return;
    }

    cout << "[";
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
    TC: O(n*n*n)
    SC: O(1)
    **tip: 4^2 = 6 -> binary of 0100 ^ 0010 => 0110 =>6**
*/
int brute_total_count(vector<int> &arr, int target)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int XOR = 0;
            for (int k = i; k <= j; k++)
            {
                XOR = XOR ^ arr[k];
            }

            if (XOR == target)
                count++;
        }
    }

    return count;
}

/* better
    TC: O(n*n)
    SC: O(1)
*/
int better_total_count(vector<int> &arr, int target)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int XOR = 0;
        for (int j = i; j < n; j++)
        {
            XOR = XOR ^ arr[j];
            if (XOR == target)
                count++;
        }
    }

    return count;
}

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Given arr: ", print_arr(nums);
    cout << endl
         << "k: " << k;
    cout << endl
         << "Brute: " << brute_total_count(nums, k);
    cout << endl
         << "Better: " << better_total_count(nums, k);
    return 0;
}