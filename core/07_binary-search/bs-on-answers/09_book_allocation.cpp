/*
****************Allocate Minimum Number of Pages***************

Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book.
There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a
student is minimum. If the allocation of books is not possible. return -1


Example 1:
Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books
and the other will get the last one.


Example 2:
Input Format:
 n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result:
 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
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

    cout << "Given pages-per-book: [";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }
    return;
}

int sum(const vector<int> &arr)
{
    int sum = 0;
    for (int num : arr)
        sum += num;
    return sum;
}

bool canAllocatePages(vector<int> &arr, int k, int pageLimit)
{
    int students = 1;
    int currentPages = 0;

    for (int pagesInBook : arr)
    {
        if (pagesInBook > pageLimit)
            return false;

        if (currentPages + pagesInBook <= pageLimit)
            currentPages += pagesInBook;
        else
        {
            students++;
            currentPages = pagesInBook;
        }

        if (students > k)
            return false;
    }
    return true;
}

/* Brute-force
    limit: maxPages - minPages
    TC: O(n) + O(limit * n) => O(n * limit)
    SC: O(1)
*/

int brute_min_pages(vector<int> &arr, int k)
{
    if (k > arr.size())
        return -1;

    int minPages = *max_element(arr.begin(), arr.end());
    int maxPages = sum(arr);
    int result = maxPages;

    for (int pageLimit = minPages; pageLimit <= maxPages; pageLimit++)
    {
        if (canAllocatePages(arr, k, pageLimit))
        {
            result = pageLimit;
            break;
        }
    }
    return result;
}

/* Optimized
    limit: high - low
    TC: O(n) + O(log limit * n) => O(n * log limit)
    SC: O(1)
*/

int optimized_min_pages(vector<int> &arr, int k)
{
    if (k > arr.size())
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = sum(arr);
    int result = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canAllocatePages(arr, k, mid))
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
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    print_arr(arr);
    cout << endl
         << "Total students(k): " << k;
    cout << endl
         << "Brute: " << brute_min_pages(arr, k);
    cout << endl
         << "Optimized: " << optimized_min_pages(arr, k);
}