/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_arr(const vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < m; j++)
        {
            if (j == m - 1)
                cout << arr[i][j] << "]";
            else
                cout << arr[i][j] << ", ";
        }
        if (i == n - 1)
            cout << "]";
        else
            cout << ", ";
    }
    return;
}

/* optimized
    Core-Idea: Overlapping intervals only make sense when they are sorted and close to each other in order.
    TC: O(n log n) + O(n) => O(n log n)
    SC: O(n)
*/
vector<vector<int>> optimized_overlapping_intervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());

    pair<int, int> current_pair(arr[0][0], arr[0][1]);
    vector<vector<int>> res;

    for (int i = 1; i < arr.size(); i++)
    {
        if (current_pair.second >= arr[i][0])
        {
            current_pair.second = max(current_pair.second, arr[i][1]);
        }
        else
        {
            res.push_back({current_pair.first, current_pair.second});
            current_pair.first = arr[i][0];
            current_pair.second = arr[i][1];
        }
    }

    // the last pair
    res.push_back({current_pair.first, current_pair.second});
    return res;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Given array: ", print_arr(arr);
    cout << endl
         << "Merged overlapping intervals(optimized): ",
        print_arr(optimized_overlapping_intervals(arr));
}