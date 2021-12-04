#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long



// Recursive approach
int MaxProfit(vector<int>&res,int n,int x,int flag,int k)
{
    // Base case
    // Either we reached to the end of array or we have reached to our buying limit
    if(x==n || k==0)
    {
        return 0;
    }

    // Wehave two choices
    // 1] Either we byu it with the minimum price
    // 2] we sold it with the maximum price
    return max(MaxProfit(res,n,x+1,-1*flag,k+1)+flag*res[x],MaxProfit(res,n,x+1,flag,k));
}
// Time Complexity :Exponential







// Memoization  Top Down
int dp[1001][1001];
int MX(vector<int>&res,int n,int x,int flag,int k)
{
    // Base case
    // Either we reached to the end of array or we have reached to our buying limit
    if(x==n || k==0)
    {
        return 0;
    }

    // if we have already travers this recursive tree
    if(dp[x][k]!=-1)
    {
        return dp[x][k];
    }


    // Wehave two choices
    // 1] Either we byu it with the minimum price
    // 2] we sold it with the maximum price
    return dp[x][k]=max(MaxProfit(res,n,x+1,-1*flag,k+1)+flag*res[x],MaxProfit(res,n,x+1,flag,k));
}
// Time Complexity :O(n*n)
// Space Complexity :O(n*n)














// DP : Bottom UP
int maxProfit(vector<int>&res,int n)
{
    // We want to byu it with minimum value
    int first_buy=INT_MIN;
    int first_sell=0;
    int second_buy=INT_MIN;
    int second_sell=0;

    for(int i=0;i<n;i++)
    {
        first_buy=min(first_buy,-res[i]);
        first_sell=max(first_sell,first_buy+res[i]);
        second_buy=min(second_buy,first_sell-res[i]);
        second_sell=max(second_sell,res[i]+second_buy);
    }
    return second_sell;
}
// Time Complexity :O(n)
// Space Complexity :O(1)







// If we have infinite number of buying and selling stocks then we just apply
// peak valley method to find the max-profit
int Profit(vector<int>&res,int n)
{
    int profit=0;
    for(int i=1;i<n;i++)
    {
        int sub=res[i]-res[i-1];
        if(sub>0)
        {
            profit+=sub;
        }
    }
    return profit;
}
// Time complexity :O(n)
// Space Complexity :O()

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    int n,k;
    cin>>n>>k;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }

    int flag=0;
    for(int i=0;i<n-1;i++)
    {
        if(res[i]<res[i+1])
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<int>pre(n);
    vector<pair<int,int>>next(n);
    pre[0]=res[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=min(pre[i-1],res[i]);
    }

    next[n-1].first=res[n-1];
    next[n-1].second=res[n-1];

    for(int i=n-2;i>0;i--)
    {
         next[i].first=min(next[i+1].first,res[i]);
        next[i].second=max(next[i+1].second,res[i]);
    }

    int val=0;
    for(int i=0;i<n;i++)
    {
        int back=res[i]-pre[i];
        int forw=next[i].second-next[i].first;
        val=max(val,back+forw);
    }
    cout<<val<<endl;

    // here 2*k means every step 
    // E.g k=2 means max two times we buy it
    // so according to our condition k becomes 4 like two times buy and 2 time cell
    // Flag=-1 means we first time byu the stock at minimum price
    cout<<MaxProfit(res,n,0,-1,2*k);
	return 0;
}
// Time Complexity :O(n)
// Space Complexity :O(n)