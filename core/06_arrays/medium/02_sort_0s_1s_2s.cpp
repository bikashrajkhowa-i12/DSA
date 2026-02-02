/*
 Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.
 The sorting must be done in-place, without making a copy of the original array.

Examples
Input: nums = [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two
*/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n+n); SC: O(1)
void brute_sort_nums(vector<int> &arr, int N)
{
    int count0s = 0;
    int count1s = 0;
    int count2s = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
            count0s++;
        else if (arr[i] == 1)
            count1s++;
        else
            count2s++;
    }

    int index = 0;

    while (count0s--)
    {
        arr[index++] = 0;
    }

    while (count1s--)
    {
        arr[index++] = 1;
    }

    while (count2s--)
    {
        arr[index++] = 2;
    }
}

/*
********************Core idea(Optimized)******************
Dutch National Flag Algorithm (0s, 1s, 2s)

Core idea:
Partition the array into three regions in a single pass by shrinking
the unknown region while expanding the sorted regions on both ends.

Invariants:
- [0 .. low-1]     → all 0s (sorted left)
- [low .. mid-1]   → all 1s
- [mid .. high]    → unknown (to be processed)
- [high+1 .. n-1]  → all 2s (sorted right)

Pointer logic:
- If nums[mid] == 0:
    Swap with nums[low], then low++, mid++
    (0 is placed correctly, swapped value is already processed)

- If nums[mid] == 1:
    mid++
    (1 is already in the correct middle region)

- If nums[mid] == 2:
    Swap with nums[high], then high--
    DO NOT increment mid, because the swapped value from high is unprocessed

Termination:
Loop ends when mid > high, meaning the unknown region is empty.

Complexity:
- Time: O(n) (single traversal)
- Space: O(1) (in-place)

Key insight:
Never skip processing an unknown value — this is why mid does not move for 2.
*/

// TC: O(n); SC: O(1)
void dnf_algo(vector<int> &arr, int N)
{
    int low = 0;
    int mid = 0;
    int high = N - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> arr1 = {1, 0, 2, 1, 0};
    vector<int> arr2 = {1, 0, 2, 1, 0, 2, 1, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0, 1, 2};

    brute_sort_nums(arr1, arr1.size());
    cout << "Sorted (brute-force): ";
    for (int i : arr1)
    {
        cout << i << " ";
    }

    dnf_algo(arr2, arr2.size());
    cout << endl
         << "Sorted (DNF algorithm): ";
    for (int i : arr2)
    {
        cout << i << " ";
    }
}