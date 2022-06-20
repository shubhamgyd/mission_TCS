/*
Given an array containing one digit numbers only, assuming we are standing at first index,
 we need to reach to end of array using minimum number of steps where in one step, 
 we can jump to neighbor indices or can jump to a position with same value.
In other words, if we are at index i, then in one step you can reach to, arr[i-1] or arr[i+1] 
or arr[K] such that arr[K] = arr[i] (value of arr[K] is same as arr[i])
*/

#include<bits/stdc++.h>
using namespace std;


// Basically his is purely graph based question
// we have to add edge betwen same occurance indices element


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    vector<int>adj[100];
    for(int i=1;i<n;i++)
    {
        adj[res[i]].push_back(i);
    }
    int dist[100];
    vector<bool>visited(100,false);
    queue<int>q;
    visited[0]=true;
    dist[0]=0;
    q.push(0);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==n-1)
        {
            break;
        }
        int d=res[u];
        for(int i=0;i<adj[d].size();i++)
        {
            if(!visited[adj[d][i]])
            {
                visited[adj[d][i]]=true;
                q.push(adj[d][i]);
                dist[adj[d][i]]=dist[u];
            }
        }
        adj[d].clear();


        // check the availability of previous index
        if(u-1>=0 and !visited[u-1])
        {
            visited[u-1]=true;
            q.push(u-1);
            dist[u-1]=dist[u]+1;
        }


        // check the availability of next index
        if(u+1<n and !visited[u+1])
        {
            visited[u+1]=true;
            q.push(u+1);
            dist[u+1]=dist[u]+1;
        }
    }
    cout<<"Min Cost: "<<dist[n-1]<<endl;
}
// Time Complexity::O(n+e)
// Space Complexity:O(n)