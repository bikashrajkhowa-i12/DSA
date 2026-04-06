/*
Design an algorithm that collects daily price quotes for some stock and returns the span
of that stock's price for the current day.
The span of the stock's price in one day is the maximum number of consecutive days
(starting from that day and going backward) for which the stock price was less than
or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price
of the stock today is 2, then the span of today is 4 because starting from today, the price
of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the
stock today is 8, then the span of today is 3 because starting from today, the price of the
stock was less than or equal 8 for 3 consecutive days.

Example 1:
Input:
 n = 7, arr = [120, 100, 60, 80, 90, 110, 115]
Output:
 1 1 1 2 3 5 6
Explanation:

Traversing the given input span:
120 is greater than or equal to 120 and there are no more elements behind it so the span is 1,
100 is greater than or equal to 100 and smaller than 120 so the span is 1,
60 is greater than or equal to 60 and smaller than 100 so the span is 1,
80 is greater than or equal to 60, 80 and smaller than 100 so the span is 2,
90 is greater than or equal to 60, 80, 90 and smaller than 100 so the span is 3,
110 is greater than or equal to 60, 80, 90, 100, 110 and smaller than 120 so the span is 5,
115 is greater than or equal to all previous elements and smaller than 120 so the span is 6.
Hence the output will be 1 1 1 2 3 5 6.

Example 2:
Input:
 n = 6, arr = [15, 13, 12, 14, 16, 20]
Output:
 1 1 1 3 5 6
Explanation:

Traversing the given input span:
15 is greater than or equal to 15 and there are no more elements behind it, so the span is 1.
13 is smaller than 15, so the span is 1.
12 is smaller than 13, so the span is 1.
14 is greater than or equal to 12 and 13, but smaller than 15, so the span is 3 (days with values 12, 13, and 14).
16 is greater than or equal to 14, 12, 13, and 15, so the span is 5.
20 is greater than or equal to all previous elements, so the span is 6.
Hence the output will be 1 1 1 3 5 6.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_arr(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
    {
        cout << "[]";
        return;
    }

    cout << "Given array: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

/* -------------------- BRUTE FORCE VERSION -------------------- */
/*
Time: O(n^2)
For every next(price), we scan all previous prices.
*/
class StockSpannerBrute
{
public:
    vector<int> prices;

    int next(int price)
    {
        prices.push_back(price);

        int span = 0;
        int i = prices.size() - 1;

        while (i >= 0 && prices[i] <= price)
        {
            span++;
            i--;
        }

        return span;
    }
};

/* -------------------- OPTIMIZED VERSION -------------------- */
/*
Time: O(n) overall (O(1) amortized per call)
Using Monotonic Decreasing Stack
*/
class StockSpannerOptimized
{
public:
    StockSpannerOptimized()
    {
        //  nothing to initialize
    }

    stack<pair<int, int>> st; // {price, span}

    int next(int price)
    {
        int span = 1;

        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

/* -------------------- DRIVER CODE -------------------- */

int main()
{
    vector<int> input = {100, 80, 60, 70, 60, 75, 85};

    StockSpannerBrute brute;
    StockSpannerOptimized opt;

    cout << "Input Prices: ";
    for (int p : input)
        cout << p << " ";
    cout << "\n\n";

    cout << "Brute Output:      ";
    for (int p : input)
        cout << brute.next(p) << " ";
    cout << "\n";

    cout << "Optimized Output:  ";
    for (int p : input)
        cout << opt.next(p) << " ";
    cout << "\n";

    return 0;
}