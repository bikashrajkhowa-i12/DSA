/*
Problem: Display the following pattern:
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/

#include<iostream>
using namespace std;

int main() {
	int n;
	
	cout << "Enter the no of rows: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		
		//top-left inverted-triangle
		for(int j=0; j<n-i; j++){ 
			cout << "*";
		}
		
		//spaces for top-mid triangle
		for(int j=0; j<2*i; j++) {
			cout << " ";
		}
		
		//top-right inverted-triangle
		for(int j=0; j<n-i; j++) {
			cout << "*";
		}

		cout << endl;		
	}
	
	int space = 2*n-2;
	
	for (int i = 0; i < n; i++) {
		//bottom-left triangle
		for(int j=0; j <=i; j++) {
			cout << "*";
		}
		
		//spaces for bottom-mid triangle
		for(int j=0; j<space; j++) {
			cout << " ";
		}
		
		//bottom-right triangle
		for(int j=i; j>=0; j--) {
			cout << "*";
		}
		cout << endl;
		space -= 2;
	}
}
