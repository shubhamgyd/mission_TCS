#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long 
#define mod 1000000007
using namespace std;
#define endl '\n'

void Display(int num)
{
    cout<<num<<endl;
}

void Input(int n,vector<int>&res)
{
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
}

int Steps(int a,int b)
{
    if(b<0)
    {
        return INT_MAX;
    }
    if(a==b)
    {
        return 0;
    }
    return 1+min(Steps(a,b+1),Steps(a,b/2));
}


void solve() 
{

    // int dp[10001];
    // memset(dp,-1,sizeof(dp));
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<0<<endl;
        return;
    }
    if(a>b)
    {
        cout<<abs(b-a)<<endl;
        return;
    }
    int ct=Steps(a,b);
    cout<<ct<<endl;
    // int ct=0;
    // while(a!=b)
    // {
    //     if(b%2==0)
    //     {
    //         b/=2;
    //         ct++;
    //     }
    //     else
    //     {
    //         b+=1;
    //         ct++;
    //     }
    // }
    // cout<<ct<<endl;
}

int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    solve();
    return 0;

}