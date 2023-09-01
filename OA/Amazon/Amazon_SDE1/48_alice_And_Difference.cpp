/*
Alice is given an array arr of length N. Alice wants to pick a subset S of size 3 from the array arr such that the value of

3 abs(median of S -mean of S) is minmized.

Task

Print the minimum value of the above expression that Alice can get.

Example

Assumptions

• N=5

arr = [1, 4, 5, 8, 9]

2

ENG
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
}