/*
Print N to 1 using recursion
*/

#include<iostream>
using namespace std;

void printNto1(int n) {
	if(n < 1) return;
	cout << n << endl;
	printNto1(n-1);
}

int main() {
	int n;
	
	cout << "Enter the limit: ";
	cin >> n;

	printNto1(n);
}
