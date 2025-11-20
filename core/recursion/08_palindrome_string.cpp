/*
Check if a string is palindrome or not.

Problem Statement: "Given a string, check if the string is palindrome or not."  
	A string is said to be palindrome if the reverse of the string is the same as the string.

Example:
Input: Str =  “ABCDCBA”
Output: Palindrome
Explanation: String when reversed is the same as string.
*/

#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(int i, string str, int n) {
	if(i >= n/2) return true;
	if(str[i] != str[n-i-1]) return false; // if it doesn't match with the end index, its not a palindrome;
	return checkPalindrome(i+1, str, n);
}

int main() {
	string str;
	
	cout << "Enter a string: ";
	cin >> str;
	
	cout << "Is palidrome ? : ";
	if(checkPalindrome(0, str, str.length())){
		cout << "True";	
	} else {
		cout << "False";
	}
}
