/*
Given two arrays arr1 and arr2, find the intersection elements of both arrays.
PS: Both the arrays are sorted
*/

#include <bits/stdc++.h>
using namespace std;

// brute force
// TC: O(nm log (n + m)); SC: O(log (n+m))
// vector<int> intersection_arr(vector<int> &arr1, vector<int> &arr2)
// {
//     set<int> st;
//     vector<int> intersectionArr;

//     for (int i = 0; i < arr1.size(); i++)
//     {
//         for (int j = 0; j < arr2.size(); j++)
//         {
//             if (arr1[i] == arr2[j])
//             {
//                 st.insert(arr1[i]);
//             }
//         }
//     }

//     for (int i : st)
//     {
//         intersectionArr.push_back(i);
//     }

//     return intersectionArr;
// }

// optimized
// TC: O(n+m) SC: O(1)
vector<int> intersection_arr(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();
    vector<int> intersectionArr;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            intersectionArr.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return intersectionArr;
}

int main()
{
    vector<int> arr1 = {2, 3, 4, 5};
    vector<int> arr2 = {3, 5, 9};

    vector<int> intersection = intersection_arr(arr1, arr2);

    for (int i : intersection)
    {
        cout << i << " ";
    }
}
