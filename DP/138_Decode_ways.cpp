#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define int long long
#define endl '\n'
#define fo(i, n) for (int i = 0; i < n; ++i)

int solve(const string& str,int i)
{
    // we iterate all the string
    if(i==str.size()) return 1;
    int ans=0;

    // condition for single way decode
    if(str[i]!='0')
    {
        ans+=solve(str,i+1);
    }
    // condition for 2 chracter 
    // means we will split it in 2 ways 
    // i.e two digits
    if(i+1<str.size() && (str[i]=='1' || str[i]=='2' && str[i+1]<='6'))
    {
        ans+=solve(str,i+2);
    }
    return ans;
}
// Time Complexity:exponential
// Space Complexity :O(1)


int memo[100];
int dp(const string& str,int i)
{
    // we iterate all the string
    if(i==str.size()) return 1;
    int ans=0;

    if(memo[i]!=0)
    {
        return memo[i];
    }
    // condition for single way decode
    if(str[i]!='0')
    {
        ans+=dp(str,i+1);
    }
    // condition for 2 chracter 
    // means we will split it in 2 ways 
    // i.e two digits
    if(i+1<str.size() && (str[i]=='1' || str[i]=='2' && str[i+1]<='6'))
    {
        ans+=dp(str,i+2);
    }
    return memo[i]=ans;
}
// Time Complexity :O(n)
// Space Complexity :O(n)



int bottom_up(const string& str)
{
    int n=str.size();
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        // Single digit
        if(str[i]!='0')
        {
            dp[i]+=dp[i+1];
        }
        if(i+1<n && (str[i]=='1' || str[i]=='2' && str[i+1]<='6')) // two digits
        {
            dp[i]+=dp[i+2];
        }
    }
    return dp[0];
}
// Time Complexity :O(n)
// Space Complexity :O(n)





int Space_Optimize(string str)
{
    // empty string or leading zeros means no ways to decode it
    if(str.empty() || str.front()=='0') return 0;

    int n=str.size();

    // here r1 and r2 keep track on the last and last of last ways
    int r1=1,r2=1;
    for(int i=1;i<n;i++)
    {
        // if 0 hit, then it voids the ways of last because last can't use seperately
        // so we need to mark the last as 0
        if(str[i]=='0')
        {
            r1=0;
        }


         // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
        if(str[i-1]=='1' || str[i-1]=='2' && str[i]<='6')
        {
            r1+=r2;
            r2=r1-r2;
        }

        // one-digit letter, no new way added
        else
        {
            r2=r1;
        }
    }
    return r1;
}
// Time Complexity :O(n)
// Space Complexity :O(1)



int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    IOS;
    string str;
    cin>>str;
    memset(memo,0,sizeof(memo));
    cout<<solve(str,0)<<endl;
    cout<<dp(str,0)<<endl;
    cout<<bottom_up(str)<<endl;
    cout<<Space_Optimize(str)<<endl;

    return 0;
}
