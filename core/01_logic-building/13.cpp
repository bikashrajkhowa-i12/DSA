/*
Problem: Display the following pattern:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/

#include<iostream>
using namespace std;

int main(){ 
	int rows, number = 1;
	
	cout << "Enter the number of rows: ";
	cin >> rows;
	
	for (int i=0; i<rows; i++) {
		for(int j=0; j<=i; j++) {
			cout << number << " ";
			number += 1;
		}
		cout << endl;
	}
}
