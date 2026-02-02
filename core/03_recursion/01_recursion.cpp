/*
Recursion: 
*/

#include<iostream>
using namespace std;
int count = 1;

void printCount(int n) {
	if(count > n) return; // base condition to stop the recursive call.
	cout << count << endl;
	count++;
	printCount(n);
}

int main() {
	int limit;
	
	cout << "Enter limit: ";
	cin >> limit;
	
	printCount(limit); //recursive call
	cout << "Count ended!";
}
