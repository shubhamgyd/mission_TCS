/*
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers 
sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is 
less than 150 combinations for the given input.
*/


#include<bits/stdc++.h>
using namespace std;


void combination(int i,vector<int>&res,vector<vector<int>>&ans,vector<int>&ds,int k)
{
    if(i==res.size())
    {
        if(k==0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if(res[i]<=k)
    {
        ds.push_back(res[i]);
        combination(i,res,ans,ds,k-res[i]);
        ds.pop_back();
    }
    combination(i+1,res,ans,ds,k);
}

vector<vector<int>> solve(vector<int>&res,int k)
{
    vector<vector<int>>ans;
    vector<int>ds;
    // int sum=0;
    combination(0,res,ans,ds,k);
    return ans;
}
// Time Complexity:O(2^target*k)
// Space Complexity:O(vriable size)

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int k;
    cin>>k;
    vector<vector<int>>ans=solve(res,k);
    for(auto it:ans)
    {
        for(auto ele:it)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}