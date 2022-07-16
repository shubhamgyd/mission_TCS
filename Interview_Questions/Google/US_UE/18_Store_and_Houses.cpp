/*
You are given 2 arrays representing integer locations of stores and houses (each location in this problem is one-dementional). For each house, find the store closest to it.
Return an integer array result where result[i] should denote the location of the store closest to the i-th house. If many stores are equidistant from a particular house, choose the store with the smallest numerical location. Note that there may be multiple stores and houses at the same location.

Example 1:

Input: houses = [5, 10, 17], stores = [1, 5, 20, 11, 16]
Output: [5, 11, 16]
Explanation:
The closest store to the house at location 5 is the store at the same location.
The closest store to the house at location 10 is the store at the location 11.
The closest store to the house at location 17 is the store at the location 16.
Example 2:

Input: houses = [2, 4, 2], stores = [5, 1, 2, 3]
Output: [2, 3, 2]
Example 3:

Input: houses = [4, 8, 1, 1], stores = [5, 3, 1, 2, 6]
Output: [3, 6, 1, 1]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> houses(n);
    for (int i = 0; i < n; i++)
    {
        cin >> houses[i];
    }
    int m;
    cin >> m;
    vector<int> stores(m);
    for (int i = 0; i < m; i++)
    {
        cin >> stores[i];
    }
    sort(begin(stores), end(stores));
    vector<int> result;
    vector<int> result;
    for (int house : houses)
    {
        int index = lower_bound(stores.begin(), stores.end(), house) - stores.begin();
        if (index == 0)
            result.emplace_back(stores[index]);
        else if (index == stores.size())
            result.emplace_back(stores[index - 1]);
        else
        {
            int distanceLeft = house - stores[index - 1];
            int distanceRight = stores[index] - house;
            if (distanceLeft == distanceRight || distanceLeft < distanceRight)
                result.emplace_back(stores[index - 1]);
            else
                result.emplace_back(stores[index]);
        }
    }
    for(auto it:result)
    {
        cout<<it<<" ";
    }
    // T:O(nlogn)
    // S:O(n)
    return 0;
}