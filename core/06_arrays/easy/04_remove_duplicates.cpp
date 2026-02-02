/**
 * Given an integer array sorted in non-decreasing order, remove the duplicates in place
 * such that each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array
should hold the final result. It does not matter what you leave beyond the first k elements.

Examples
Input: arr[]=[1,1,2,2,2,3,3]
Output: [1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and
Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
Output: [1,2,3,4,_,_,_,_,_,_,_]
Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and
therefore return 4 after assigning [1,2,3,4] in the beginning of the array.
 */

#include <bits/stdc++.h>
using namespace std;

// two-pointer approach
int remove_duplicates(vector<int> &arr, int n)
{
    int idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[idx])
        {
            arr[idx + 1] = arr[i];
            idx++;
        }
    }
    return idx + 1;
}

int main()
{
    vector<int> arr = {2, 2, 2, 2, 4, 6, 6, 6, 8, 8, 8, 8, 8};

    // brute force
    // set<int> st;
    // for (int it : arr)
    // {
    //     st.insert(it);
    // }

    // int uniqueEle = 0;
    // cout << "Set elements are: ";
    // for (auto e : st)
    // {
    //     cout << e << " ";
    //     uniqueEle++;
    // }
    // cout << "Total number of unique elements are: " << unqiueEle << endl;

    cout << "Total number of unique elements are: " << remove_duplicates(arr, arr.size()) << endl;

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
