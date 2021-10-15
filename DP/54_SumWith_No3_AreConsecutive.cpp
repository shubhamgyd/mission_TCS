// In this program we are going to find maxumum sum , with no 3 elements are consecutive

#include<bits/stdc++.h>
using namespace std;

int ANS(int a[],int n)
{
    // int M[n];
    // int i;
    // M[0]=a[0];
    // M[1]=max(M[0],max(a[1],a[0]+a[1]));
    // M[2]=max(M[1],max(a[2],max(a[0]+a[2],a[1]+a[2])));
    
    // for(i=2;i<n;i++)
    // {
    //     M[i]=max(a[i]+M[i-2],max(a[i]+a[i-1]+M[i-3],M[i-1]));
    // }
    int dp[n];
    int j;
    dp[0]=a[0];
    dp[1]=max(dp[0],max(a[1],a[0]+a[1]));
    dp[2]=max(dp[1],max(a[2],max(a[0]+a[2],a[1]+a[2])));
    for(j=2;j<n;j++)
    {
        dp[j]=max(dp[j-2]+a[j],max(dp[j-1],a[j]+a[j-1]+dp[j-3]));
    }
    //cout<<dp[n-1]<<endl;
    return dp[n-1];
    //return M[n-1];
    
}

int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];
    
    int ans;
    ans=ANS(a,n);
    
    cout<<ans<<endl;
    
    }
    return 0;
}