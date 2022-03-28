/*
his problem was asked by Airbnb.

We're given a hashmap associating each courseId key with a list of courseIds values, 
which represents that the prerequisites of courseId are courseIds. Return a sorted ordering 
of courses such that we can finish all courses.

Return null if there is no such ordering.

For example, given {'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []}, 
should return ['CSC100', 'CSC200', 'CSCS300'].

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    cin>>n>>m;
    // vector<set<int>>adj[n+1];
    set<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[v].insert(u);
    }
    vector<bool>visited(n+1,false);
    queue<int>q;
    vector<int>ans;
    for(int i=1;i<n;i++)
    {
        if(adj[i].size()==0)
        {
            q.push(i);
            visited[i]=true;
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(auto it:adj[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }

    while(!q.empty())
    {
        int u=q.front();
        ans.push_back(u);
        q.pop();
        for(auto it:adj[u])
        {
            q.push(it);
        }
    }

    for(auto it:ans)
    {
        cout<<it<<endl;
    }
    return 0;
}