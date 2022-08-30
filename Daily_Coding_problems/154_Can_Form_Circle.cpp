/*
This problem was asked by Dropbox.

Given a list of words, determine whether the words can be chained to form a circle.
A word X can be placed in front of another word Y in a circle if the last character of X is
same as the first character of Y.

For example, the words ['chair', 'height', 'racket', touch', 'tunic'] can form the following circle:
chair --> racket --> touch --> height --> tunic --> chair
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<int> adj[], vector<bool> &visited)
{
    
    visited[start] = true;
    for (auto it : adj[start])
    {
        if (visited[it] == false)
        {
            dfs(it, adj, visited);
        }
    }
}

bool IsConnected(int s, int V, vector<int> adj[], vector<bool> &mark)
{
    vector<bool> visited(26, false);
    dfs(s, adj, visited);

    for (int i = 0; i < 26; i++)
        if (visited[i] == false && mark[i] == true)
        {
            return false;
        }

    return true;
}

int solve(vector<string> &res, int n)
{
    vector<int> adj[26];
    vector<bool> mark(26, false);
    vector<int>indegree(26,0),outdegree(26,0);
    for (int i = 0; i < n; i++)
    {
        string str = res[i];
        int u = str[0] - 'a';
        int v = str[str.size() - 1] - 'a';
        mark[u] = true;
        mark[v] = true;
        indegree[v]++;
        outdegree[u]++;
        adj[u].push_back(v);
    }
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] != outdegree[i])
        {
            return false;
        }
    }
    return IsConnected(res[0].front() - 'a', 26, adj, mark);
}

int main()
{
    int n;
    cin >> n;
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    // for(auto it:res)
    // {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    bool isCircle = solve(res, n);
    if (isCircle)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}