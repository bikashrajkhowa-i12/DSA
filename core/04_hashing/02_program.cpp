#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cout << "Enter a string: ";
	cin >> s;
	
	int hash[26] = {0}; //26 aplhabets chars
	
	//assignment and counter 
	for(int i=0; i<s.size(); i++) {
		hash[s[i]-'a'] += 1;
	}
	
	char c;
	cout << "Enter the character to be searched: ";
	cin >> c;
	cout << "Frequency of " << c << " is: " << hash[c-'a'] << endl;
}
