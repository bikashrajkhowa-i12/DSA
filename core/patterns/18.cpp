/*
Problem: Display the following pattern:
E
D E			
C D E
B C D E
A B C D E
*/

#include<iostream>
using namespace std;

// If it is for 'n' rows, follow this >>
int main() {
	int n;
	
	cout << "Enter the number of rows: ";
	cin >> n;

	char ch = 'A' + n-1;			

	for(int i=0;i<n; i++) {			
		for(int j=0; j<=i; j++) {
			cout << ch << " ";					
			ch++;						
		}
		cout << endl;
		ch = ch - i - 2;		
	}
}


// If it is for exact pattern go for this >>
//int main() {
//	int n;
//	
//	cout << "Enter the no of rows: ";
//	cin >> n;
//	
//	for (int i=0;i<n; i++) {
//		for (char ch = 'E' - i; ch <= 'E'; ch++) {
//			cout << ch << " ";
//		}
//		cout << endl;
//	}
//}
