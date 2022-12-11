/*
In under to try maximum security, the developers at Amazon employ multiple encryption methods to keep user data protected.

in one method, numbers are encrypted using a scheme called 'Pascal Triangle'. When an array of digits is fed to this systern, it sums the adjacent digits. It then takes the rightmost digit (least significant digit) of each addition for the next step. Thus, the number of digits in each step is reduced by 1. This procedure is repeated until there are only 2 digits left, and this sequence of 2 digits forms the encrypted number.

Given the initial sequence of the digits of numbers, find the encrypted number. You should report a string of digits representing the encrypted number.

Example

numbers = [4, 5, 6, 7]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    while (arr.size() > 2)
    {
        vector<int> temp;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            temp.push_back((arr[i] + arr[i + 1]) % 10);
        }
        arr = temp;
    }
    for (auto it : arr)
    {
        cout << it;
    }
    return 0;
}