/*
Consider N walls, each of unit width, situated next to each other. You have to select any two walls i and j (1 ≤ i,j≤N) such that if you break all the walls except i and j and fill the spaces between them with water, then the amount of water stored is maximum

Write a program to find the maximum amount of water that can be

accumulated between the walls

Input format

• First line: 7 denoting the number of test cases

For each test case

o First line: N

Second line: N space-separated integers denoting the

heights of the walls

Output format

For each test case, print the maximum amount of water that can be

stored between the walls.

Constraints

1≤T≤ 100

1 ≤ N ≤ 104

1 ≤ Value ≤ 10°
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int i = 0;
        int j = n - 1;
        int water = 0;
        while (i < j)
        {
            int h = min(nums[i], nums[j]);
            water = max(water, h * (j - i - 1));
            while (nums[i] <= h and i < j)
            {
                i++;
            }
            while (nums[j] <= h and j > i)
            {
                j--;
            }
        }
        cout << water << endl;
    }
    return 0;
}