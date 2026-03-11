/*
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array,
except for A, which appears twice and B which is missing.
Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

Note: You are not allowed to modify the original array.

Example 1:
Input:
 nums = [3, 5, 4, 1, 1]
Output:
 [1, 2]
Explanation:
 1 appears twice in the array, and 2 is missing from the array. So the output is [1, 2].

Example 2:
Input:
 nums = [1, 2, 3, 6, 7, 5, 7]
Output:
 [7, 4]
Explanation:
 7 appears twice in the array, and 4 is missing from the array. So the output is [7, 4].
*/

/*
1 to n
o/p: [A, B] -> A: repeating no; B: missing no
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* Brute Force
TC: O(n) – two linear passes
SC: O(n) – hashmap for frequency
*/
vector<int> brute_find_nums(const vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> freq;

    for (int num : arr)
        freq[num]++;

    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 2)
            repeating = i;
        if (freq[i] == 0)
            missing = i;
    }

    return {repeating, missing};
}

/* Optimized
    TC: O(n)
    SC: O(1)
*/
vector<int> optimal_find_nums(const vector<int> &arr)
{
    long long n = arr.size();

    long long S = n * (n + 1) / 2;
    long long S2 = n * (n + 1) * (2 * n + 1) / 6;

    long long arrSum = 0;
    long long arrSqSum = 0;

    for (int num : arr)
    {
        arrSum += num;
        arrSqSum += (long long)num * num;
    }

    long long val1 = S - arrSum;
    long long val2 = S2 - arrSqSum;

    val2 = val2 / val1; // y + x

    int missing = (val1 + val2) / 2;
    int repeating = missing - val1;

    return {repeating, missing};
}

int main()
{
    vector<int> arr = {1, 2, 3, 6, 7, 5, 7};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    // vector<int> result = brute_find_nums(arr);
    vector<int> result = optimal_find_nums(arr);
    cout << endl
         << "Output: [";
    for (int i = 0; i < result.size(); i++)
    {
        if (i == result.size() - 1)
            cout << result[i] << "]";
        else
            cout << result[i] << ", ";
    }
}