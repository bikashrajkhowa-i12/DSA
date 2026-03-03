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
    // bool startPos = (nums[0] > 0); since the start is always a positive integer

    for (int i = 0; i < nums.size() / 2; i++)
    {
        // if (startPos)
        // {
        res[2 * i] = positives[i];
        res[2 * i + 1] = negatives[i];
        // }
        // else
        // {
        //     res[2 * i] = negatives[i];
        //     res[2 * i + 1] = positives[i];
        // }
    }

    return res;
}

/*
Optimal approach:
- Skip the separation step entirely.
- place elements directly into their correct index in one pass
- using two pointers to track the next position of the current sign index.

TC: O(n); SC: O(n)
-   Both approaches are O(n) time and O(n) space, but the optimal solution runs in a single pass
    with no intermediate vectors so the constant factor is smaller.
-   In practice this means better cache performance and less memory allocation overhead, which matters at scale.
*/
vector<int> optimal_rearrange_elements_by_sign(vector<int> &nums)
{
    vector<int> result(nums.size());

    // if starting sign is +ve
    int posIdx = 0;
    int negIdx = 1;

    // if starting sign is preserved
    // int posIdx = nums[0] > 0 ? 0 : 1;
    // int negIdx = 1 - posIdx;

    for (int x : nums)
    {
        if (x > 0)
        {
            result[posIdx] = x;
            posIdx += 2;
        }
        else
        {
            result[negIdx] = x;
            negIdx += 2;
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {-3, 1, 2, -4, -5, 6};
    cout << "Given array: [";
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            cout << nums[i] << "]";
        else
            cout << nums[i] << ", ";
    }

    cout << endl
         << "Rearraged elements by sign: [";
    // vector<int> res = brute_rearrange_by_sign(nums);
    vector<int> res = optimal_rearrange_elements_by_sign(nums);

    for (int i = 0; i < res.size(); i++)
    {
        if (i == res.size() - 1)
            cout << res[i] << "]";
        else
            cout << res[i] << ", ";
    }
}