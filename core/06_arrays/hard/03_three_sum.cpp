/*
Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero.
In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i,
and their sum is equal to zero.

Pre-requisite: 2 Sum Problem

Examples
Example 1:
Input:
 nums = [-1,0,1,2,-1,-4]
Output:
 [[-1,-1,2],[-1,0,1]]
Explanation:
 Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of
 summing up to zero with i!=j!=k


Example 2:
Input:
 nums=[-1,0,1,0]
Output:
 Output: [[-1,0,1],[-1,1,0]]
Explanation:
 Out of all possible unique triplets possible, [-1,0,1] and [-1,1,0] satisfy the condition of
 summing up to zero with i!=j!=k
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
Brute-force
TC: O(n^3); SC: O(n^3)
*/
vector<vector<int>> brute_3sum(vector<int> &arr)
{
    vector<vector<int>> res;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            for (int k = j + 1; k < arr.size(); k++)
            {
                bool unique = (((i != j) != k) != i) ? true : false;
                bool zeroSum = ((arr[i] + arr[j]) + arr[k]) == 0 ? true : false;
                if (unique && zeroSum)
                {
                    res.push_back({arr[i], arr[j], arr[k]});
                }
            }
        }
    }

    return res;
}

/*
Better (hash/map)
TC: O(i × j) = O(n²)
Hash operations (count, insert) are O(1) average.

SC: O(n+k) => n for number of elements in the set, k number of triplets in the resultant vector
*/
vector<vector<int>> better_3sum(vector<int> &arr)
{
    vector<vector<int>> res;
    for (int i = 0; i < arr.size(); i++)
    {
        unordered_set<int> uset;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int firstNum = -(arr[i] + arr[j]); // thirdNum = target(0) - (first + second)
            if (uset.count(firstNum))
            {
                res.push_back({arr[i], arr[j], firstNum});
            }
            uset.insert(arr[j]);
        }
    }
    return res;
}

/*
Optimal approach
TC: O(n log n) + O(n*n) = O(n*n);
SC:
    - O(n*n); //with resultant array output
    - O(log n) // without resultant array, only for the sorting

*/
vector<vector<int>> optimal_3sum(vector<int> &arr)
{
    vector<vector<int>> res;
    sort(arr.begin(), arr.end()); // O(n log n)
    int n = arr.size();

    for (int i = 0; i < n - 2; i++) // since for a triplet we need 3 elements, i, left and right so < n-2
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0)
            {
                res.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;

                while (left < right && arr[left - 1] == arr[left])
                    left++;
                while (left < right && arr[right] == arr[right + 1])
                    right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 0};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    // vector<vector<int>> result = brute_3sum(arr);
    vector<vector<int>> result = better_3sum(arr);
    // vector<vector<int>> result = optimal_3sum(arr);

    cout << endl
         << "Three sum array: [";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++)
        {
            if (j == result[i].size() - 1)
            {
                cout << result[i][j] << "]";
            }
            else
            {
                cout << result[i][j] << ", ";
            }
        }
    }
    cout << "]";
    return 0;
}