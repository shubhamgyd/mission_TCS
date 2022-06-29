/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

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

    // Brute Force
    // find the lest max and right max
    // take min no both and reduce the hight of current cell

    int mx = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int left = res[i];
        for (int j = 0; j < i; j++)
        {
            left = max(left, res[j]);
        }

        int right = res[i];
        for (int j = i + 1; j < n; j++)
        {
            right = max(right, res[j]);
        }

        int ans = min(left, right) - res[i];
        mx += ans;
    }
    cout << mx << endl;
    // T:O(n*n)
    // S:O(1)

    // Using Prefix and Suffix
    vector<int> height = res;
    int left[n];
    left[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }

    int right[n];
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }

    int water[n];
    for (int i = 0; i < n; i++)
    {
        water[i] = min(left[i], right[i]) - height[i];
    }

    int trapped_water = 0;
    for (int i = 0; i < n; i++)
    {
        trapped_water += water[i];
    }
    cout<<trapped_water<<endl;
    // T:O(3*n)
    // S:O(n+n)


    // Space Optimize
    int left_min=0;
        int right_min=0;
        int l=0;
        int r=n-1;
        int water1=0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>left_min)
                {
                    left_min=height[l];
                }
                else
                {
                    water1+=(left_min-height[l]);
                }
                l++;
            }
            else
            {
                if(height[r]>=right_min)
                {
                    right_min=height[r];
                }
                else
                {
                    water1+=right_min-height[r];
                }
                r--;
            }
        }
        cout<<water1<<endl;
        // T:O(n)
        // S:O(1)
        return 0;
}