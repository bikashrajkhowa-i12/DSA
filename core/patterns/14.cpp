/*
Problem: Display the following pattern:
A
AB
ABC
ABCD
ABCDE
*/

// in chars it increments when we add 1 to it

#include<iostream>
using namespace std;

int main() {
	int rows;
	
	cout << "Enter no of rows: ";
	cin >> rows;

	for (int i=0; i<rows; i++) {
		for (char c='A'; c <= 'A'+i; c++) {
			cout << c;
		}
		cout << endl;
	}
	
	return 0;
}
