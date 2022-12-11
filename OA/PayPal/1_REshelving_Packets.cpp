/*
Reshelving Packets -
Range of shelves from 1 to 99 inclusive
Given list of integers, reshelve them to the minimum value possible and return the array in the same order though.

Example 1 - Input : [1, 12, 4, 12] - List of shelves
Output - [1, 3, 2, 3]

Explanation - Strarting shelf is 1, so that remains same, next lowest available value is 2, which can be assigned to 4 and the next available shelf is 3 that can be assigned to 12.

Example 2 - Input : [1, 2, 6, 5]
Ouput : [1, 2, 4, 3]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp[i] = arr[i];
    }
    sort(arr, arr + n);
    int num = 1;
    vector<int> output(n);
    unordered_map<int, int> mp;
    int i = 0;
    while (i < n)
    {
        int j = i;
        mp[arr[i]] = num;
        while (j < n and arr[i] == arr[j])
        {
            j++;
        }
        i = j;
        num++;
    }
    for (int i = 0; i < n; i++)
    {
        output[i] = mp[temp[i]];
    }
    for (auto it : output)
    {
        cout << it << " ";
    }
    return 0;
}