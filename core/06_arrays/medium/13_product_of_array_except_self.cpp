/*
Given an integer array nums, return an array answer such that answer[i] is equal to
the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

#include <iostream>
#include <vector>
using namespace std;

/* brute-force approach
    TC: O(n*n); SC: O(n)
*/
vector<int> brute(vector<int> &nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int prod = 1;
        for (int j = 0; j < nums.size(); j++)
        {
            if (j == i)
                continue;
            prod *= nums[j];
        }
        res.push_back(prod);
    }
    return res;
}

vector<int> prefix_prod(vector<int> &arr)
{
    vector<int> res(arr.size());
    int prod = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            res[i] = 1;
        else
        {
            res[i] = prod;
            prod *= arr[i];
        }
    }
    return res;
}

vector<int> suffix_prod(vector<int> &arr)
{
    vector<int> res(arr.size());
    int prod = arr[arr.size() - 1];

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (i == arr.size() - 1)
            res[i] = 1;
        else
        {
            res[i] = prod;
            prod *= arr[i];
        }
    }
    return res;
}

/* optimal approach
    - prefix_prod[i]
    - suffix_prod[i]
    - product of prefix[i] * product of suffix[i]

    Complexity:
        - TC: O(n) + O(n) + O(n) = O(3n) => O(n)
        - SC: O(n) + O(n) = O(2n) => O(n) excluding the output array
*/
vector<int> optimal(vector<int> &arr)
{
    vector<int> prefix = prefix_prod(arr);
    vector<int> suffix = suffix_prod(arr);
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        res.push_back(prefix[i] * suffix[i]);
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    // vector<int> res = brute(arr);
    vector<int> res = optimal(arr);

    cout << endl
         << "Result: [";
    for (int i = 0; i < res.size(); i++)
    {
        if (i == res.size() - 1)
            cout << res[i] << "]";
        else
            cout << res[i] << ", ";
    }

    // cout << endl
    //      << "Max subarray product(optimized) : " << optimal(arr);
}