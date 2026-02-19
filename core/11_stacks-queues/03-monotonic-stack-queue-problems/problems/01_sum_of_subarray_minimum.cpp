/*
Given an array of integers arr of size n, calculate the sum of the minimum value in each (contiguous) subarray of arr.
Since the result may be large, return the answer modulo 10⁹ +7.

Example:
Input:
 arr = [3, 1, 2, 5]
Output:
 18
Explanation:
 The minimum of subarrays: [3], [1], [2], [5], [3, 1], [1, 2], [2, 5], [3, 1, 2], [1, 2, 5], [3, 1, 2, 5]
 are 3, 1, 2, 5, 1, 1, 2, 1, 1, 1 respectively and their sum is 18.
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* approach
minSum = 0
for i =0 to n-1
    for j=i to n-1
        for(k=i to j)
            minSum += min(minSum, arr[k]);
*/

// TC: O(n*n); SC: O(1)
int min_sum(vector<int> &arr)
{
    int minSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            int minSub = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                minSub = min(minSub, arr[k]);
            }
            minSum += minSub;
        }
    }
    return minSum;
}

/* Optimal approach*************
Instead of: What is the minimum of each subarray?”
Find: “For each element, how many subarrays consider it the minimum?”
Then apply: element × number of subarrays where it is minimum
And add it for all elements
*/

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
        res[i] = st.empty() ? -1 : st.top();
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
        res[i] = st.empty() ? arr.size() : st.top(); // for empty stack means the element is beyond arr.size() - 1
        st.push(i);
    }
    return res;
}

// TC: O(n); SC: O(n)
int optimized_min_sum(vector<int> &arr)
{
    int total = 0;
    long long mod = 1e9 + 7;
    vector<int> ple = PLE(arr); // Eg: [1,2,3,4]
    vector<int> nle = NLE(arr); // Eg: [1,2,3,4]

    for (int i = 0; i < arr.size(); i++)
    {
        long long left = i - ple[i];
        long long right = nle[i] - i;
        total += ((long long)arr[i] * left * right) % mod; // % mod incase the result is extremely big
    }

    return total;
}

int main()
{
    vector<int> arr = {3, 1, 2, 5};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << ", ";
    }

    cout << endl
         << "Min subarray sum(brute): " << min_sum(arr);
    cout << endl
         << "Min subarray sum(optimal): " << optimized_min_sum(arr);
}