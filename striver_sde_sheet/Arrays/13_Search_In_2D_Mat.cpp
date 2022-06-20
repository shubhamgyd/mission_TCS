/*
Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

Given matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row
Example 1:

Input: matrix =
[[1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]],

target = 3

Output: true

Explanation: As the given integer(target) exists in the given 2D matrix, the function has returned true.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> res[i][j];
        }
    }
    int target;
    cin >> target;

    // Brute Force
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (res[i][j] == target)
            {
                cout << "Fond" << endl;
                ok = true;
            }
        }
    }
    if (!ok)
    {
        cout << "Not Found" << endl;
    }
    // T:O(N*m)
    // S:O(1)

    // Binary Search
    int l = 0, r = m * n - 1;
    while (l != r)
    {
        int mid = (l + r - 1) >> 1;
        if (res[mid / m][mid % m] < target)
            l = mid + 1;
        else
            r = mid;
    }
    if (res[r / m][r % m] == target)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    // Time complexity: O(log(m*n))

    // Space complexity: O(1)
}