/*
Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array.
The output can be returned in any order.

Examples
Example 1:
Input:
 nums = [1, 2, 1, 1, 3, 2]
Output:
 [1]
Explanation:
 Here, n / 3 = 6 / 3 = 2.
Therefore, the elements appearing 3 or more times are: [1].

Example 2:
Input:
 nums = [1, 2, 1, 1, 3, 2, 2]
Output:
 [1, 2]
Explanation:
 Here, n / 3 = 7 / 3 = 2.
Therefore, the elements appearing 3 or more times are: [1, 2].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// TC: O(n); SC: O(n)
vector<int> brute_majority_element(vector<int> &arr)
{
    vector<int> res;
    unordered_map<int, int> ump;
    int n = arr.size();

    for (int i = 0; i < arr.size(); i++)
    {
        ump[arr[i]]++;
        if (ump[arr[i]] > n / 3)
            res.push_back(arr[i]);
    }
    return res;
}

/*
frequency > n/3 means at max there can be 2 elements appearing more than twice...minimum 1 element
*/
// TC: ; SC:
vector<int> optimized_majority_element(vector<int> &arr)
{
}

int main()
{
    vector<int> arr = {1, 2, 1, 1, 3, 2, 2};
    cout << "Given array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    vector<int> result = brute_majority_element(arr);
    cout << endl
         << "Majority elements(n/3): [";
    for (int i = 0; i < result.size(); i++)
    {
        if (i == result.size() - 1)
            cout << result[i] << "]";
        else
            cout << result[i] << ", ";
    }
    return 0;
}