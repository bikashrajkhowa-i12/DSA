/*
Given two binary numbers, swap them without using a third variable
Eg: a = 4 (0110), b = 7 (0111)
output: a = 7, b = 4
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 4;
    int b = 7;

    cout << "Before swapping: ";
    cout << endl
         << "a: " << a;
    cout << ",\tb: " << b;

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    cout << endl
         << "After swapping(bits): ";
    cout << endl
         << "a: " << a;
    cout << ",\tb: " << b;
}