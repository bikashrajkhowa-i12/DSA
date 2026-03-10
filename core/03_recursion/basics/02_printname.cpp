/*
Print name N times using recursion
*/

#include<iostream>
#include<string>
using namespace std;

void printName(string name, int n, int count) {
	if(count > n) return; //base case
	cout << name << endl;
	printName(name, n, count+1); //recursive call
}

int main() {
	string name;
	int n;
	
	cout << "Enter your name: ";
	cin >> name;
	
	cout << "Enter the no of times to be printed: ";
	cin >> n;
	
	cout << "*******Start*******" << endl;
	printName(name, n, 1);
	
	cout << "*******End*******";
}
