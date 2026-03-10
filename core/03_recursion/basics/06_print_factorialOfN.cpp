/*
Factorial of a Number : Iterative and Recursive
Problem Statement: Given a number X,  print its factorial.
To obtain the factorial of a number, it has to be multiplied by all the whole numbers preceding it. More precisely X! = X*(X-1)*(X-2) … 1.
*/

#include<iostream>
using namespace std;

int factorial(int n) {
	if(n == 0) return 1;
	return n * factorial(n-1);
}

int main() {
	int n;
	
	cout << "Enter a number: ";
	cin >> n;
	
	cout << "Factorial of " << n << " is " << factorial(n);
}
