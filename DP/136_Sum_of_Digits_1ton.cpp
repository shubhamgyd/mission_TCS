#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    int sum=0;
    int i;
    for(i=0;i<=9;i++)
    {
        dp[i]=i;
        if(i>n)
        {
            break;
        }
        sum+=dp[i];
    }
    while(i<=n)
    {
        dp[i]=dp[i%10]+dp[i/10];
        sum+=dp[i];
        i++;
    }
    cout<<sum<<endl;
    return 0;
}
// Time Complexity :O(n)
// Space Coplexity :O(n)