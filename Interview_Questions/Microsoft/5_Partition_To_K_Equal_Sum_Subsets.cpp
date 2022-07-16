/*
Given an integer array nums and an integer k, return true if it is possible to 
divide this array into k non-empty subsets whose sums are all equal.
*/

#include<bits/stdc++.h>
using namespace std;

bool solve(int i,int n,int curr_sum,int k,int target,vector<int>&nums,vector<bool>&visited)
{
    if(k==0)
    {
        return true;
    }
    if(curr_sum==target)
    {
        return true;
    }
    for(int j=i;j<n;j++)
    {
        if(!visited[j] and curr_sum+nums[j]<=target)
        {
            visited[j]=true;
            if(solve(j+1,n,curr_sum+nums[j],k,target,nums,visited))
            {
                return true;
            }
            visited[j]=false;
        }
    }
    return false;
}


int main()
{
    int  n;
    cin>>n;
    vector<int>nums(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        sum+=nums[i];
    }
    int k;
    cin>>k;
    int target=sum/k;
    if(sum%k>0)
    {
        cout<<"False"<<endl;
        return 0;
    }
    vector<bool>visited(n,false);
    bool ans=solve(0,n,0,k,target,nums,visited);
    cout<<ans<<endl;
    return 0;
}