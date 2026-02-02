/*
Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N.
Find the number(between 1 to N), that is not present in the given array..

Examples
Example 1:
Input Format: N = 5, array[] = {1,2,4,5}
Result: 3
Explanation: In the given array, number 3 is missing. So, 3 is the answer.


Example 2:
Input Format: N = 3, array[] = {1,3}
Result: 2
Explanation: In the given array, number 2 is missing. So, 2 is the answer.
*/

#include <bits/stdc++.h>
using namespace std;

// brute TC: O(N x N)
// int missing_number(vector<int> &arr, int N)
// {
//     for (int i = 0; i < N; i++)
//     {
//         bool flag = 0;
//         for (int j = 0; j < N; j++)
//         {
//             if (arr[i] == j)
//             {
//                 flag = 1;
//                 break;
//             }
//         }

//         if (flag == 0)
//             return i;
//     }
// }

// better
// TC: O(2N); SC: O(N+1) or O(N)
// int missing_number(vector<int> &arr, int N)
// {
//     int hash[N + 1] = {0};

//     for (int i = 0; i < N - 1; i++)
//     {
//         hash[arr[i]] = 1;
//     }

//     for (int i = 1; i <= N; i++)
//     {
//         if (hash[i] == 0)
//             return i;
//     }

//     return -1;
// }

// optimal
// TC: O(N) SC: O(1)
// limitations: incase N is very huge, "int" will explode (long will work)
// best is the XOR
int missing_number(vector<int> &arr, int N)
{
    int totalSum = (N * (N + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }

    return totalSum - sum;
}

int main()
{
    int N;
    cout << "Enter an integer(+ve): ";
    cin >> N;

    vector<int> arr(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> arr[i];
    }

    cout << "The missing number between " << arr[0] << " to " << arr[arr.size() - 1] << " is: " << missing_number(arr, N);
}
