/*
    A boy have N chocklate and a girls have M candies , we have to pair them i.e each boys must pair 
    with gils ( no pf girls are more than boys so we can reject girls)

    we have to return the  absolute sum of minimum difference of chocklate and candies of  pairs boys and girls
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000
#define int long long 


int dp[1001][1001];
int CountPairs(int arr1[],int arr2[],int n,int m,int i,int j)
{
    // We have paired all the boys
    if(i==n)
    {
        return 0;
    }

    // Either we reject lots of girls or we have paired all the girls
    if(j==m)
    {
        return MAX;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    // we paired one one boy to another girl and recurively count other pairs
    int ans1=abs(arr1[i]-arr2[j])+CountPairs(arr1,arr2,n,m,i+1,j+1);


    // We don't pair boy with any other girl
    int ans2=CountPairs(arr1,arr2,n,m,i,j+1);

    return dp[i][j]=min(ans1,ans2);
}

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)


int32_t main()
{
    memset(dp,-1,sizeof(dp));
    int n,m;
    cin>>n>>m;
    int boys[n];
    int girls[m];
    for(int i=0;i<n;i++)
    {
        cin>>boys[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>girls[i];
    }
    sort(boys,boys+n);
    sort(girls,girls+m);
    cout<<CountPairs(boys,girls,n,m,0,0);
    return 0;
}