#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define str string
#define MOD 1000000007
//#define num1 1000000
#define pie 3.14
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define Bob cout<<"Bob"<<endl
#define Alice cout<<"Alice"<<endl
#define sz(x) (int)(x).size()
#define newMOD 1000000006
const int MAX = 10000000;
const int size=2*1e9;


// The intuition behind this is , DFS or BFS traversal means but here we use 
// each nodes n-1 times i.e. n! to check any weight is greater than k or not

bool solve(int src,int k,vector<pair<int,int>>graph[],vector<bool>&visited)
{
    //step 1: Mark the source as true
    visited[src]=true;

    //step 2: check weather k is less than 0 or equal to 0 not , 
    // is yes then return true
    if(k<=0) return true;

    //step 3: iterate to its neighbours to check the given condition
    for(auto it:graph[src])
    {
        int u=it.first;
        int w=it.second;

        // if node is already visited , then proceed with next node
        if(visited[u]==true)
        {
            continue;
        }

        // if weight is greater than k , our condition satisfies , return true
        if(w>=k)
        {
            return true;
        }

        // if given condition don't satiefies then iterater to next node with 
        // k-w weight , coz we have w weight already 
        if(solve(u,k-w,graph,visited))
        {
            return true;
        }
    }
    visited[src]=false;        // this point help us to backtracking , coz we uses
    // each node n times so after one path we need to mark the visited nodes as false
    // so that for next path we can again use them

    return false;             // coz our condition doesn't satisfies
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fast();
    int n,e;
    cin>>n>>e;
    int k;
    cin>>k;
    vector<pair<int,int>>graph[n+1];
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        //cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<bool>visited(n+1,false);
    if(solve(1,k,graph,visited)==true)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
    return 0;
}