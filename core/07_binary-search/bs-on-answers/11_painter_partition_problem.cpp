/*
Given an array/list of length ‘N’, where the array/list represents the boards
and each element of the given array/list represents the length of each board.
Some ‘K’ numbers of painters are available to paint these boards. Consider that
each unit of a board takes 1 unit of time to paint. You are supposed to return
the area of the minimum time to get this job done of painting all the ‘N’ boards
under the constraint that any painter will only paint the continuous sections of
boards.

Example 1:
Input Format: N = 4, boards[] = {5, 5, 5, 5}, k = 2
Result: 10
Explanation: We can divide the boards into 2 equal-sized partitions, so each
painter gets 10 units of the board and the total time taken is 10.

Example 2:
Input Format: N = 4, boards[] = {10, 20, 30, 40}, k = 2
Result: 60
Explanation: We can divide the first 3 boards for one painter and the last board
for the second painter.

Example 3:
Input Format: N = 4, boards[] = {5, 10, 30, 20, 15}, k = 3
Result: 35
Explanation: We can divide the first 3 boards for one painter and the last board
for the second painter.
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

    cout << "Given boards: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

int sum(vector<int> &arr)
{
    int sum = 0;
    for (int i : arr)
        sum += i;
    return sum;
}

bool canPaintAllBoards(vector<int> &boards, int k, int limit)
{
    int paintersCount = 1;
    int currBoardLen = 0;

    for (int board : boards)
    {
        if (board > limit)
            return false;

        if (currBoardLen + board <= limit)
            currBoardLen += board;
        else
        {
            currBoardLen = board;
            paintersCount++;
        }

        if (paintersCount > k)
            return false;
    }

    return true;
}

/* brute
    limit = maxSum - minSum
    TC: O(n) + O(limit * n) => O(n * limit)
    SC: O(1)
*/
int brute_min_time(vector<int> &arr, int k)
{
    int minTime = *min_element(arr.begin(), arr.end()); // atleast one pair must paint the largest board
    int maxTime = sum(arr);                             // one painter paints everything (k = 1 worst case)
    int result = maxTime;

    for (int limit = minTime; limit <= maxTime; limit++)
    {
        if (canPaintAllBoards(arr, k, limit))
        {
            result = limit;
            break;
        }
    }

    return result;
}

/* optimized
    limit = maxSum - minSum
    TC: O(n) + O(log limit * n) => O(n * log limit)
    SC: O(1)
*/
int optimized_min_time(vector<int> &arr, int k)
{
    int low = *min_element(arr.begin(), arr.end());
    int high = sum(arr);
    int result = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canPaintAllBoards(arr, k, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return result;
}

int main()
{
    vector<int> boards = {5, 10, 30, 20, 15};
    int k = 3;
    print_arr(boards);
    cout << endl
         << "k(painters): " << k;
    cout << endl
         << "--Minimum time required--";
    cout << endl
         << "brute: " << brute_min_time(boards, k);
    cout << endl
         << "brute: " << optimized_min_time(boards, k);
}