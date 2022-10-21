#include<bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

ordered_set o_set;
vector<bool>visited(1000+1,false);

void DFS(int i,vector<int>adj[])
{
    if(visited[i])
    {
        return;
    }
    o_set.insert(i);
    if(adj[i].size()==0)
    {

    }
}

int main()
{
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }

    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        int u=arr1[i];
        int v=arr2[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    DFS(1,adj);
}