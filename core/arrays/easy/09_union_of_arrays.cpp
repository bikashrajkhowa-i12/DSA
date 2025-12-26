/*
Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.

The union of two arrays can be defined as the common and distinct elements in the two arrays.

NOTE: Elements in the union should be in ascending order.

Examples

Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
Output: {1,2,3,4,5}
Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5}
*/

#include <bits/stdc++.h>
using namespace std;

// brute force
// n = arr1.size
// m = arr2.size
// k = st.size
// TC: O((n + m) log (n + m))
// SC: O(k) or worst case: O(n+m)
// void union_array(vector<int> &arr1, vector<int> &arr2, vector<int> &unionArray)
// {
//     set<int> st;

//     for (int i = 0; i < arr1.size(); i++)
//     {
//         st.insert(arr1[i]);
//     }

//     for (int i = 0; i < arr2.size(); i++)
//     {
//         st.insert(arr2[i]);
//     }

//     for (int i : st)
//     {
//         unionArray.push_back(i);
//     }
// }

// optimal two-pointer approach
// TC: O(n + m); SC: O(n + m) (SC in case of returning the array, not for solving)
vector<int> union_array(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();
    vector<int> unionArray;

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArray.size() == 0 || unionArray.back() != arr1[i])
            {
                unionArray.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (unionArray.size() == 0 || unionArray.back() != arr2[j])
            {
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (unionArray.size() == 0 || unionArray.back() != arr1[i])
        {
            unionArray.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (unionArray.size() == 0 || unionArray.back() != arr2[j])
        {
            unionArray.push_back(arr2[j]);
        }
        j++;
    }

    return unionArray;
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 5, 9, 10, 10, 10, 10, 10, 10, 10};
    vector<int> arr2 = {1, 2, 2, 3, 4, 6, 6};
    // vector<int> unionArray; // o/p: [1,2,3,4,5,6,9]

    vector<int> unionArray = union_array(arr1, arr2);
    for (int i : unionArray)
    {
        cout << i << " ";
    }
}
