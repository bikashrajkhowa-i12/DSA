/**
Problem: Display the following pattern >
	1
	22
	333
	4444
	55555
*/

#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter the size: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << i + 1 << " ";
		}
		cout << endl;
	}
}
