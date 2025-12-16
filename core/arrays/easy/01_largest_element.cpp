/*
Given an array of n elements, print the largest element in the array.
Eg: 29,55,44,34,33,15,50
o/p: 55
*/
#include <bits/stdc++.h>
using namespace std;

int largest_element(int arr[], int n)
{
  for (int i = n - 1; i >= 0; i--)
  {
    bool swapped = false;
    for (int j = 0; j < i; j++)
    {
      if (arr[j + 1] < arr[j])
      {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }

  return arr[n - 1];
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
