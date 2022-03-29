/*
You are given two lists of integers and an integer representing a process id to kill. 
One of the lists represents a list of process ids and the other represents a list of each of 
the processes’ corresponding (by index) parent ids. When a process is killed, all of its children 
should also be killed. Return a list of all the process ids that are killed as a result of killing 
the requested process.

Ex: Given the following…

pid =  [2, 4, 3, 7]
ppid = [0, 2, 2, 3]
kill = 3
the tree of processes can be represented as follows:
           2
         /   \
        4     3
             /
            7
return [3, 7] as killing process 3 will also require killing its child (i.e. process 7).
*/

#include<bits/stdc++.h>
using namespace std;

void DFS(int node,vector<int>adj[],vector<bool>&visited,vector<int>&ans)
{
    if(visited[node]) return;
    visited[node]=true;
    ans.push_back(node);
    for(auto it:adj[node])
    {
        DFS(it,adj,visited,ans);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>node(n),parent(n);
    for(int i=0;i<n;i++)
    {
        cin>>node[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>parent[i];
    }

    int killId;
    cin>>killId;

    vector<int>adj[100];
    for(int i=0;i<n;i++)
    {
        int u=node[i];
        int v=parent[i];
        adj[v].push_back(u);
    }

    int node1=killId;
    vector<int>ans;
    vector<bool>visited(100,false);
    DFS(node1,adj,visited,ans);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}

// Time complexity:O(V+E)
// Space Complexity :O(V^2)