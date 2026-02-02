/*
Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.

Examples

Input: N = 5, arr[] = {2,6,5,8,11}, target = 14
Output : YES
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for first variant for second variant output will be : [1,3].

Input: N = 5, arr[] = {2,6,5,8,11}, target = 15
Output : NO.
Explanation: There exist no such two numbers whose sum is equal to the target.
*/

/*
N = 5, arr[] = {2,6,5,8,11}, target = 14
i => 0 to N-1
j => i+1 to N-1
<N-i === j> ? indexes.push [i,j] break;  else return j++;
return the indexes
if(indexes.size() == 2) ? yes else no;
*/

#include <bits/stdc++.h>
using namespace std;

// brute => TC: O(n^2); SC: O(2);
void two_sum(vector<int> &arr, int n, int target)
{
    vector<int> indexes;

    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) == target)
            {
                indexes.push_back(i);
                indexes.push_back(j);
                flag = true;
                break;
            }
        }
        if (flag == true)
            break;
    }

    if (indexes.size() == 2)
    {
        cout << "YES" << endl;
        cout << "[";
        for (int i : indexes)
        {
            cout << i << ",";
        }
        cout << "]";
    }
    else
    {
        cout << "NO";
    }
}

/*
Better; TC: O(n); SC: O(n)
arr = {2,6,5,8,11}
indexes = if target - arr[i] => push
*/
void two_sum2(vector<int> &arr, int n, int target)
{
    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
    {
        int otherNum = target - arr[i];
        if (target < arr[i])
        {
            otherNum = arr[i] - target;
        }

        if (ump.find(otherNum) != ump.end())
        { // if find() != STOP(end points to one element AFTER the end, i.e STOP an iteration)
            cout << "YES" << endl;
            cout << "[" << ump[otherNum] << ", " << i << "]";
            return;
        }
        ump[arr[i]] = i;
    }
    cout << "NO";
}

// best (if sorted array)
// TC: O(n); SC: O(1)
void two_sum3(vector<int> &arr, int n, int target)
{
    int i = 0;
    int j = n - 1;

    while (i < n && j > 0)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            cout << "YES" << endl;
            cout << "[" << i << ", " << j << "]";
            return;
        }

        if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "NO";
}

int main()
{
    int target;
    cout << "Enter your target: ";
    cin >> target;
    vector<int> arr = {2, 6, 5, 8, 11};

    two_sum3(arr, arr.size(), target);
}
