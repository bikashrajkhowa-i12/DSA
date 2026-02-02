/*
Problem Statement: Given an integer N return the reverse of the given number.
*/


#include<iostream>
using namespace std;

int main() {
	int n, rev = 0;
	
	cout << "Enter a number: ";
	cin >> n;
	
	while (n > 0) {
		rev = (rev*10) + (n % 10); //append the last digit in the reverse number
		n = n/10; // for scanning each digit from end
	}
	
	cout << "The reversed number is: " << rev;
	
	return 0;
}
