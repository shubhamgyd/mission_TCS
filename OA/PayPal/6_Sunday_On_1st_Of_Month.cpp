/*
A leap year is an year in which the month of February has 29 days.
If a year is divisible by 4, it is typically a leap year. However,
if the year is also divisible by 100, it is not a leap year. But when the year is divisible by 400,
 it is a leap year. April, June, September and November have 30 days January, March, May, July,
 August, October and December have 31 days.

1st Jan, 1900 was a Monday.

Write a program to find out how many Sundays

on the first of the month for a given year

wch greater than or equal to 1900.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int year;
    cin >> year;
    int totalSundays = (year - 1900) / 5 + (year - 1900) % 5;
    cout << totalSundays << endl;
}