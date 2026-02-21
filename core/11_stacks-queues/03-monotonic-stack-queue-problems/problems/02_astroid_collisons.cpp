/*
 Given an array of integers asteroids, where each integer represents an asteroid in a row,
 determine the state of the asteroids after all collisions. In this array, the absolute value
 represents the size of the asteroid, and the sign represents its direction (positive meaning
 right and negative meaning left). All asteroids move at the same speed.

When two asteroids meet, the smaller one will explode. If they are the same size, both will explode.
Asteroids moving in the same direction will never meet.

Examples
Example 1:
Input:
 asteroids = [2, -2]
Output:
 []
Explanation:
 The asteroid with size 2 and the one with size -2 collide, exploding each other.

Example 2:
Input:
 asteroids = [10, 20, -10]
Output:
 [10, 20]
Explanation:
 The asteroid with size 20 and the one with size -10 collide, resulting in the remaining asteroid with size 20.
 The asteroids with sizes 10 and 20 never collide.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* APPROACH*************

TC: O(n+n); SC: O(n)
 */
vector<int> astroid_collison(vector<int> &arr)
{
    vector<int> res;

    for (int i = 0; i < arr.size(); i++)
    {
        // if arr[i] is +ve
        if (arr[i] > 0)
            res.push_back(arr[i]);
        else
        {
            // if arr[i] is -ve
            while (!res.empty() && res.back() > 0 && res.back() < abs(arr[i]))
            {
                res.pop_back(); // pop smaller ones
            }
            if (!res.empty() && res.back() == abs(arr[i]))
            {
                res.pop_back();
            }
            else if (res.empty() || res.back() < 0)
            {
                res.push_back(arr[i]);
            }
        }
    }
    return res;
}

int main()
{
    vector<int> asteroids = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    cout << "Asteroids: [";
    for (int i = 0; i < asteroids.size(); i++)
    {
        if (i == asteroids.size() - 1)
            cout << asteroids[i] << "]";
        else
            cout << asteroids[i] << ", ";
    }

    vector<int> resultant = astroid_collison(asteroids);
    cout << endl
         << "Final state after collison: [";
    for (int i = 0; i < resultant.size(); i++)
    {
        if (i == resultant.size() - 1)
            cout << resultant[i] << "]";
        else
            cout << resultant[i] << ", ";
    }
}