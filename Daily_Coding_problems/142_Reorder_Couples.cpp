/*
This problem was asked by Spotify.

There are N couples sitting in a row of length 2 * N. They are currently ordered randomly,
but would like to rearrange themselves so that each couple's partners can sit side by side.

What is the minimum number of swaps necessary for this to happen?
*/

// #include<bits/stdc++.h>
// using namespace std;

// string solve(string a,string b)
// {
//     string ans="";
//     unordered_map<char,int>mp;
//     for(auto it:b)
//     {
//         mp[it]++;
//     }
//     int n=a.length();
//     for(int i=0;i<n;i++)
//     {
//         if(mp.find(a[i])==mp.end())
//         {
//             ans.push_back(a[i]);
//         }
//     }
//     return ans;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     string a,b;
//     cin>>a>>b;
//     string ans=solve(a,b);
//     cout<<ans<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int recurDFS(vector<vector<int>> &grid, int i, int j, int n, int m)
{
    if (i >= n || i < 0 || j < 0 || j >= m || grid[i][j] == 0)
    {
        return 0;
    }
    grid[i][j] = 0;

    int a = recurDFS(grid, i + 1, j, n, m);
    int b = recurDFS(grid, i - 1, j, n, m);
    int c = recurDFS(grid, i, j + 1, n, m);
    int d = recurDFS(grid, i, j - 1, n, m);
    return 1 + a + b + c + d;
}

int solve(vector<vector<int>>&res,int n,int m)
{
    vector<int>points;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(res[i][j]==1)
            {
                int temp=recurDFS(res,i,j,n,m);
                points.push_back(temp);
            }
        }
    }
    sort(points.rbegin(),points.rend());
    int ct=0;
    for(int i=1;i<points.size();i+=2)
    {
        ct+=points[i];
    }
    return ct;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        for(int j=0;j<m;j++)
        {
            res[i][j]=str[j]-'0';
        }
    }
    int ans = solve(res, n, m);
    cout << ans << endl;
    return 0;
}