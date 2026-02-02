/*
Problem Statement: Given an integer N, check whether it is prime or not. A prime number is a number that is only 
divisible by 1 and itself and the total number of divisors is 2.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, count=0;
	cout << "Enter a number: ";
	cin >> n;
	
	for(int i=1; i*i<=n; i++) {
		if(n%i == 0) {
			count += 1;
			if(n/i != i) {
				count += 1;
			}
		}
	}
	
	if(count == 2) {
		cout << "Prime number.";
	} else {
		cout << "Not a prime number.";
	}
	
}


