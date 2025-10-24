/*
Problem Statement: Given an integer N, return the number of digits in N.
*/

#include<iostream>
using namespace std;

int main() {
	int n, counter = 0;
	
	cout << "Enter any integer: ";
	cin >> n;
	
	cout << "The number of digits present in the " << n << " is: ";
	
	while(n > 0) {
		n = n / 10;
		counter++;
	}

	cout << counter;
	return 0;
}
