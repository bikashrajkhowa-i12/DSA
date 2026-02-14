/*
Given an array of non-negative integers representation elevation of ground.
Your task is to find the water that can be trapped after rain.

Examples:

Input : height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output : 6
Explanation : Water is trapped in the dips between bars. The total trapped water units add up to 6 (1+1+2+1+1).

Input : height = [4,2,0,3,2,5]
Output : 9
Explanation : The elevation map traps 9 units of water in total, as water fills the spaces between higher bars on both sides.
*/
#include <iostream>
#include <vector>

using namespace std;

// optimal; TC: O(n); SC: O(1)
int find_total(vector<int> &arr)
{
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] < leftMax)
                total += leftMax - arr[left];
            else
                leftMax = arr[left];
            left++;
        }
        else
        {
            if (arr[right] < rightMax)
                total += rightMax - arr[right];
            else
                rightMax = arr[right];
            right--;
        }
    }
    return total;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Height: [";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr.size() - 1)
            cout << arr[i] << "]";
        else
            cout << arr[i] << ", ";
    }

    cout << endl
         << "Total: " << find_total(arr);
}