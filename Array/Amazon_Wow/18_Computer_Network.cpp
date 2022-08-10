#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

// bool dfs(vector<int>graph[],int src,vector<bool>&visited)
// {
// 	if(visited[src])
// 	{
// 		return false;
// 	}
// 	visited[src]=true;
// 	for(auto it:graph[src])
// 	{
// 		return dfs(graph,it,visited);
// 	}
// 	return true;
// }

// int32_t main()
// {
// 	fast();
// 	int n,m;
// 	cin>>n>>m;
//     int start[n+1];
//     int end[n+1];
//     for(int i=0;i<m;i++)
//     {
//         cin>>start[i];
//     }
//     for(int i=0;i<m;i++)
//     {
//         cin>>end[i];
//     }
// 	vector<int>graph[n+1];
// 	vector<int>incoming(n+1,0);
// 	for(int i=0;i<m;i++)
// 	{
// 		int u,v;
// 		u=start[i];
//         v=end[i];
// 		graph[u].push_back(v);
// 		graph[v].push_back(u);
// 		incoming[u]++;
// 		incoming[v]++;
// 	}
// 	int one=count(incoming.begin(),incoming.end(),1);
// 	int mx=count(incoming.begin(),incoming.end(),n-1);
// 	int two=count(incoming.begin(),incoming.end(),2);
// 	if(one==n-1 && mx==1)
// 	{
// 		cout<<"2"<<endl;
// 	}
// 	else if(two==n-2 && one==2)
// 	{
// 		cout<<"1"<<endl;
// 	}
// 	else if(two==n)
// 	{
// 		cout<<"3"<<endl;
// 	}
// 	else
// 	{
// 		cout<<"-1"<<endl;
// 	}

// 	return 0;
// }

bool checkBusTopologyUtil(vector<int> adj[], int V, int E)
{

    if (E != (V - 1))
        return false;

    if (V == 1)
        return true;

    int *vertexDegree = new int[V + 1];
    memset(vertexDegree, 0, sizeof vertexDegree);
    for (int i = 1; i <= V; i++)
    {
        for (auto v : adj[i])
        {
            vertexDegree[v]++;
        }
    }

    int countDegree2 = 0, countDegree1 = 0;
    for (int i = 1; i <= V; i++)
    {
        if (vertexDegree[i] == 2)
        {
            countDegree2++;
        }
        else if (vertexDegree[i] == 1)
        {
            countDegree1++;
        }
        else
        {
            return false;
        }
    }
    if (countDegree1 == 2 && countDegree2 == (V - 2))
    {
        return true;
    }
    return false;
}

bool checkBusTopology(vector<int> adj[], int V, int E)
{
    bool isBus = checkBusTopologyUtil(adj, V, E);
    return isBus;
}

bool checkStarTopologyUtil(vector<int> adj[], int V, int E)
{
    if (E != (V - 1))
        return false;
    if (V == 1)
        return true;

    int *vertexDegree = new int[V + 1];
    memset(vertexDegree, 0, sizeof vertexDegree);
    for (int i = 1; i <= V; i++)
    {
        for (auto v : adj[i])
        {
            vertexDegree[v]++;
        }
    }
    int countCentralNodes = 0, centralNode = 0;

    for (int i = 1; i <= V; i++)
    {
        if (vertexDegree[i] == (V - 1))
        {
            countCentralNodes++;
            centralNode = i;
        }
    }
    if (countCentralNodes != 1)
        return false;

    for (int i = 1; i <= V; i++)
    {
        if (i == centralNode)
            continue;
        if (vertexDegree[i] != 1)
        {
            return false;
        }
    }

    return true;
}

bool checkStarTopology(vector<int> adj[], int V, int E)
{
    bool isStar = checkStarTopologyUtil(adj, V, E);
    return isStar;
}

bool checkRingTopologyUtil(vector<int> adj[], int V, int E)
{

    if (E != V)
        return false;

    if (V <= 2)
        return false;

    int *vertexDegree = new int[V + 1];
    memset(vertexDegree, 0, sizeof vertexDegree);

    for (int i = 1; i <= V; i++)
    {
        for (auto v : adj[i])
        {
            vertexDegree[v]++;
        }
    }

    int countDegree2 = 0;

    for (int i = 1; i <= V; i++)
    {
        if (vertexDegree[i] == 2)
        {
            countDegree2++;
        }
    }

    if (countDegree2 == V)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkRingTopology(vector<int> adj[], int V, int E)
{
    bool isRing = checkRingTopologyUtil(adj, V, E);
    if (isRing)
    {
        cout << "YES" << endl;
        return true;
    }
    else
    {
        cout << "NO" << endl;
        return false;
    }
}

// #include<bits/stdc++.h>
// using namespace std;

signed main()
{
    // fast();
    int n, m;
    cin >> n >> m;
    int start[m];
    int end[m];
    for (int i = 0; i < m; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> end[i];
    }
    vector<int> adj[n + 5];
    for (int i = 0; i < m; i++)
    {
        int u = start[i];
        int v = end[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (checkRingTopology(adj, n, m))
    {
        cout << 3 << endl;
        return 0;
    }
    if (checkBusTopology(adj, n, m))
    {
        cout << 1 << endl;
        return 0;
    }
    if (checkStarTopology(adj, n, m))
    {
        cout << 2 << endl;
        return 0;
    }
    else
    {
        cout << -1 << endl;
    }
    // if(n==m)
    // {
    //     cout<<3<<endl;
    //     return 0;
    // }
    // else if(n>m)
    // {
    //     if(start[m-1]==end[0])
    //     {
    //         cout<<1<<endl;
    //         return 0;
    //     }
    //     else
    //     {
    //         for(int i=0;i<m;i++)
    //         {
    //             for(int j=0;j<m;j++)
    //             {
    //                 if(start[i]==end[j])
    //                 {
    //                     cout<<2<<endl;
    //                     return 0;
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout<<-1<<endl;

    // if (input1 == 3)
    // {
    //     if (input2 == 3)
    //     {
    //         return 3;
    //     }
    //     else
    //     {
    //         return 1;
    //     }
    // }
    // else
    // {
    //     return 2;
    // }

    return 0;
}