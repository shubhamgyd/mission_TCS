/*
The Interns at Amazon were asked to review the company's stock value over a period.
Given the stock prices of n months, the net price change for the Ah month is defined
as the absolute difference between the average of stock prices for the first/ months and
for the remaining (n-months where 1si<n. Note that these averages are rounded down to an integer.

Given an array of stock prices, find the month at which the net price change is minimum.
 If there are several such months, return the earliest month.

Note: The average of a set of integers here is defined as the sum of integers divided by
the number of integers, rounded down to the nearest integer. For example, the average of [1,2,3,4)
 is the floor of (1+2+3+4)/4-2.5 and the floor of 2.5 is 2.

Example

stockPrice [1,3,2,3]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int ind = n + 2;
    int change = INT_MAX;
    int pref = 0;
    for (int i = 1; i < n; i++)
    {
        pref += arr[i];
        int left = (pref / i);
        int right = ((sum - pref) / (n - i));
        int res = abs(left - right);
        if (res < change)
        {
            change = res;
            ind = i;
        }
    }
    cout << ind << endl;
    return 0;
}