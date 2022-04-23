#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int  long long 
using namespace std;
#define endl '\n'
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back
#define next continue
const int mod=1e9+7;

 
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
int gcd(int a,int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}
 
string to_upper(string &a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string &a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}


int miJump(int i,int n,vector<int>&res,int arr[],vector<int>&dp)
{
    if(i>=n-1)
    {
        return 0;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int a=miJump(i+1,n,res,arr,dp);
    int b=miJump(i+2,n,res,arr,dp);
    int c=INT_MAX;
    if(res[i]%2==0)
    {
        int ind=arr[0];
        if(ind>i)
        {
            c=miJump(ind,n,res,arr,dp);
        }
    }
    else
    {
        int ind=arr[1];
        if(ind>i)
        {
            c=miJump(ind,n,res,arr,dp);
        }
    }
    return dp[i]=1+min({a,b,c});
}

void dfs(int i,int d,vector<int>adj[],vector<bool>&visited,int &mx)
{
    if(visited[i]) return;
    visited[i]=true;
    mx=max(mx,d);
    for(auto it:adj[i])
    {
        dfs(it,d+1,adj,visited,mx);
    }
}


int TillNotW(string &str,int i,int &red,int &blue)
{
    int nxt=i;
    int n=str.length();
    while(nxt<n and str[nxt]!='W')
    {
        if(str[nxt]=='R') red++;
        else if(str[nxt]=='B') blue++;
        nxt++;
    }
    return nxt;
}


void Disp(int n)
{
    if(n==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

void solve() {
    int n;
    cin>>n;
    string str;
    cin>>str;
    bool ok=true;
    if(n==1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        string s1="BR";
        string s2="RB";
        int i=0;
        while(i<n)
        {
            if(str[i]=='W') {
                i++;
            }
            else
            {
                int red=0;
                int blue=0;
                int nxt=TillNotW(str,i,red,blue);
                if(red==0 or blue==0){
                    ok=false;
                }
                cout<<"nxt: "<<nxt<<endl;
                i=nxt;
            }
        }

        if(!ok) Disp(0);
        else Disp(1);
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