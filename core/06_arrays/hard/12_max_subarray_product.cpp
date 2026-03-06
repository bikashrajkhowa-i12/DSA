/*
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Note that the product of an array with a single element is the value of that element.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <iostream>
#include <vector>

using namespace std;

/* Brute-force approach
    TC: O(n*n); SC: O(1)
*/

int brute_max_product(vector<int> &arr)
{
    int maxProd = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        int product = 1;
        for (int j = i; j < arr.size(); j++)
        {
            product *= arr[j];
            maxProd = max(maxProd, product);
        }
    }
    return maxProd;
}

/* Optimal approach
    - Track maxProd and minProd.
    - Negative number flips sign → swap(maxProd, minProd).
    - Update using current element.
    - Keep global max.

   Complexity:
        - TC: O(n)
        - SC: O(1)
*/
int optimal_max_product(vector<int> &arr)
{
    int res = 0;
    int minProd = arr[0];
    int maxProd = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < 0)
            swap(maxProd, minProd);
        maxProd = max(arr[i], maxProd * arr[i]);
        minProd = min(arr[i], minProd * arr[i]);

        res = max(res, maxProd);
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    cout << endl
         << "Max subarray product(brute) : " << brute_max_product(arr);
    cout << endl
         << "Max subarray product(optimized) : " << optimal_max_product(arr);
}