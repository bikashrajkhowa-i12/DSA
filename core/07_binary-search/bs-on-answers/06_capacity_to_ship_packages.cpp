/*
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship
with packages on the conveyor belt (in the order given by weights). We may not load more weight
than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor
belt being shipped within days days.



## Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages
into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

## Example 2:
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4

## Example 3:
Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
// #include <cmath>

using namespace std;

void print_weights(const vector<int> &weights)
{
    int n = weights.size();
    if (n == 0)
    {
        cout << "[]";
        return;
    }

    cout << "Given weights: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << weights[i] << "]";
        else
            cout << weights[i] << ", ";
    }
    return;
}

int sum(const vector<int> &weights)
{
    int n = weights.size();
    int sum = 0;
    for (int weight : weights)
        sum += weight;
    return sum;
}

int total_days(const vector<int> &weights, int cap)
{
    int totalDays = 1;
    int currentWeight = 0;

    for (int weight : weights)
    {
        if (currentWeight + weight <= cap)
        {
            currentWeight += weight;
        }
        else
        {
            totalDays++;            // new day
            currentWeight = weight; // start with current package for next day
        }
    }
    return totalDays;
}

/* brute-force
    - TC: O(n) + O(maxCap * n) => O(n * maxCap)
    - SC: O(1)
*/
int brute_min_cap(const vector<int> &weights, const int &days)
{
    int minCap = *max_element(weights.begin(), weights.end()); // min weight-capacity
    int maxCap = sum(weights);

    for (int cap = minCap; cap <= maxCap; cap++)
    {
        int totalDays = total_days(weights, cap);
        if (totalDays <= days)
            return cap;
    }
    return maxCap;
}

/* optimized
    - TC: O(n) + O(log(maxCap) * n) => O(n * log(maxCap))
    - SC: O(1)
*/
int optimized_min_cap(const vector<int> &weights, const int &days)
{
    int low = *max_element(weights.begin(), weights.end()); // min weight-capacity
    int high = sum(weights);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalDays = total_days(weights, mid);

        if (totalDays > days)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    print_weights(weights);
    cout << endl
         << "Given days: " << days;

    cout << endl
         << "Minimum capacity/day: ";
    cout << endl
         << "brute: " << brute_min_cap(weights, days);
    cout << endl
         << "optimized: " << optimized_min_cap(weights, days);
}