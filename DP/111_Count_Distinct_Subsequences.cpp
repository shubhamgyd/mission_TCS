#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

set<string>st;

void solve(string str,string op)
{
    if(str.length()==0)
    {
        st.insert(op);
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(str[0]);
    str.erase(str.begin()+0);
    solve(str,op1);
    solve(str,op2);
    return;
}
// Time Complexity : Exponential





// Bottom UP: DP
int Count(string str)
{
    int n=str.length();

    map<char,int>mp;
    int dp[n+1];
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        dp[i]=2*dp[i-1];

        char ch=str[i-1];
        if(mp.find(ch)!=mp.end())
        {
            int j=mp[ch];
            dp[i]=dp[i]-dp[j-1];
        }
        mp[ch]=i;
    }
    return dp[n];

}

// Time Complexity :O(n)
// Space Complexity :O(n)

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    string str;
    cin>>str;
    int n=str.length();
    // solve(str,"");
    // for(auto it:st)
    // {
    //     cout<<it<<" ";
    // }
    cout<<Count(str)<<endl;
    return 0;
}


