
#include<bits/stdc++.h>
using namespace std;

void solve(int src,int dest,vector<vector<int>>&graph,vector<vector<int>>&paths,vector<int>&path)
{
    path.push_back(src);
    if(src==dest) paths.push_back(path);
    else
        for(auto it:graph[src])
        {
            solve(it,dest,graph,paths,path);
        }
    path.pop_back();
}


vector<vector<int>> GetPaths(vector<vector<int>>&graph,int src,int dest)
{
    vector<vector<int>>paths;
    vector<int>path;
    solve(src,dest,graph,paths,path);
    cout<<paths.size()<<endl;
    return paths;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<"-->";
    //     for(auto it:graph[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    int src,dest;
    cin>>src>>dest;
    vector<vector<int>>res=GetPaths(graph,src,dest);
    for(auto it:res)
    {
        for(auto ele:it)
        {
            cout<<ele<<"->";
        }
        cout<<endl;
    }

    return 0;
}