/*
Problem: Display the pattern:>
	*
	**
	***
	****
	***
	**
	*
*/

#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter mid-size: ";
	cin >> n;

	for (int i = 0; i < 2 * n; i++)
	{
		int stars = i;

		if (i > n)
		{
			stars = 2 * n - i;
		}

		for (int j = 0; j < stars; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}
