/*
Consider a 2-D map with a horizontal river passing through its center.
 There are n cities on the southern bank with x-coordinates a(1) … a(n) and n 
 cities on the northern bank with x-coordinates b(1) … b(n). You want to connect 
 as many north-south pairs of cities as possible with bridges such that no two bridges cross. 
 When connecting cities, you can only connect city a(i) on the northern bank to city b(i) on 
 the southern bank. Maximum number of bridges that can be built to connect north-south pairs
  with the aforementioned constraints.
*/

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
    return a.second<b.second;
}

int Solve(vector<pair<int,int>>&res,int n)
{
    sort(res.begin(),res.end(),cmp);
    int ct=0;
    int dp[n]={0};
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        // dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(res[i].first>res[j].first && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,dp[i]);
    }
    return mx;
}
// Time Complexity:O(n*n)
// Space Complexity :O(n)












// Optimise DP of LIS
//O(nLogn Approach)
int Ways(vector<pair<int,int>>res,int n)
{
    sort(res.begin(),res.end());
    vector<int>dp(n+1,INT_MAX);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int idx=lower_bound(dp.begin(),dp.end(),res[i].second)-dp.begin();
        dp[idx]=res[i].second;
        ans=max(ans,idx+1);
    }
    return ans;
}
// Time Complexity :O(nlogn)
// Space Complexity :O(n)







int main()
{
    vector<pair<int,int>>res;
    for(int i=0;i<4;i++)
    {
        int a,b;
        cin>>a>>b;
        res.push_back({a,b});
    }
    int n=res.size();
    cout<<Solve(res,n)<<endl;
    cout<<Ways(res,n)<<endl;
    return 0;
}