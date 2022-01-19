/*
his question is asked by Google. Given an array of integers, return whether or not 
two numbers sum to a given target, k.
Note: you may not sum a number with itself.

Ex: Given the following...

[1, 3, 8, 2], k = 10, return true (8 + 2)
[3, 9, 13, 7], k = 8, return false
[4, 2, 6, 5, 2], k = 4, return true (2 + 2)

*/

#include<bits/stdc++.h>
using namespace std;

bool FindSum(vector<int>&res,int target,int n)
{
    for(int i=0;i<n;i++)
    {
        int num=res[i];
        for(int j=i+1;j<n;j++)
        {
            if(res[j]+num==target)
            {
                return true;
            }
        }
    }
    return false;
}
// Time Complexity:O(n*n)
// Space Complexity:O(1)



bool solve(vector<int>&res,int target,int n)
{
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[res[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        int num=target-res[i];
        if(mp.find(num)!=mp.end())
        {
            return true;
        }
        mp[res[i]]++;
    }
    return false;
}
// Time Complexity:O(n)
// Space Complexity;

int main()
{
    int n,target;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    cin>>target;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[res[i]]++;
    }
    if(solve(res,target,n))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}