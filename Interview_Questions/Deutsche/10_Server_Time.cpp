/*
Servers Time:
In distributed computing, one of the common subroutines for the servers is to pass what they computed to one special server called master that uses those results they computed to combine them together.
Your company has N servers that are numbered from 1 to N, The master server has number N. Each server i can pass direct messages to servers i+sendTime[i] and i-sendTime[i] , providing that servers with those numbers exist. Passing a direct message lasts 1 second and message channels have an unlimited capacity which means that at any time many messages can be passing from one server to another. Now all servers want to pass their messages to the master server . How long would each server take to pass its messages to the master server?
The goal is to calculate, for each server, the minimum time needed to pass messages to the server . If there is a server which can't pass messages to the master, the answer for that server would be -1.
Example:
Lets say there are 5 servers and sendTime array is [1,3,1,3,4], then the following are the best way to pass messages from each server to master server
The first server can pass message to server 2, and then message is passed to server 5 from server 2, so it needed 2 seconds to reach master server 5.
The second server can pass messages to server 5 directly, which means it needed only 1 second to reach master server.
The third server can pass messages to server 2, and then server 2 can pass message to server 5 from server 2, So, message needed 2 seconds to reach master server.
The fourth server can pass message to server 1, and then message is passed to server 2, and then to server 5, So, message needed 3 seconds to reach master server.
The fifth server is the master server, it doesnt need any time to pass message to itself.
So final ans is:
[2,1,2,3,0],
Constraints:
2<=N<=10^5,
1<=sendTime[i]<=N
Input Format:
The first line contains N,number of elements in the distance array.
Each i of the N subsequent lines contains an integer indicates the distance that server i can pass messages to.
Sample Input:
4
3
4
2
1
Sample Output:
1
-1
2
0

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    vector<int>adj[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        int prev=i-nums[i];
        int next=i+nums[i];
        if(prev>=0)
        {
            adj[prev].push_back(i);
        }
        if(next<n)
        {
            adj[next].push_back(i);
        }
    }
    queue<int>q;
    vector<int>dist(n,-1);
    q.push(n-1);
    dist[n-1]=0;
    vector<bool>visited(n,false);
    while(!q.empty())
    {
        auto curr=q.front();q.pop();
        for(auto it:adj[curr])
        {
            if(dist[it]==-1)
            {
                q.push(it);
                dist[it]=1+dist[curr];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }
    return 0;
   
    
}