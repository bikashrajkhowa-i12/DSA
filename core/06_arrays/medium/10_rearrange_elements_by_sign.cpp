/*
There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
Without altering the relative order of positive and negative elements, you must return
an array of alternately positive and negative values.

Example :
Input:
arr[] = {1,2,-4,-5}, N = 4
Output:
1 -4 2 -5
Explanation:
Positive elements = 1,2
Negative elements = -4,-5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
TC: O(n) + O(n/2) = O(n)
SC: O(n/2) + O(n/2) + O(n) => O(2n) => O(n)
*/
vector<int> brute_rearrange_by_sign(vector<int> &nums)
{
    vector<int> positives, negatives;

    for (int x : nums)
    {
        if (x > 0)
            positives.push_back(x);
        else
            negatives.push_back(x);
    }

    vector<int> res(nums.size());
    bool startPos = (nums[0] > 0);

    for (int i = 0; i < nums.size() / 2; i++)
    {
        if (startPos)
        {
            res[2 * i] = positives[i];
            res[2 * i + 1] = negatives[i];
        }
        else
        {
            res[2 * i] = negatives[i];
            res[2 * i + 1] = positives[i];
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 2, -4, -5};
    cout << "Given array: [";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            cout << nums[i] << "]";
        else
            cout << nums[i] << ", ";
    }

    cout << endl
         << "Rearraged elements by sign (brute): [";
    vector<int> res = brute_rearrange_by_sign(nums);

    for (int i = 0; i < res.size(); i++)
    {
        if (i == res.size() - 1)
            cout << res[i] << "]";
        else
            cout << res[i] << ", ";
    }
}