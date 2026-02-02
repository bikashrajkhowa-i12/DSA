/*
	Find the GCD(HCF) of two numbers.
	Eg: 15, 20
	15: 1,3,5,15
	20: 1,5,10,20
	
	factors: 1, 5
	GCD: 5	
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	int num1, num2;
	
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	
// brute-force
//	for(int i=min(num1, num2); i>=1 ;i--){
//		if(num1%i == 0 && num2%i == 0) {
//			cout << "GCD of " << num1 << " & " << num2 << " is " << i;
//			break;
//		}
//	}

//apply time complexity
// Euclidean algorithm.(search for algorithm breakdown)
	while(num1 > 0 && num2 > 0) {
		if(num1 > num2) num1 = num1 % num2;
		else num2 = num2 % num1;
	}
	cout << "GCD of the two numbers is: ";
	if(num1==0) cout << num2;
	else cout << num1;
}
