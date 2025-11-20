/*
Print Fibonacci Series up to Nth term

Problem Statement: Given an integer N. Print the Fibonacci series up to the Nth term.

Example:
Input: N = 5
Output: 0 1 1 2 3 5
Explanation: 0 1 1 2 3 5 is the fibonacci series up to 5th term.(0 based indexing)
*/

#include<bits/stdc++.h>
using namespace std;

int fibonacci(int N){
   
   // Base Condition.
   if(N <= 1)
   {
       return N;
   }

   // Problem broken down into 2 functional calls
   // and their results combined and returned.
   int last = fibonacci(N-1);
   int slast = fibonacci(N-2);
   
   return last + slast;

}

int main(){
  int n;
  
  cout<< "Enter the no of terms: ";
  cin >> n;
  
  cout<<fibonacci(n)<<endl;
  return 0;

}
