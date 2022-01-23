/*
War between Republic and Separatist is escalating. The Separatist are on a new offensive. 
They have started blocking the path between the republic planets (represented by integers), 
so that these planets surrender due to the shortage of food and supplies. The Jedi council 
has taken a note of the situation and they have assigned Jedi Knight Skywalker and his 
Padawan Ahsoka to save the critical planets from blockade (Those planets or system of
 planets which can be accessed by only one path and may be lost if that path is blocked 
 by separatist).

Skywalker is preparing with the clone army to defend the critical paths. He has assigned 
Ahsoka to find the critical planets. Help Ahsoka to find the critical planets(C) in 
ascending order. You only need to specify those planets which have only one path between 
them and they cannot be accessed by any other alternative path if the only path is compromised.

Constraints

M <= 10000
N <= 7000
Input

First line contains two space separated integers M and N, where M denotes the number 
of paths between planets and N denotes the number of planets.
Next M lines, each contains two space separated integers, representing the planet 
numbers that have a path between them.
Output

C lines containing one integer representing the critical planet that they need to 
save in ascending order of the planet number if no planet is critical then print -1

Time Limit

1

Examples

Example 1

Input

3 4

0 1

1 2

2 3

Output

0

1

2

3

Explanation

Since all the planets are connected with one path and cannot be accessed by any 
alternative paths hence all the planets are critical.
*/


#include<bits/stdc++.h>
using namespace std;


set<int>st;
void Bridges(int node,int parent,vector<int>&disc,vector<int>&low,vector<int>&vis,int &timer,vector<int>adj[])
{
    vis[node]=1;
    disc[node]=low[node]=timer++;
    for(auto it:adj[node])
    {
        if(it==parent)
        {
            continue;
        }
        if(!vis[it])
        {
            Bridges(it,node,disc,low,vis,timer,adj);
            low[node]=min(low[it],low[node]);
            if(low[it]>disc[node])
            {
                st.insert(node);
                st.insert(it);
            }
        }
        else
        {
            low[node]=min(low[node],disc[it]);
        }
    }
}




int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>graph[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>disc(n+1,-1);
    vector<int>low(n+1,-1);
    vector<int>vis(n+1,0);
    int timer=0;
    // Keep track on the discovery time of nodes
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            Bridges(i,-1,disc,low,vis,timer,graph);
        }
    }
    cout<<"Following are the critical points.."<<endl;
    for(auto it:st)
    {
        cout<<it<<endl;
    }
    return 0;
}
// Time Complexity:O(E(V+E))
// Space Complexity:O(V)