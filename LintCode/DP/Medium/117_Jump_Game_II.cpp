/*
Description
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

The array A contains 𝑛 integers 𝑎1, 𝑎2, …, 𝑎𝑛 (1 \leq a_i \leq 20000)(1≤a 
i
​
 ≤20000) (1\leq n \leq20000)(1≤n≤20000)

Example
Example 1:

Input:

A = [2,3,1,1,4]
Output:

2
Explanation:

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*/


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    /**
     * @param a: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &a) { 
 
        // Solution 1: :O(n)
        // int n=a.size();
        // if(a[0]==0 and n>1) return -1;
        // if(n<=1) return 0;
        
        // pair<int,int>interval={0,0};
        // int jump=0;
        // while(1)
        // {
        //     jump++;
        //     int can_reach=-1;
        //     for(int i=interval.first;i<=interval.second;i++)
        //     {
        //         can_reach=max(can_reach,i+a[i]);
        //     }
        //     if(can_reach>=n-1) return jump;
        //     interval={interval.second+1,can_reach};
        //     if(interval.first>interval.second) return -1;
        // }
        // return -1;

        // Solutuon 2: O(n)

        int n=a.size();
        if(n == 0){
        return 0;
    }
        int mxReachPos=a[0];
        int currReach=a[0];
        int steps=1;
        for(int i=1;i<=min(n,mxReachPos);i++)
        {
            currReach=max(currReach,i+a[i]);
            if(i==n-1)
            {
                return steps;
            }
            if(i==mxReachPos)
            {
                steps++;
                mxReachPos=currReach;
            }
        }
        return 0;
    }
};