/*
 Given an integer array nums, determine the range of a subarray, defined as the difference
 between the largest and smallest elements within the subarray. Calculate and return the sum
 of all subarray ranges of nums.

A subarray is defined as a contiguous, non-empty sequence of elements within the array.

Examples
Example 1:
Input:
 nums = [1, 2, 3]
Output:
 4
Explanation:
 The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

Example 2:
Input:
 nums = [1, 3, 3, 8]
Output: 21
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/* brute [1,2,3] => [1] [1,2] [1,2,3] [2] [2,3] [3]
TC: O(n*n); SC: O(1)
*/
int subarray_ranges_sum(vector<int> &arr)
{
    int totalSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int largest = arr[i];
        int smallest = arr[i];

        for (int j = i + 1; j < arr.size(); j++)
        {
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            totalSum += largest - smallest;
        }
    }
    return totalSum;
}

// previous lesser element
vector<int> PLE(vector<int> &arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        res[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return res;
}

// next lesser element
vector<int> NLE(vector<int> &arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        res[i] = !st.empty() ? st.top() : arr.size();
        st.push(i);
    }
    return res;
}

// previous greater element
vector<int> PGE(vector<int> &arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }
        res[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return res;
}

// next greater element
vector<int> NGE(vector<int> &arr)
{
    stack<int> st;
    vector<int> res(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        res[i] = !st.empty() ? st.top() : arr.size();
        st.push(i);
    }
    return res;
}

int subarray_min_sum(vector<int> &arr)
{
    int minSum = 0;
    long long mod = 1e9 + 7;
    vector<int> ple = PLE(arr);
    vector<int> nle = NLE(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - ple[i];
        int right = nle[i] - i;
        minSum += ((long long)arr[i] * left * right) % mod;
    }
    return minSum;
}

int subarray_max_sum(vector<int> &arr)
{
    int maxSum = 0;
    long long mod = 1e9 + 7;
    vector<int> pge = PGE(arr);
    vector<int> nge = NGE(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        int left = i - pge[i];
        int right = nge[i] - i;
        maxSum += ((long long)arr[i] * left * right) % mod;
    }
    return maxSum;
}

/* Approach***********
sum of subarray max - sum of subarray min = sum of subarray range
TC: O(n); SC: O(n)
*/
int optimized_sum(vector<int> &arr)
{
    int sumOfMin = subarray_min_sum(arr);
    int sumOfMax = subarray_max_sum(arr);

    return sumOfMax - sumOfMin;
}

int main()
{
    vector<int> arr = {1, 3, 3};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    cout << endl
         << "Sum of subarray ranges(brute): " << subarray_ranges_sum(arr);

    cout << endl
         << "Sum of subarray ranges(optimized): " << optimized_sum(arr);
}