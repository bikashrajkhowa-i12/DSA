/*
Given an array nums of n integers, find the most frequent element
in it i.e., the element that occurs the maximum number of times.
If there are multiple elements that appear a maximum number of times,
find the smallest of them.

Eg1 :
Input: nums = [1, 2, 2, 3, 3, 3]
Output: 3

Eg2:
Input: nums = [4, 4, 5, 5, 6]
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter array size: ";
	cin >> n;

	int arr[n];					// input elements
	unordered_map<int, int> mp; // store (key, frequency) in unordered_map

	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		mp[arr[i]] += 1;
	}

	// frequent element counter
	int maxCount = 0;
	int res = 0;

	// loop over the map
	for (auto &it : mp)
	{
		cout << it.first << " -> " << it.second << endl;

		int num = it.first;
		int freq = it.second;

		// update frequent element
		if (freq > maxCount || (freq == maxCount && num < res))
		{
			maxCount = freq;
			res = num;
		}
	}

	cout << "The most frequent element is: " << res << endl;
	return 0;
}
