/*
Print 1 to N using recursion
*/

#include<iostream>
using namespace std;

void printN(int i, int n) {
	if(i > n) return;
	cout << i << endl;
	printN(i+1, n);
}

int main() {
	int n;
	
	cout << "Enter the limit: ";
	cin >> n;
	
	printN(1, n);
}
