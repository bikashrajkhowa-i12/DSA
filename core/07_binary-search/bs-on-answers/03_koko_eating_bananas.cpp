/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours. Koko can decide her bananas-per-hour eating speed of k.
Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas,
she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.


Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int max_pile(vector<int> &arr)
{
    int maxi = 0;
    for (int x : arr)
        maxi = max(maxi, x);

    return maxi;
}

int total_hours_required(vector<int> &piles, int speed)
{
    int totalHours = 0;

    for (int pile : piles)
        totalHours += (pile + speed - 1) / speed;

    return totalHours;
}

/*
    Brute Idea:
        - Try every speed k from 1 → max(pile).
        - For each k compute total hours = Σ ceil(pile / k).
        - Return first k where hours ≤ h.
    Complexity:
        - TC:  O(n) + O(maxPile * n) => O(n * maxPile)
        - SC:  O(1)
*/
int brute_min_speed(vector<int> &arr, int h)
{
    int maxPile = max_pile(arr);

    for (int k = 1; k <= maxPile; k++)
    {
        if (total_hours_required(arr, k) <= h)
            return k;
    }

    return maxPile;
}

int main()
{
    vector<int> piles = {30, 11, 23, 4, 20};
    int h = 6;

    cout << "Given piles: [";
    for (int i = 0; i < piles.size(); i++)
    {
        if (i == piles.size() - 1)
            cout << piles[i] << "]";
        else
            cout << piles[i] << ", ";
    }
    cout << endl
         << "Maximum hours(h): " << h;
    cout << endl
         << "Minimum bananas to eat: ";
    cout << endl
         << "\tBrute: " << brute_min_speed(piles, h);
}