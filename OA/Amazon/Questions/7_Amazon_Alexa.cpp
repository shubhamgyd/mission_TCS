/*
Alexa is Amazon's virtual Al assistant. It makes it easy to set up your Alexa enabled devices, listen to music, get weather updates, and much more. The team is working on a new feature that evaluates the aggregate temperature change for a period based on the changes in temperature of previous and upcoming days.

Taking the change in temperature data of n days, the aggregate temperature change evaluated on the day is the maximum of the sum of the changes in temperatures until the ith day, and the sum of the change in temperatures in the next (n-1) days, with the ith day temperature change included in both.

Given the temperature data of n days, find the maximum aggregate

temperature change evaluated among all the days.

Example

tempChange [6,-2,5]

The aggregate temperature change on each day is evaluated as:
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
    int pref[n];
    int suff[n];
    pref[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + arr[i];
    }
    suff[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + arr[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max({mx, pref[i], suff[i]});
    }
    cout << mx << endl;
    return 0;
}