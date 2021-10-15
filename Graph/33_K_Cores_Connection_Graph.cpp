
#include<bits/stdc++.h>
using namespace std;


bool DFS(int src,vector<int>graph[],vector<bool>&visited,vector<int>&res,int k)
{
    // Mark the node visited
    visited[src]=true;
    for(auto it:graph[src])
    {
        // if degree of parent is less than k 
        // then reduce the degree of child by one
        // coz we are not considering parent in k-cores
        if(res[src]<k)
        {
            res[it]--;
        }

        if(!visited[it])
        {
            DFS(it,graph,visited,res,k);
        }
    }
    // Return degree of node is greater than k or not
    return (res[src]<k);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif

    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    vector<int>graph[n];

    // Undirected graph
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    int start=0;
    int degree=INT_MAX;
    vector<int>res(n);
    vector<bool>visited(n,false);

    // TO keep eye on the node whose degree is minimum
    // and store the degree of each node in array
    for(int i=0;i<n;i++)
    {
        res[i]=graph[i].size();
        if(res[i]<degree)
        {
            start=i;
            degree=res[i];
        }
    }

    // Start dfs from that node whose degree is smaller
    DFS(start,graph,visited,res,k);


    // After the applying the DFS check 
    // any node is not visited , again apply dfs on this node
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            DFS(i,graph,visited,res,k);
        }
    }


    // Process  to the nodes whose degree greater than k

    for(int i=0;i<n;i++)
    {
        // Consider only those nodes whose degree is greater than k
        if(res[i]>=k)
        {
            cout<<"["<<i<<"]-->";
            for(auto it:graph[i])
            {
                // Consider only those childs whose degree is greater than k
                if(res[it]>=k)
                {
                    cout<<it<<" ";
                }
            }
            cout<<endl;
        }
    }

    return 0;
}

/*
Time complexity of the above solution is O(V + E) where V is number of vertices 
and E is number of edges.
*/