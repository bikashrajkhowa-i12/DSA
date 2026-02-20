/*
You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day
in the future to sell that stock. Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.

Examples
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <iostream>
#include <vector>

using namespace std;

/* Brute Approach
Idea: For every buy day → check all future sell days.
TC: O(n*n); SC: O(1)
*/
int max_profit(vector<int> &arr)
{
    int maxProfit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                maxProfit = max(maxProfit, arr[j] - arr[i]);
            }
        }
    }
    return maxProfit > 0 ? maxProfit : 0;
}

/* Optimal approach
Idea:
    > Instead of checking all previous buy days for each sell day…
    > Just remember the best (minimum) buy price seen so far
TC: O(n); SC: O(1)
*/
int optimized_max_profit(vector<int> &arr)
{
    int minPrice = arr[0];
    int maxProfit = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int profit = arr[i] - minPrice;
        maxProfit = max(maxProfit, profit);
        minPrice = min(minPrice, arr[i]);
    }

    return maxProfit;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << "Given prices: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i];
        else
            cout << arr[i] << ", ";
    }
    cout << "]";

    cout << endl
         << "Max-profit: " << max_profit(arr);
    cout << endl
         << "Max-profit: " << optimized_max_profit(arr);
}