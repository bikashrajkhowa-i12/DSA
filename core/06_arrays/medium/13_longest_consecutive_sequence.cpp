/*
Given an array nums of n integers.
Return the length of the longest sequence of consecutive integers.
The integers in this sequence can appear in any order.

Example 1:
Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation:
 The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4.
 This sequence can be formed regardless of the initial order of the elements in the array.

Example 2:
Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation:
 The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool linearSearch(vector<int> &arr, int target)
{
    for (int num : arr)
    {
        if (num == target)
            return true;
    }
    return false;
}

// TC: O(n*n); SC: O(1)
int brute_len(vector<int> &arr)
{
    int n = arr.size();
    int longest = 0;

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int count = 1;

        while (linearSearch(arr, x + 1))
        {
            x = x + 1;
            count++;
        }

        longest = max(longest, count);
    }

    return longest;
}

// TC: O(n log n); SC: O(n)
int better_len(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    vector<int> sorted_nums = arr;
    sort(sorted_nums.begin(), sorted_nums.end());

    int maxLen = 1;
    int len = 1;

    for (int i = 0; i < n - 1; i++)
    {
        if (sorted_nums[i] + 1 == sorted_nums[i + 1])
        {
            len++;
        }
        else if (sorted_nums[i] == sorted_nums[i + 1])
        {
            continue; // ignore duplicates
        }
        else
        {
            maxLen = max(maxLen, len);
            len = 1;
        }
    }

    maxLen = max(maxLen, len);

    return maxLen;
}

/* Optimal approach
Idea:
    1. Put all numbers in a HashSet for O(1) lookup.
    2. Only start counting when (num - 1) does NOT exist → start of a sequence.
    3. Expand the sequence by checking (num + 1, num + 2, ...).
    4. Track the maximum length.

    Complexity:
        - Time: O(n)
        - Space: O(n)
*/
int optimal_len(vector<int> &nums)
{
    // store all elements in a set
    unordered_set<int> st(nums.begin(), nums.end());

    int longest = 0;

    for (int num : st)
    {
        // check if num-1 exist in the set, if not then num is the smallest
        if (st.find(num - 1) == st.end())
        {
            int current = num; // starting point of a sequence
            int length = 1;    // track length

            // check if next current + 1 exits -> increament length
            while (st.find(current + 1) != st.end())
            {
                current++;
                length++;
            }

            // update maxLength
            longest = max(longest, length);
        }
    }

    return longest;
}

int main()
{
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int n = nums.size();
    cout << "Given array nums: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << nums[i] << "]";
        else
            cout << nums[i] << ", ";
    }

    cout << endl
         << "Longest consecutive sequence length: ";
    cout << endl
         << "Brute: " << brute_len(nums);
    cout << endl
         << "Better: " << better_len(nums);
    cout << endl
         << "Optimal: " << optimal_len(nums);
    return 0;
}