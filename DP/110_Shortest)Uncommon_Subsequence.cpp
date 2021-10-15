#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define MAX 10005


bool ans=false;
int len=1;
bool Checking(string str,string target)
{
    stack<char>st;

    for(int i=0;i<target.length();i++)
    {
        st.push(target[i]);
    }

    for(int i=str.length()-1;i>=0;i--)
    {
        if(st.empty())
        {
            return false;
            
        }
        if(str[i]==st.top())
        {
            st.pop();
        }
    }

    if(st.empty())
    {
        return false;
    }
    return true;


}


void solve(string str,int n,string tar,int ind=-1,string curr="")
{
    if(n==ind)
    {
        return;
    }

    if(!curr.empty())
    {
        // cout<<curr<<endl;
        if(Checking(tar,curr)==true)
        {
            len=curr.length();
            ans=true;
            return;
        }
    }

    for(int i=ind+1;i<n;i++)
    {
        curr.push_back(str[i]);
        solve(str,n,tar,i,curr);
        curr.pop_back();
    }
    return ;
}
// Time Complexity : Exponential












// Recursive
int shortestSeq(char *S, char *T, int m, int n)
{
    // S string is empty
    if (m == 0)
        return MAX;
 
    // T string is empty
    if (n <= 0)
        return 1;
 
    // Loop to search for current character
    int k;
    for (k=0; k < n; k++)
        if (T[k] == S[0])
            break;
 
    // char not found in T
    if (k == n)
        return 1;
 
    // Return minimum of following two
    // Not including current char in answer
    // Including current char
    return min(shortestSeq(S+1, T, m-1, n),
            1 + shortestSeq(S+1, T+k+1, m-1, n-k-1));
}

// Time Complexity: Exponential














// Bottom UP: DP
int Len(string str,string target,int n,int m)
{
    int dp[n+1][m+1];

    // If target is empty
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }


    // is string is empty
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=INT_MAX;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch=str[i-1];

            int k;
            for(k=j-1;k>=0;k--)
            {
                if(target[k]==ch)
                {
                    break;
                }
            }

            // is char is not present
            if(k==-1)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][k]+1);
            }
        }
    }

    return dp[n][m]==INT_MAX?-1:dp[n][m];
}

// Time Complexity :O((m*n)^2)
// Space Complexity O(n*m)

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    fast();
    string str,tar;
    cin>>str>>tar;
    int n=str.length();
    int m=tar.length();
    // solve(str,n,tar);
    // if(ans)
    // {
    //     cout<<"YES"<<endl;
    //     cout<<"Length of subequence: "<<len<<endl;
    // }
    // else
    // {
    //     cout<<-1<<endl;
    // }

    int ans=Len(str,tar,n,m);
    cout<<ans<<endl;
    return 0;
}


