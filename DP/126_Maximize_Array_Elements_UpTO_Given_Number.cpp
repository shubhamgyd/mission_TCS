
#include <bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define int long long 

void solve(int num,int mx,int &val,vector<int>&res,int curr,int n)
{
    if(curr==n)
    {
        val=max(val,num);
        return;
    }
    
    // case 1:
    // Subtrace current element from the num and check for next elements

    if(num-res[curr]>=0)
    {
        solve(num-res[curr],mx,val,res,curr+1,n);
    }



    // Case 2: Add current element in the num and check for the next element
    if(num+res[curr]<=mx)
    {
        solve(num+res[curr],mx,val,res,curr+1,n);
    }
}
// Recursion 
// Time Cimplexity :Exponential














// Memoization
int dp[1001][1001];
int solve1(int num,int mx,vector<int>&res,int curr,int n)
{
    if(curr==n)
    {
        return num<=mx?num:-1;
    }

    if(dp[curr][num]!=-1)
    {
        return dp[curr][num];
    }

    int ans=-1;
    if(num<res[curr])
    {
        ans=solve1(num+res[curr],mx,res,curr+1,n);
    }
    else if(num+res[curr]>mx)
    {
        ans=solve1(num-res[curr],mx,res,curr+1,n);
    }
    else
    {
        ans=max(solve1(num+res[curr],mx,res,curr+1,n),solve1(num-res[curr],mx,res,curr+1,n));
    }
    dp[curr][num]=ans;
    return ans;
}
// Time Complexity :O(n*n)
// Space Complexity :O(n*n)



// Bottom UP: DP Optimization 
int MAXSUM(vector<int>res,int n,int num,int mx)
{
    
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }
    int num,mx;
    cin>>num>>mx;
    int val=0;
    // res.insert(res.begin()+0,num);
    memset(dp,-1,sizeof dp);
    solve(num,mx,val,res,0,n);
    cout<<val<<endl;
    cout<<solve1(num,mx,res,0,n)<<endl;
	return 0;
}