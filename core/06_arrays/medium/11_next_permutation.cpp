/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3],
[2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
then the next permutation of that array is the permutation that follows it in the sorted container.
If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.
*/

#include <bits/stdc++.h>
using namespace std;

// ({1,2,3}, 0, {})
void permute(vector<int> &nums, int start, vector<vector<int>> &allPerms)
{
    if (start == nums.size())
    {
        allPerms.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        swap(nums[start], nums[i]);
        permute(nums, start + 1, allPerms);
        swap(nums[start], nums[i]); // backtracking
    }
}

// TC: O(n! * n); SC: O(n)
void brute_next_permutation(vector<int> &arr)
{
    vector<vector<int>> allPerms;

    /*
    - find all permutations.
    - match the current sequence
    - return the current + 1 sequence(if exists)
    - else return sequence[0];
    */

    // 1. generate all permutations
    vector<int> sorted_nums = arr;                // {2,1,3}
    sort(sorted_nums.begin(), sorted_nums.end()); // {1,2,3}
    permute(sorted_nums, 0, allPerms);            // ({1,2,3}, 0, {})

    // 2. sort them lexiologically
    sort(allPerms.begin(), allPerms.end());

    // 3. find current permutation
    for (int i = 0; i < allPerms.size(); i++)
    {
        if (allPerms[i] == arr)
        {
            arr = allPerms[(i + 1) % allPerms.size()];
            return;
        }
    }
}

void optimal_next_permutation(vector<int> &arr)
{
}

int main()
{
    vector<int> arr = {2, 1, 3};
    cout << " Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    /* In-built next_permutation
       TC: O(n); SC: O(1)
    */
    // next_permutation(arr.begin(), arr.end());

    /* Brute-force next_permutation
     */
    brute_next_permutation(arr);

    /* Optimal next_permutation
     */
    // optimal_next_permutation(arr);

    cout
        << endl
        << "Next-permutation: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
}