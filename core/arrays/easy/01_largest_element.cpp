/*
Given an array of n elements, print the largest element in the array.
Eg: 29,55,44,34,33,15,50
o/p: 55
*/
#include <bits/stdc++.h>
using namespace std;

int largest_element(int arr[], int n)
{
  int max_index = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > arr[max_index])
      max_index = i + 1;
  }
  return arr[max_index];
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
