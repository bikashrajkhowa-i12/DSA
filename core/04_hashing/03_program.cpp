//Using map/unordered maps to display!!!!

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	
	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	//map for sorted keys. unordered for fast-access unsorted keys
	
	map<int, int> mp;
	//unordered_map<int, int> mp;
	for(int i=0; i<n; i++) {
		mp[arr[i]] +=  1;
	}

	//iterate a map/unordered_map
	for(auto it : mp) {
		cout << it.first << "->" << it.second << endl;
	}
	
	int number;
	cout << "Enter the number to be searched: ";
	cin >> number;
	
	cout << "Frequency of " << number << " is: " << mp[number] << endl;
}
