/*
Given an array of n elements, print the largest element in the array.
Eg: 29,55,44,34,33,15,50
o/p: 55
*/
#include <bits/stdc++.h>
using namespace std;

int largest_element(int arr[], int n)
{
  int largest = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > largest)
      largest = arr[i];
  }
  return largest;
}

int main()
{
  int n;
  cout << "Enter size of array: ";
  cin >> n;

  int arr[n];
  cout << "Enter " << n << " array elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "The largest element is: " << largest_element(arr, n);
}
