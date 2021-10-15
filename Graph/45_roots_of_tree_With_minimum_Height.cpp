
/*
Given an undirected graph, which has tree characteristics. It is possible to 
choose any node as root, the task is to find those nodes only which minimize
 the height of tree. 
*/
#include <bits/stdc++.h>
using namespace std;


int BFS(int src,vector<int>res[],int n)
{
    int dist[n+1];
    for(int i=1;i<=n;i++)
    {
        dist[i]=0;
    }
    vector<bool>visited(n+1,false);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    visited[src]=true;
    while(!q.empty())
    {
        auto ele=q.front();
        q.pop();
        for(auto it:res[ele])
        {
            if(visited[it])
            {
                continue;
            }
            else
            {
                visited[it]=true;
                dist[it]=dist[ele]+1;
                q.push(it);
            }
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,dist[i]);
    }
    return mx;
}

bool cmp(pair<int,int>a,pair<int,int>b)
{
    return (a.first>b.first);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vector<int>res[n+1];
    int incoming[n+1];
    memset(incoming,0,sizeof(incoming));
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        res[u].push_back(v);
        res[v].push_back(u);
        incoming[u]++;
        incoming[v]++;
    }
    vector<pair<int,int>>nodes;
    for(int i=1;i<=n;i++)
    {
        nodes.push_back({incoming[i],i});
    }
    sort(nodes.begin(),nodes.end(),cmp);
    int val=INT_MAX;
    int root;
    vector<int>ans;
    for(auto it:nodes)
    {
        int src=it.second;
        int temp=BFS(src,res,n);
        // cout<<src<<" "<<temp<<endl;
        if(temp<val)
        {
            if(ans.empty())
            {
                ans.push_back(src);
            }
            else
            {
                ans.pop_back();
                ans.push_back(src);
            }
            val=temp;
        }
        else if(temp==val)
        {
            ans.push_back(src);
            val=temp;
        }
        else{
            break;
        }
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
	return 0;
}

// Time Complexity :O(n*(v+e))


















// Alternative Solution 
// With Time Complexity :O(n)

// C++ program to find root which gives minimum height to tree
#include <bits/stdc++.h>
using namespace std;

// This class represents a undirected graph using adjacency list
// representation
class Graph
{
public:
    int V; // No. of vertices

    // Pointer to an array containing adjacency lists
    list<int> *adj;

    // Vector which stores degree of all vertices
    vector<int> degree;

    Graph(int V);        // Constructor
    void addEdge(int v, int w); // To add an edge

    // function to get roots which give minimum height
    vector<int> rootForMinimumHeight();
};

// Constructor of graph, initializes adjacency list and
// degree vector
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    for (int i = 0; i < V; i++)
        degree.push_back(0);
}

// addEdge method adds vertex to adjacency list and increases
// degree by 1
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list
    adj[w].push_back(v); // Add v to w’s list
    degree[v]++;         // increment degree of v by 1
    degree[w]++;         // increment degree of w by 1
}

// Method to return roots which gives minimum height to tree
vector<int> Graph::rootForMinimumHeight()
{
    queue<int> q;

    // first enqueue all leaf nodes in queue
    for (int i = 0; i < V; i++)
        if (degree[i] == 1)
            q.push(i);

    // loop until total vertex remains less than 2
    while (V > 2)
    {
        V=V-q.size();
        int tmp=q.size();
        for (int i = 0; i < tmp; i++)
        {
            int t = q.front();
            q.pop();

            // for each neighbour, decrease its degree and
            // if it become leaf, insert into queue
            for (auto j = adj[t].begin(); j != adj[t].end(); j++)
            {
                degree[*j]--;
                if (degree[*j] == 1)
                q.push(*j);
            }
        }
    }

    // copying the result from queue to result vector
    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}


// Driver code
int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    Graph g(6);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(5, 4);

    // Function Call
    vector<int> res = g.rootForMinimumHeight();
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}









