/*
Problem Statement: Given an integer N, return true if it is a palindrome else return false.
*/

#include<iostream>
using namespace std;

int main() {
	int n, original, rev;
	
	cout << "Enter a number: ";
	cin >> n;
	
	original = n;
	
	while(n > 0) {
		rev = (10*rev) + (n%10);
		n=n/10;
	}
	
	if(original == rev) {
		cout << "The entered number is a palindrome.";
	} else {
		cout << "The entered number is not a palindrome.";
	}
}
