/*
Sum of first N number using recursion

Problem statement: Given a number ‘N’, find out the sum of the first N natural numbers.

Examples:

Example 1:
Input: N=5
Output: 15
Explanation: 1+2+3+4+5=15
*/

#include<iostream>
using namespace std;

void sumOfN(int i, int n, int &sum) {
	if (i > n) return;
	sum = sum + i;
	sumOfN(i+1, n, sum);
}

int main() {
	int n, sum = 0;
	
	cout << "Enter a number: ";
	cin >> n;
	
	sumOfN(1, n, sum);
	cout << "The sum of first " << n << " natural numbers is: " << sum;
}
