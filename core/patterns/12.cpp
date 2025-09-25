/*
Problem: Display the following pattern:
1      1
12    21
123  321
12344321

*/


#include<iostream>
using namespace std;

int main() {
	int n;
	
	cout << "Enter the no of rows: ";
	cin >> n;

	int space = 2* (n-1);

	
	for(int i=1; i<=n; i++) {     //outer loop
		for (int j=1; j<=i; j++) {
			cout << j;
		}
		
		for (int j=1; j<=space; j++) {
			cout << " ";
		}
		
		for (int j=i; j>=1; j--) {
			cout << j;
		}
		cout << endl;
		space -= 2;
	}
}
