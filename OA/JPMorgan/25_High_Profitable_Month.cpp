/*
The stocks of a company are being surveyed to analyze the net profit of the company over a
period.

For an analysis parameter k, an interval of k consecutive months is said to be highly
profitable if the values of the stock prices are strictly increasing for those months.
Given the stock prices of the company for n months and the analysis parameter k, find
the number of highly profitable intervals.

Example

stockPrices 5, 3,5, 7, 8]

k=3

These are the Intervals of k months in which the stock prices are strictly

increasing
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int suff[n];
    suff[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            suff[i] = suff[i + 1] + 1;
        }
        else
        {
            suff[i] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (suff[i] >= k)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}