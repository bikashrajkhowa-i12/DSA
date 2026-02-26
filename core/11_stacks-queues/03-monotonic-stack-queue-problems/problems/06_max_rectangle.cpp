/*
Given a m x n binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Examples
Input: matrix = [
    [1,0,1,0,0],
    [1,0,1,1,1],
    [1,1,1,1,1],
    [1,0,0,1,0]
    ]
*/
/*
for(0 to n-1)
histogram = fn() => current heights (including prev) => returns an array
maxArea(histogram []) => max(max_area, maxArea)
    {
        PLE & NLE
    }
return maxArea;

*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*  - core intuition: At index i, whose NLE did I just discover? Calculate the area for its previous
    - We calculate area whenever the current height is smaller than the height at stack top: arr[stack.top()] > arr[i]
    - Because the bar at stack.top() just found its Next Smaller Element on the right → which is i.
    - So its rectangle cannot extend further right, meaning we now know its full width → we can compute its area.
*/
int calculate_area(vector<int> &arr)
{
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= arr.size(); i++)
    {
        int currHeight = i == arr.size() ? 0 : arr[i];

        while (!st.empty() && arr[st.top()] > currHeight)
        {
            int height = arr[st.top()];
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1; // i - top - 1 means nle[i] - ple[i] - 1
            maxArea = max(height * width, maxArea);
        }
        st.push(i);
    }
    return maxArea;
}

int max_area(vector<vector<int>> &mat, int n, int m)
{
    int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            if (mat[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }
        int area = calculate_area(height);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};
    cout << "Given matrix: \n";
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Maximum rectangle area: " << max_area(mat, mat.size(), mat[0].size());
}