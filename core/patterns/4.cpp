/**
Problem: Display the following >
	1
	1 2
	1 2 3
	1 2 3 4
	1 2 3 4 5
*/

#include <iostream>
using namespace std;

int main()
{
	int n, i, j;

	cout << "Enter the size: ";
	cin >> n;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			cout << j + 1 << " ";
		}
		cout << endl;
	}
}
