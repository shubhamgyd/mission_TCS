#include<bits/stdc++.h>
using namespace std;

void minimumPath(int n,int m,vector<vector<int>>&connections)
{
    vector<int>graph[n+1];
    for(auto it:connections)
    {
        int u=it[0];
        int v=it[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int>Q;
    vector<bool>visited(n+1,false);
    int pathLength[n+1];
    visited[1]=true;
    int parent[n+1];
    parent[1]=-1;
    pathLength[1]=0;
    Q.push(1);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(auto it:graph[u])
        {
            if(!visited[it])
            {
                visited[it]=true;
                pathLength[it]=pathLength[u]+1;
                parent[it]=u;
                Q.push(it);

            }
        }
    }
    if(visited[n]==false)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int minPathLength=pathLength[n];
    vector<int>path;
    path.push_back(n);
    int node=n;
    while(node!=1)
    {
        node=parent[node];
        path.push_back(node);
    }
    reverse(path.begin(),path.end());
    cout<<minPathLength+1<<endl;
    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;


}

int main()
{
    int num=pow(2,31)-1;
    int num1=pow(-2,31);
    cout<<num<<endl;
    cout<<num1<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>connections;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        connections.push_back({a,b});
    }
    minimumPath(n,m,connections);
    return 0;
}