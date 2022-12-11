/*
Given input array.
Arr = [4, 8, 5,3,1]

Output all pair of elements satisfying below condition.
(4,1) (8,2) (8,3) (8,1) (5,1) (3,1)

Condition:
(i,j) -> i and j are array indexes, i < j
Arr[i] > 2*Arr[j]
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
}