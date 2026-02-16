/*
 Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

Examples
Example 1:
Input Format: arr[] = {2,2,1}
Result: 1
Explanation: In this array, only the element 1 appear once and so it is the answer.


Example 2:
Input Format: arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute-force TC: O(2n); SC: O(n)
int brute_1(vector<int> &arr)
{
    unordered_map<int, int> ump;

    for (int i = 0; i < arr.size(); i++)
    {
        ump[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (ump[arr[i]] < 2)
            return arr[i];
    }
    return -1;
}

/*Optimized approach***************
    - XOR all elements → duplicates cancel (a ^ a = 0).
    - Remaining value = single occurring element.
    - Time O(n), space O(1).
    - Works only if all others appear exactly twice.
*/
int check_single_appearance(vector<int> &arr)
{
    int xorr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main()
{
    vector<int> arr = {5, 2, 4, 1, 2, 4, 1};
    cout << "Orignal array elements: ";
    for (int i : arr)
    {
        cout << i << ", ";
    }

    cout << endl
         << "Single appearing integer(brute-force): " << brute_1(arr);
    cout << endl
         << "Single appearing integer(optimized): " << check_single_appearance(arr);
}