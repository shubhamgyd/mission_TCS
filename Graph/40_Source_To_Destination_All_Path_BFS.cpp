
#include<bits/stdc++.h>
using namespace std;


// utility function for printing
// the found path in graph
void printPath(vector<int>path)
{
    for(auto it:path)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

void BFS(int src,int dest,vector<int>graph[])
{
    vector<int>path;
    path.push_back(src);
    queue<vector<int>>q;
    q.push(path);
    while(!q.empty())
    {
        path=q.front();
        q.pop();

        int last=path[path.size()-1];

        // if last vertex is the desired destination
        // then print the path
        if(dest==last)
        {
            printPath(path);
        }

        // traverse to all the nodes connected to
        // current vertex and push new path to queue
        for(auto it:graph[last])
        {
            if(find(path.begin(),path.end(),it)==path.end())
            {
                vector<int>newPath(path);
                newPath.push_back(it);
                q.push(newPath);
            }
        }

    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n,m;
   cin>>n>>m;
   vector<int>graph[n];
   for(int i=0;i<m;i++)
   {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
   }
   int src,dest;
   cin>>src>>dest;
   BFS(src,dest,graph);   
}
// Time Complexity :O(n!) Exponential
// As we are visited each node n-1 times, for checking the paths