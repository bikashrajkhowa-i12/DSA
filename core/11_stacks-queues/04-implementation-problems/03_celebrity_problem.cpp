/*
A celebrity is a person who is known by everyone else at the party
but does not know anyone in return. Given a square matrix M of size
N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise,
determine if there is a celebrity at the party. Return the index of
the celebrity or -1 if no such person exists.

Note that M[i][i] is always 0.

Example 1:
Input:
 M = [ [0, 1, 1, 0],
       [0, 0, 0, 0],
       [1, 1, 0, 0],
       [0, 1, 1, 0]
    ]
Output: 1
Explanation:
 Person 1 does not know anyone and is known by persons 0, 2, and 3.
 Therefore, person 1 is the celebrity.

Example 2:
Input:
 M = [ [0, 1],
       [1, 0]
     ]
Output: -1
Explanation:
 Both persons know each other, so there is no celebrity.
*/
#include <iostream>
#include <vector>
using namespace std;

void print_matrix(vector<vector<int>> &M)
{
    int n = M.size();

    cout << "[\n";
    for (int i = 0; i < n; i++)
    {
        cout << "[";
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
                cout << M[i][j] << "]";
            else
                cout << M[i][j] << ", ";
        }
        if (i == n - 1)
            cout << "]";
        else
            cout << ",\n";
    }
    return;
}

/* brute-force
    TC: O(n*n) + O(n) => O(n*n)
    SC: O(n + n) => O(2n)
*/
int brute_celebrity(vector<vector<int>> &M)
{
    int n = M.size();
    if (n == 0)
        return -1;

    vector<int> knowsMe(n, 0);
    vector<int> iKnow(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 1)
            {
                knowsMe[j]++;
                iKnow[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (knowsMe[i] == n - 1 && iKnow[i] == 0)
            return i;
    }

    return -1;
}

int main()
{
    vector<vector<int>> M = {{0, 1, 1, 0},
                             {0, 0, 0, 0},
                             {1, 1, 0, 0},
                             {0, 1, 1, 0}};

    cout
        << "Given matrix: ";
    print_matrix(M);
    cout << endl
         << "Celebrity: " << brute_celebrity(M);
    return 0;
}