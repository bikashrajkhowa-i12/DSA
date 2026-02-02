#include<bits/stdc++.h>
using namespace std;

int main(){ 
	int n; 
	cout << "Enter total elements: ";
	cin >> n;


	//input elements
	int arr[n];	
	cout << "Enter " << n << " elements: " << endl;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	// create the hasharray
	int hash[13] = {0}; //assigning all elements of the hash array to "0"
	
	// hash function for allocating the 
	for(int i=0; i<n; i++) {
		hash[arr[i]] += 1; //increasing the count
	}
	
	int number;
	cout << "Enter the number to be searched: ";
	cin >> number;
	//fetch the number
	cout << "Total appearance of " << number << " is: " << hash[number] << endl;

	
	return 0;
}
