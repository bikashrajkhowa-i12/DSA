#include <iostream>
#include <vector>
using namespace std;

// TC: O(n); SC: O(n)
vector<int> prefix_sum(const vector<int> &arr)
{
    int n = arr.size();
    int sum = arr[0];
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            res[i] = sum;
        }
        else
        {
            sum += arr[i]; // remove incase of exlcuding self
            res[i] = sum;
            // sum += arr[i]; incase of excluding self
        }
    }
    return res;
}

// TC: O(n); SC: O(n)
vector<int> suffix_sum(const vector<int> &arr)
{
    int n = arr.size();
    int sum = arr[n - 1];
    vector<int> res(n);

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            res[i] = sum;
        }
        else
        {
            sum += arr[i]; // remove incase of exlcuding self
            res[i] = sum;
            // sum += arr[i]; incase of excluding self
        }
    }
    return res;
}

int main()
{
    vector<int> prefix_input = {6, 2, 4, 3};
    vector<int> suffix_input = {1, 3, 6, 2};

    cout << "Given prefix-input: [";
    for (int i = 0; i < prefix_input.size(); i++)
    {
        if (i == prefix_input.size() - 1)
            cout << prefix_input[i] << "]";
        else
            cout << prefix_input[i] << ", ";
    }

    // prefix-sum
    vector<int> res = prefix_sum(prefix_input);
    int m = res.size();
    cout << endl
         << "Prefix sum: [";
    for (int i = 0; i < m; i++)
    {
        if (i == m - 1)
            cout << res[i] << "]";
        else
            cout << res[i] << ", ";
    }

    cout << endl
         << "Given suffix-input: [";
    for (int i = 0; i < suffix_input.size(); i++)
    {
        if (i == suffix_input.size() - 1)
            cout << suffix_input[i] << "]";
        else
            cout << suffix_input[i] << ", ";
    }
    // suffix-sum
    vector<int> res2 = suffix_sum(suffix_input);
    int x = res2.size();
    cout << endl
         << "Suffix sum: [";
    for (int i = 0; i < x; i++)
    {
        if (i == x - 1)
            cout << res2[i] << "]";
        else
            cout << res2[i] << ", ";
    }
}