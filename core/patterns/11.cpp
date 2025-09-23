/*
Problem: Display the following pattern: >>
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/

// approach> pick odd even logic

#include <iostream>
using namespace std;

int main()
{
	int n, value;

	cout << "Enter rows: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			value = 1;
		else
			value = 0;

		for (int j = 0; j <= i; j++)
		{
			cout << value;
			value = 1 - value;
		}
		cout << endl;
	}
}
