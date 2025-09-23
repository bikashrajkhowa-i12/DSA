/**
Problem: Display the following >>
			*
		  * * *
		* * * * *
	  * * * * * * *
	* * * * * * * * *
*/

#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter the no of rows: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{ // no of rows

		for (int j = 0; j < n - i - 1; j++)
		{ // spaces
			cout << " ";
		}

		for (int j = 0; j < 2 * i + 1; j++)
		{ // stars
			cout << "*";
		}

		for (int j = 0; j < n - i - 1; j++)
		{ // spaces
			cout << " ";
		}
		cout << endl;
	}
}
