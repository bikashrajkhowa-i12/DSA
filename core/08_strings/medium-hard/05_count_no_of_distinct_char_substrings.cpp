/*
Count Number of Substrings:
You are given a string s and a positive integer k.
Return the number of substrings that contain exactly k distinct characters.

Example 1:
Input:
 s = "pqpqs", k = 2
Output:
 7
Explanation:
  All substrings with exactly 2 distinct characters:
"pq", "pqp", "pqpq", "qp", "qpq", "pqs", "qs"
Total = 7.

Example 2:
Input:
 s = "abcbaa", k = 3
Output:
 5
Explanation:
  All substrings with exactly 3 distinct characters:
"abc", "abcb", "abcba", "bcba", "cbaa"
Total = 5.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Brute force
    Idea-intuition: Generate every substring and check how many distinct characters it has.
    TC: O(n*n)
    SC: O(n)
*/
int countSubstringsExactlyK(string s, int k)
{
    int n = s.size();
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> freq;
        int distinct = 0;

        for (int j = i; j < n; j++)
        {
            if (freq[s[j]] == 0)
                distinct++;

            freq[s[j]]++;

            if (distinct == k)
                total++;

            if (distinct > k)
                break;
        }
    }

    return total;
}

long long atMostK(const string &s, int k)
{
    if (k < 0)
        return 0;

    vector<int> freq(256, 0);
    int left = 0, distinct = 0;
    long long count = 0;

    for (int right = 0; right < s.size(); right++)
    {
        if (freq[s[right]] == 0)
            distinct++;

        freq[s[right]]++;

        while (distinct > k)
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                distinct--;
            left++;
        }

        count += (right - left + 1);
    }

    return count;
}

/* Optimal
    - Idea-Intuition:
        - Exactly(k) = AtMost(k) - AtMost(k-1)
        - Use sliding window to count substrings with at most k distinct by adding (right - left + 1) for each right.
    - TC: O(n)
    - SC: O(n)
*/
int optimal_countSubstringsExactlyK(string s, int k)
{
    return atMostK(s, k) - atMostK(s, k - 1);
}

int main()
{
    string s = "pqpqs";
    int k = 2;
    cout << "Given string: " << s;
    cout << endl
         << "Total count(brute): "
         << countSubstringsExactlyK(s, k);
    cout << endl
         << "Total count(optimal): "
         << optimal_countSubstringsExactlyK(s, k);
}