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

int checkRoot(int N, int M, int num)
{
    long long product = 1;

    for (int i = 1; i <= N; i++)
    {
        product *= num;

        if (product > M)
            return 1; // too big
    }

    if (product == M)
        return 0; // exact match

    return -1; // too small
}

/* optimized
    TC: O(N * log M)
    SC: O(1)
*/
int optimized_nth_root(int &N, int &M)
{
    int low = 1;
    int high = M;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int result = checkRoot(N, M, mid);

        if (result == 0)
        { // found exact root;
            return mid;
        }
        else if (result == 1)
        { // mid^N > M
            high = mid - 1;
        }
        else
        { // mid^N < M
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int N = 4, M = 256;
    cout << "N: " << N << ", M: " << M;
    cout << endl
         << "Nth root(brute): " << brute_nth_root(N, M);
    cout << endl
         << "Nth root(optimized): " << optimized_nth_root(N, M);
}