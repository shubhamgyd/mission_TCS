#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, map<pair<int, int>, bool> &visited,vector<vector<int>>&res)
{
    int n=res[0].size();
    int m=res.size();
    if (i >= 0 && j >= 0 && i < n && j < m && res[i][j]!=1 && (visited.find({i, j}) == visited.end()))
    {
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }
    queue<vector<int>> Q;
    Q.push({0, 0, 0});
    map<pair<int, int>, bool> visited;
    visited[{0, 0}] = true;
    while (!Q.empty())
    {
        auto curr = Q.front();
        Q.pop();
        int i = curr[0], j = curr[1], dist = curr[2];
        if (i == n - 1 and j == m - 1)
        {
            cout << dist + 1 << endl;
            return 0;
        }
        if(isSafe(i,j-1,visited,res))
        {
            visited[{i,j-1}]=true;
            Q.push({i,j-1,dist+1});
        }
        if(isSafe(i,j+1,visited,res))
        {
            visited[{i,j+1}]=true;
            Q.push({i,j+1,dist+1});
        }
        if(isSafe(i-1,j,visited,res))
        {
            visited[{i-1,j}]=true;
            Q.push({i-1,j,dist+1});
        }
        if(isSafe(i+1,j,visited,res))
        {
            visited[{i+1,j}]=true;
            Q.push({i+1,j,dist+1});
        }
    }
    cout<<-1<<endl;
    return 0;
}