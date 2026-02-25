/*
Given an integer array nums of size n, return the majority element of the array.

The majority element of an array is an element that appears more than n/2 times in the array.
The array is guaranteed to have a majority element.

Example :
Input:
 nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]
Output:
 7
Explanation:
 The number 7 appears 5 times in the 9-sized array, making it the most frequent element.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// TC: O(n); SC: O(n)
int majority_element(vector<int> &arr)
{
    if (arr.size() == 0)
        return 0;

    unordered_map<int, int> ump;
    int majority_ele;
    for (int i = 0; i < arr.size(); i++)
    {
        ump[arr[i]]++;
        if (ump[arr[i]] >= arr.size() / 2)
        {
            majority_ele = arr[i];
            break;
        }
    }
    return majority_ele;
}

// TC: O(n); SC: O(1)
int optimized_majority_element(vector<int> &arr)
{
    // since it appears more than half, if we cancel out the majority element will not get cancelled out.
    // hence return the uncancelled element.
    int majority_ele = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            majority_ele = arr[i];
            count++;
        }
        else if (arr[i] == majority_ele)
            count++;
        else
            count--;
    }

    // verification
    int freq = 0;
    for (int i : arr)
    {
        if (i == majority_ele)
            freq++;
    }
    if (freq > arr.size() / 2)
        return majority_ele;
    else
        return -1;
}

int main()
{
    vector<int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 2, 1, 2};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    cout << endl
         << "Majority element(brute): " << majority_element(arr);
    cout << endl
         << "Majority element(optimal): " << optimized_majority_element(arr);
}