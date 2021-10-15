/*
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int known[n]={0};                 // Celebrity known to ths person
        int unknown[n]={0};               // Unknown persons to celebrity
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    known[i]+=1;          // If celebrity know this person
                    unknown[j]+=1;        // If celebrity don't known this person
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            // Condition
            if(unknown[i]==n-1 && known[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};