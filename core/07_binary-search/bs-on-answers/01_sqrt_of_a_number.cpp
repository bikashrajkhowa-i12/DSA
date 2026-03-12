/*
 You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

Examples
Input: N = 36
Output: 6
Explanation: Square root of 36 is 6.
*/
#include <bits/stdc++.h>
using namespace std;

// brute force; TC: O(N); SC:O(1)
// loop through the entire range from 1 to x/2 and check i*i <= num.

// optimal; TC: O(logN); SC: O(1)
int square_root(int num)
{
    int low = 1;
    int high = num / 2;
    int result;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid <= num)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Square root of " << num << " is: " << square_root(num);
}