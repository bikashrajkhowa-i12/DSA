/*
Given an array of integers heights representing the histogram's bar height where the width
of each bar is 1 return the area of the largest rectangle in histogram. .

Example:

Input: N =6, heights[] = {2,1,5,6,2,3}
Output: 10
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> PLE(vector<int> &arr)
{
    stack<int> st;
    vector<int> res(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        res[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return res;
}

vector<int> NLE(vector<int> &arr)
{
    stack<int> st;
    vector<int> res(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        res[i] = !st.empty() ? st.top() : arr.size();
        st.push(i);
    }
    return res;
}

int area_of_rectangle(vector<int> &arr)
{
    int max_area = 0;
    vector<int> ple = PLE(arr);
    vector<int> nle = NLE(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        int width = (nle[i] - ple[i]) - 1;
        max_area = max(arr[i] * width, max_area);
    }
    return max_area;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Given heights: [";
    for (int i = 0; i < heights.size(); i++)
    {
        if (i == heights.size() - 1)
            cout << heights[i] << "]";
        else
            cout << heights[i] << ", ";
    }

    cout << endl
         << "Area of the largest rectangle: " << area_of_rectangle(heights);
}