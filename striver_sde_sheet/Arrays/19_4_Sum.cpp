/*
Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

Pre-req: Binary Search and 2-sum problem

Note:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
arr[a] + arr[b] + arr[c] + arr[d] == target
Example 1:

Input Format: arr[] = [1,0,-1,0,-2,2], target = 0

Result: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Explanation: We have to find unique quadruplets from
the array such that the sum of those elements is
equal to the target sum given that is 0.

The result obtained is such that the sum of the
quadruplets yields 0.
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
    int target;
    cin >> target;

    // Brute Force
    bool ok = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (res[i] + res[j] + res[k] + res[l] == target)
                    {
                        cout << "Found" << endl;
                        ok = true;
                    }
                }
                if (ok)
                    break;
            }
            if (ok)
                break;
        }
        if (ok)
            break;
    }
    if (!ok)
    {
        cout << "Not Found" << endl;
    }
    // T:O(n^4)
    // S:O(1)

    // using three pointer and binary search
    sort(res.begin(), res.end());
    bool ok1 = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int num =target-res[i] + res[j] + res[k];
                if (binary_search(res.begin() + k + 1, res.end(), num))
                {
                    cout << "Found" << endl;
                    ok1 = true;
                    break;
                }
            }
            if (ok1)
                break;
        }
        if (ok1)
            break;
    }
    if (!ok1)
    {
        cout << "Not Found" << endl;
    }
    // Time Complexity: O(N log N + N³ logN)
    // Reason: Sorting the array takes N log N and three nested loops will be taking N³ and for binary search, it takes another log N.
    // Space Complexity: O(1), where M is the number of quads

    // Using Three Pointer only
    vector<int> num = res;
    bool ok2 = false;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {

        int target_3 = target - num[i];

        for (int j = i + 1; j < n; j++)
        {

            int target_2 = target_3 - num[j];

            int front = j + 1;
            int back = n - 1;

            while (front < back)
            {

                int two_sum = num[front] + num[back];

                if (two_sum < target_2)
                    front++;

                else if (two_sum > target_2)
                    back--;

                else
                {

                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = num[i];
                    quadruplet[1] = num[j];
                    quadruplet[2] = num[front];
                    quadruplet[3] = num[back];
                    ans.push_back(quadruplet);

                    // Processing the duplicates of number 3
                    while (front < back && num[front] == quadruplet[2])
                        ++front;

                    // Processing the duplicates of number 4
                    while (front < back && num[back] == quadruplet[3])
                        --back;
                }
            }

            // Processing the duplicates of number 2
            while (j + 1 < n && num[j + 1] == num[j])
                ++j;
        }

        // Processing the duplicates of number 1
        while (i + 1 < n && num[i + 1] == num[i])
            ++i;
    }
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    // T:O(n^3)
    // S:O(n*n)
}