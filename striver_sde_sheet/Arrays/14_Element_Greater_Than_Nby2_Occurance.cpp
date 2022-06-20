/*
Problem Statement: Given an array of N integers, write a program to return an element
that occurs more than N/2 times in the given array. You may consider that such an element
always exists in the array.

Example 1:

Input Format: N = 3, nums[] = {3,2,3}

Result: 3

Explanation: When we just count the occurrences of each number and compare with half
of the size of the array, you will get 3 for the above solution.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }

    // bute force
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (res[i] == res[j])
                count++;
        }
        if (count > n / 2)
        {
            cout << res[i] << endl;
        }
    }
    // Time Complexity:O(n*n)
    // Space Complexity:O(1)

    // using frequency count
    map<int, int> mp;
    for (auto it : res)
    {
        mp[it]++;
    }
    for (auto it : mp)
    {
        if (it.second > n / 2)
        {
            cout << it.first << " ";
        }
        cout << endl;
    }
    // Time Complexity:O(nlon)
    // Space Complexity:O(n)

    // using frequency sort
    // Time C:O(n)
    // Space C:O(n)

    // using Boyer-Moore Voting Algorithm
    int counter = 0, majority;
    for (int num : res)
    {
        if (!counter)
        {
            majority = num;
        }
        counter += num == majority ? 1 : -1;
    }
    cout<<majority<<endl;
    // T:O(n)
    // S: O(1)
}