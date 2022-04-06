#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int  long long 
using namespace std;
#define endl '\n'
const int mod=1e9+7;
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back


void solve()
{
    string str;
    int x;
    cin>>str;
    cin>>x;
    string w="";
    int n=str.length();
    w.resize(str.length());
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='1')
        {
            if(i-x>=0)
            {
                if(!visited[i-x])
                {
                    w[i-x]='1';
                    visited[i-x]=true;
                }
                if(visited[i-x] && str[i-x]=='1')
                {
                    w[i]='1';
                    visited[i]=true;
                }
            }
            else if(i+x<n)
            {
                if(!visited[i+x])
                {
                    w[i+x]='1';
                    visited[i+x]=true;
                }
            }
        }
        else if(str[i]=='0')
        {
            
            if(i-x>=0)
            {
                w[i-x]='0';
                visited[i-x]=true;
            }
            if(i+x<n)
            {
                w[i+x]='0';
                visited[i+x]=true;
            }
            w[i]='1';
            visited[i]=true;
        }
    }
    string ans="";
    ans.resize(n);
    for(int i=0;i<n;i++)
    {
        if(i-x>=0 or i+x<n)
        {
            if(i-x>=0)
            {
                if(w[i-x]=='1')
                {
                    ans[i]='1';
                }
            }
            if(i+x<n)
            {
                if(w[i+x]=='1')
                {
                    ans[i]='1';
                }
            }
            else
            {
                ans[i]='0';
            }
        }
    }
    cout<<ans<<endl;
    cout<<str<<endl;
    if(ans==str)
    {
        cout<<w<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }


}



signed main()
{
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
    fast();
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    // solve();
    
    return 0;
}