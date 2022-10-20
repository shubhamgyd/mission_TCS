/*
You are given two integer arrays, A and B. B is an anagram of A meaning that B contains all the same elements of A but in a different order. Return an array that represents a mapping from every element in A to which index it occurs at in B.
Note: You may assume every element in A is unique.

Ex: Given the following A and B…

A = [8, 23, 2], B = [2, 23, 8], return [2, 1, 0] (8 appears at index 2 in B, 23 appears at index 1 in B, and 2 appears at index 0 in B).
Ex: Given the following A and B…

A = [9, 3, 1, 5, 2, 4], B = [2, 5, 1, 3, 4, 9], return [5,3,2,1,0,4].
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        mp[A[i]] = i;
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
        res[i] = mp[B[i]];
    }
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}