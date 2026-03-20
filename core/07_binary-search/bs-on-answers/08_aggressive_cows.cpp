/*
You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum
distance between any two of them is the maximum possible. Find the maximum possible
minimum distance.

Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
 The maximum possible minimum distance between any two cows will be 3 when
 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows
 are 3, 4, and 3 respectively. We cannot make the minimum distance greater
 than 3 in any ways.

Example 2:
Input Format:
 N = 5, k = 2, arr[] = {4,2,1,3,6}
Result:
 5
Explanation:
 The maximum possible minimum distance between any two cows will be 5 when 2 cows
 are placed at positions {1, 6}.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_arr(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        cout << "[]";
        return;
    }

    cout << "Given stalls: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

bool canPlace(vector<int> &arr, int k, int distance)
{
    int cows = 1;
    int last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - last >= distance)
        {
            cows++;
            last = arr[i];
        }

        if (cows >= k)
            return true;
    }

    return false;
}

/* brute
    TC: O(n log n) + O(distance * n) => O(distance * n)
    SC: O(1)
*/
int find_distance(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int distance = arr[arr.size() - 1] - arr[0];

    for (int i = 1; i <= distance; i++)
    {
        if (!canPlace(arr, k, i))
            return i - 1;
    }
    return distance;
}

/* Optimized
    distance = high
    TC: O(n log n) + O(log(distance) * n)
    SC: O(1)
*/
int optimized_find_distance(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr[arr.size() - 1] - arr[0];

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canPlace(arr, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {4, 2, 1, 3, 6}; // stalls
    int k = 2;                         // cows
    print_arr(arr);
    cout << endl
         << "Cows(k): " << k;
    cout << endl
         << "Minimum max-distance between cows: ";
    cout << endl
         << "Brute: " << find_distance(arr, k);

    cout << endl
         << "Optimized: " << optimized_find_distance(arr, k);
}