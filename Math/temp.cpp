#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
using namespace std;
#define endl '\n'
#define max_pq priority_queue<int>
#define min_pq priority_queue<int, vector<int>, greater<int>>
#define For(i, x, n) for (i = x; i < n; ++i)
#define pb push_back

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

string to_upper(string &a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}

string to_lower(string &a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}

const int mod = 1e9 + 7;
const int INF = 1e9;




bool dfs(int i,int j,int n,int m,vector<vector<bool>>&dp,vector<vector<char>>&res,vector<vector<bool>>&visited)
{
    if(i<0 or i>=n or j<0 or j>=m or res[i][j]=='B' or res[i][j]=='#' or visited[i][j]) return false;

    visited[i][j]=true;
    if(i==n-1 and j==m-1)
    {
        return dp[i][j]=true;
    }
    if(dp[i][j])
    {
        return dp[i][j];
    }
    bool l=dfs(i,j-1,n,m,dp,res,visited);
    bool r=dfs(i,j+1,n,m,dp,res,visited);
    bool u=dfs(i-1,j,n,m,dp,res,visited);
    bool d=dfs(i+1,j,n,m,dp,res,visited);
    return dp[i][j]=(l or r or u or d);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> res(n, vector<char>(m, '.'));
    int bad1 = 0;
    int good1 = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cin >> res[i][j];
            if (res[i][j] == 'B')
                bad1++;
            else if (res[i][j] == 'G')
                good1++;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (res[n - 1][m - 1] == 'B')
    {
        cout << "No" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (res[i][j] == 'B')
            {
                // cout<<"here"<<endl;
                if (i - 1 >= 0 and res[i - 1][j] == 'G')
                {
                    cout << "No" << endl;
                    return;
                }
                else
                {
                    if ( i-1>=0 and res[i - 1][j] == '.')
                    {
                        res[i - 1][j] = '#';
                    }
                }

                if (i + 1 < n and res[i + 1][j] == 'G')
                {
                    cout << "No" << endl;
                    return;
                }
                else
                {
                    if (i+1<n and res[i + 1][j] == '.')
                    {
                        res[i + 1][j] = '#';
                    }
                }

                if (j - 1 >= 0 and res[i][j - 1] == 'G')
                {
                    cout << "No" << endl;
                    return;
                }
                else
                {
                    if (j-1>=0 and res[i][j - 1] == '.')
                    {
                        res[i][j-  1] = '#';
                    }
                }

                if (j + 1 < m and res[i][j + 1] == 'G')
                {
                    cout << "No" << endl;
                    return;
                }
                else
                {
                    if (j+1<m and res[i][j + 1] == '.')
                    {
                        res[i][j + 1] = '#';
                    }
                }
            }
        }
    }

    queue<pair<int,int>>q;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            // cout<<res[i][j]<<" ";
            if(res[i][j]=='G')
            {
                q.push({i,j});
            }
        }
        // cout<<endl;
    }
    
    bool ok=true;
    vector<vector<bool>>dp(n,vector<bool>(m,false));
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        int i=p.first;
        int j=p.second;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        if(!dfs(i,j,n,m,dp,res,visited))
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

signed main()
{
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();

    return 0;
}