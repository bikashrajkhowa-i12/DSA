/*
 You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer
 positions of ‘n’ gas stations on the X-axis. You are also given an integer ‘k’.
 You have to place 'k' new gas stations on the X-axis. You can place them anywhere
 on the non-negative side of the X-axis, even on non-integer positions. Let 'dist'
 be the maximum value of the distance between adjacent gas stations after adding
 k new gas stations. Find the minimum value of ‘dist’.

Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
Result: 0.5
Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}.
Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’
is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that
the value of ‘dist’ is lower than this.

Example 2:
Input Format: N = 10, arr[] = {1,2,3,4,5,6,7,8,9,10}, k = 1
Result: 1
Explanation: One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10}.
Thus the maximum difference between adjacent gas stations is still 1. Hence, the value of ‘dist’
is 1. It can be shown that there is no possible way to add 1 gas station in such a way that
the value of ‘dist’ is lower than this.
*/

#include <bits/stdc++.h>

using namespace std;

void print_arr(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        cout << "[]";
        return;
    }

    cout << "Given gas-stations: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

int stationsNeeded(vector<int> &stations, double d)
{
    int count = 0;
    for (int i = 1; i < stations.size(); i++)
    {
        double gap = stations[i] - stations[i - 1];
        count += (int)(gap / d);
    }
    return count;
}

// approach - 1
/* Brute
    TC: O((maxGap / step) × n) — for each candidate d, scan all n gaps
    SC: O(1)
*/
double brute_min_max_distance(vector<int> &stations, int k)
{
    int n = stations.size();
    double res = 0.0;
    double gap = stations[n - 1] - stations[0];

    for (double d = 0.01; d <= gap; d += 0.01)
    {
        if (stationsNeeded(stations, d) <= k)
        {
            res = d;
            break;
        }
    }

    return res;
}

// approach - 2
// double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size();

//     // howMany[i] = number of stations added in gap i
//     vector<int> howMany(n - 1, 0);

//     // Place k gas stations
//     for (int gas = 1; gas <= k; gas++) {
//         double maxDist = -1.0;
//         int index = -1;

//         // Find the gap with maximum segment length
//         for (int i = 0; i < n - 1; i++) {
//             double gap = arr[i + 1] - arr[i];
//             double currentSegment = gap / (howMany[i] + 1);

//             if (currentSegment > maxDist) {
//                 maxDist = currentSegment;
//                 index = i;
//             }
//         }

//         // Add station in that gap
//         howMany[index]++;
//     }

//     // Compute final answer
//     double ans = 0.0;

//     for (int i = 0; i < n - 1; i++) {
//         double gap = arr[i + 1] - arr[i];
//         double currentSegment = gap / (howMany[i] + 1);

//         ans = max(ans, currentSegment);
//     }

//     return ans;
// }

/* optimized (approach - 1)
   TC: O(n log(maxGap / 1e-6))
   SC: O(1)
*/
double optimized_min_max_distance(vector<int> &stations, int k)
{
    double low = 0;
    double high = stations.back() - stations.front();

    while (high - low > 1e-6)
    { // stop when range is tiny enough
        double mid = (low + high) / 2.0;
        if (stationsNeeded(stations, mid) <= k)
            high = mid;
        else
            low = mid;
    }

    return high;
}

int main()
{
    vector<int> stations = {1, 2, 3, 4, 5};
    int k = 4;
    print_arr(stations);
    cout << endl
         << "k(new stations): " << k;
    cout << endl
         << "-- Minimized max distance between each stations --";
    cout << endl
         << "Brute: " << brute_min_max_distance(stations, k);
    cout << endl
         << "Optimized: " << setprecision(2) << optimized_min_max_distance(stations, k);
}