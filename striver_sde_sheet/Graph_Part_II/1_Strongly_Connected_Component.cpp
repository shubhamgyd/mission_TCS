/*
Problem Statement: Given a Directed Graph with V vertices 
(Numbered from 0 to V-1) and E edges, Find the number of strongly connected 
components in the graph.
(Tarjan’s Algorithm)
*/
#include<bits/stdc++.h>
using namespace std;

void topo(int src,vector<int>graph[],vector<int>&visited,stack<int>&st)
{
    visited[src]=1;
    for(auto it:graph[src])
    {
        if(!visited[it])
        {
            topo(it,graph,visited,st);
        }
    }
    st.push(src);
}
void dfs(int src,vector<int>&visited,vector<int>transpose[])
{
    if(visited[src]==1) return;
    visited[src]=1;
    cout<<src<<" ";
    for(auto ele=transpose[src].begin();ele!=transpose[src].end();++ele)
    {
        if(!visited[*ele])
        {
            dfs(*ele,visited,transpose);
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    vector<int>graph[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    

    // Step 1 & 2:  Sort all edges according to their finishing time and apply Topological Sort
    stack<int>st;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++)
    {   
        if(visited[i]==0)
        {
            topo(i,graph,visited,st);
        }
    }

    // Step 3: Transpose the graph
    vector<int>transpose[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        for(auto it:graph[i])
        {
            transpose[it].push_back(i);
        }  
    }


    //Step 4: Do dfs on transpose graph i.e. dfs on original graph by reverse manner
    while(!st.empty())
    {
        int curr=st.top();
        st.pop();
        if(!visited[curr])
        {
            cout<<"SSC: ";
            dfs(curr,visited,transpose);
            cout<<endl;
        }
    }
    return 0;
}


/*
Time Complexity: O(N+E), DFS+TopoSort

Space Complexity: O(N+E), Transposing the graph
*/