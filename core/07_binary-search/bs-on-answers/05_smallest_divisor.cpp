/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor,
divide all the array by it, and sum the division's result.
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
Each result of the division is rounded to the nearest integer greater than or equal to that element.
(For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).

Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44
*/
#include <iostream>
#include <vector>
#include <algorithm>
// #include <cmath>
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
}

int divisor_sum(const vector<int> &arr, int divisor)
{
    int sum = 0;
    for (int num : arr)
    {
        // int quotient = ceil((double)num / divisor); // inbuild c++ function
        int quotient = (num + divisor - 1) / divisor; // ceiling division
        sum += quotient;
    }
    return sum;
}

int brute_smallest_divisor(const vector<int> &arr, int threshold)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    int maxNum = *max_element(arr.begin(), arr.end());

    for (int divisor = 1; divisor <= maxNum; divisor++)
    {
        int divisorSum = divisor_sum(arr, divisor);
        if (divisorSum <= threshold)
        {
            return divisor;
        }
    }
    return maxNum;
}

int optimized_smallest_divisor(vector<int> &arr, int threshold)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    int maxNum = *max_element(arr.begin(), arr.end());
    int low = 1, high = maxNum;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int divisorSum = divisor_sum(arr, mid);
        if (divisorSum <= threshold)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << "Nums: ", print_arr(nums);
    cout << endl
         << "Threshold: " << threshold;

    cout << endl
         << "Smallest divisor (<= threshold): ";

    cout << endl
         << "\tBrute-force: " << brute_smallest_divisor(nums, threshold);
    cout << endl
         << "\tOptimized: " << optimized_smallest_divisor(nums, threshold);
    return 0;
}