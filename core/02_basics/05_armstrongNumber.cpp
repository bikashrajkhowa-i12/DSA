/*
Problem Statement: Given an integer N, return true it is an Armstrong number otherwise return false.

An Amrstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.

Eg: 
	371 = 3^3 + 7^3 + 1^3 = 371 (true)
	555 = 5^3 + 5^3 + 5^3 = 375 (false)
*/

#include<iostream>
using namespace std;

int main() {
	int n, sum=0;

	cout << "Enter a number: ";
	cin >> n;
	
	int dup = n;
	
	while(n > 0) {
		int lastDigit = n%10;
		sum = sum + (lastDigit * lastDigit * lastDigit);
		n = n/10;
	}
	
	if(dup == sum) {
		cout << "true";
	} else {
		cout << "false";
	}
}
