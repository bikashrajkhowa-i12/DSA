/*
Problem: Display the following pattern:
   A   
  ABA
 ABCBA
ABCDCBA
*/

#include<iostream>
using namespace std;

int main() {
	int n;
	
	cout << "Enter no of rows: ";
	cin >> n;
	
	for (int i=0; i<n; i++) {	//outer loop
		
		//spaces
		for (int j=0; j<n-i; j++) {
			cout << " ";
		}
		
		//characters
		char ch = 'A';
		int breakpoint = (2*i+1)/2;
		
		for (int j=0; j<2*i+1; j++) {
			cout << ch;
			if (j<breakpoint) ch++;
			else ch--;
		}
		
		//spaces
		for (int j=0; j<n-i; j++) {
			cout << " ";
		}
		
		cout << endl;
	}
}
