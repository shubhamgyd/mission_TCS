#include<bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
public:
    map<T, list<pair<T, T>>> adjlist;

    void addEdge(T u, T v, int dist, bool bidirec)
    {
        adjlist[u].push_back(make_pair(v, dist));
        if (bidirec)
        {
            adjlist[v].push_back(make_pair(u, dist));
        }
    }
    
    void BFS(T src, T goal)
    {
        map<T,bool> visited;
        priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> q;
        q.push(make_pair(0, src));
        while (!q.empty())
        {
            pair<T, T> top = q.top();
            q.pop();

            cout<<"-->"<<top.second;
            visited[top.second] = true;
    
            if (top.second == goal)
            {
                return;
            }
            
            for (auto adj : adjlist[top.second])
            {
                if (!visited[adj.first])
                {   
                    q.push(make_pair(adj.second, adj.first));
                }
            }
        }
    }
};

int32_t main()
{
    graph<char> g;
    // g.addEdge('S', 'A', 3, 1);
    // g.addEdge('S', 'B', 6, 1);
    // g.addEdge('S', 'C', 5, 1);
    // g.addEdge('A', 'D', 9, 1);
    // g.addEdge('A', 'E', 8, 1);
    // g.addEdge('B', 'F', 12, 1);
    // g.addEdge('B', 'G', 14, 1);
    // g.addEdge('C', 'H', 7, 1);
    // g.addEdge('H', 'I', 5, 1);
    // g.addEdge('H', 'J', 6, 1);
    // g.addEdge('I', 'K', 1, 1);
    // g.addEdge('I', 'L', 10, 1);
    // g.addEdge('I', 'M', 2, 1);
    cout<<"Enter number of edges you want: ";
    int n;
    cin>>n;
    while(n--)
    {
        cout<<"Enter source destinaion and weight: ";
        int u,v,w;
        cin>>u>>v>>w;
        int direction=0;
        cout<<"You want to make graph directional or bidirectional: (enter 0(directional)/1(bidirectional): ";
        cin>>direction;
        g.addEdge(u,v,w,direction);
    }
    cout<<"Enter source: ";
    int src;
    cin>>src;
    cout<<"Enter destination: ";
    int dest;
    cin>>dest;
    cout << "Best First Search (BFS Variation)" << endl;
    g.BFS(src,dest);
    return 0;
}

/*
worst case time complexity for Best First Search is O(n * Log n) 
where n is number of nodes. In worst case, we may have to visit all nodes 
before we reach goal. Note that priority queue is implemented using Min(or Max) Heap,
 and insert and remove operations take O(log n) time.

*/