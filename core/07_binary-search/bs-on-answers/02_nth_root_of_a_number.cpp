/*
Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined
as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.

Example 1:
Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.

Example 2:
Input : N = 4, M = 69
Output: -1
Explanation : The 4th root of 69 does not exist. So, the answer is -1.
*/

#include <iostream>
using namespace std;

bool isRootOf(int &N, int &M, int &num)
{
    long long product = 1;

    for (int i = 1; i <= N; i++)
    {
        product *= num;
        if (product > M)
            break;
    }
    return product == M ? true : false;
}

/* brute force
    TC: O(M * N)
    SC: O(1)
*/
int brute_nth_root(int &N, int &M)
{
    for (int num = 1; num <= M; num++)
    {
        if (isRootOf(N, M, num))
            return num;
    }

    return -1;
}

int main()
{
    int N = 5, M = 1;
    cout << "N: " << N << ", M: " << M;
    cout << endl
         << "Nth root: " << brute_nth_root(N, M);
}