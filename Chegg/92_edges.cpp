#include<bits/stdc++.h>
using namespace std;

int main()
{
    int E;
    cin>>E;
    vector<pair<int,int>>adj[101];
    for(int i=0;i<E;i++)
    {
        int A,B,C;
        cin>>A>>B>>C;
        adj[A].push_back({B,0});
        adj[B].push_back({A,C});
    }

    int minCost=0;
    for(int i=1;i<101;++i)
    {
        if(adj[i].size()>0)
        {
            int edgeCost=solve(i,adj);
            minCost+=edgeCost;
        }
    }
    cout<<minCost<<endl;
}