/*
Problem Statement
You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.
Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph.
Example:
Sample input 1
2
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
Sample output 1
0 4 1 2 5
0 5 8 7

*/

#include<bits/stdc++.h>
using namespace std;



vector<int> dijkstra(vector<vector<int>> &vec, int v, int e, int src) {
    // Write your code here.
    vector<pair<int,int>>adj[v];
    for(auto it:vec)
    {
        int u,v,w;
        u=it[0];
        v=it[1];
        w=it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>dist(v,INT_MAX);
    vector<bool>visited(v,false);
    priority_queue<pair<int,int>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        auto u=pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u]=true;
        for(auto it:adj[u])
        {
            int v,w;
            v=it.first;
            w=it.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push({-dist[v],v});
            }
        }
    }
    return dist;
}

// Time Complexity: O((N+E)*logN). Going through N nodes and E edges and log N for priority queue
// Space Complexity: O(N). Distance array and priority queue