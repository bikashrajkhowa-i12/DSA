#include <bits/stdc++.h>
using namespace std;

// Kadane's algorithm(optimized)
// TC: O(n); SC: O(1)
long long Kadane_max_sum(vector<int> &arr)
{
    long long sum = 0, maxSum = LONG_MIN;
    int start = 0, ansStart = -1, ansEnd = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        // we count the indexes where it sum starts with non-negatives
        if (sum == 0)
            start = i;

        sum += arr[i];

        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    cout << "\nSub-array indexes from " << ansStart << " to " << ansEnd << endl;
    return maxSum;
}

int main()
{
    // vector<int> arr = {-1, -3, -1, -2, -3};
    vector<int> arr = {2, 3, 5, -2, 7, -4};
    cout << "Given array: ";
    for (int i : arr)
    {
        cout << i << ", ";
    }
    // cout << endl
    //      << "Result(brute): " << max_subarray_sum(arr);
    cout << endl
         << "Result(optimized): " << Kadane_max_sum(arr);
}