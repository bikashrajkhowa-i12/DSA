/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Exampel 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

#include <bits/stdc++.h>

using namespace std;

double brute_pow(double x, int n)
{
    double res = 1.0;

    long long power = n; // promote first

    if (power < 0)
    {
        x = 1.0 / x;
        power = -power; // safe now
    }

    for (long long i = 0; i < power; i++)
        res *= x;

    return res;
}

int main()
{
    double x = 2.10000;
    int n = 3;
    cout << "Given,\n\tx: " << x << endl
         << "\tn: " << n;
    cout << endl
         << "Pow(" << x << "^" << n << "): ";
    cout << brute_pow(x, n);
}