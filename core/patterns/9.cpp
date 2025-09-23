/*
Problem: Display the following pattern:>
		*
	  * * *
	* * * * *
	* * * * *
	  * * *
		*
*/

/*
Approach >>
 > Count the no of rows (n)
 > Count the spaces and the stars
 > Add a logic to fix it. There will definitely atleast one logic for sure!
*/

#include <iostream>
using namespace std;

int main()
{
	int num, n;

	cout << "Enter the number for rows: ";
	cin >> num;

	n = num / 2;

	// first triangle
	for (int i = 0; i < n; i++)
	{

		// spaces
		for (int j = 0; j < n - i - 1; j++)
		{
			cout << " ";
		}

		// stars
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "*";
		}

		// spaces
		for (int j = 0; j < n - i - 1; j++)
		{
			cout << " ";
		}
		cout << endl;
	}

	// second triangle
	for (int i = 0; i < n; i++)
	{

		// spaces
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		// stars
		for (int j = 0; j < ((n - i) * 2 - 1); j++)
		{
			cout << "*";
		}

		// spaces
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
}
