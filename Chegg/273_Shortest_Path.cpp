#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
using namespace std;

// Fuction which prints the path
void pathToDest(vector<int> &parent, int i, int dest)
{
    // if hit to the parent
    // then reutrn
    if (parent[i] == -1)
    {
        return;
    }
    // else recur to the parent node
    pathToDest(parent, parent[i], dest);

    // print the nodes
    if (i == dest)
    {
        cout << i << endl;
    }
    else
        cout << i << "->";
}

int main()
{
    // Read file
    ifstream file("network01.txt");
    // String to read line by line
    string num;
    // get the number of nodes and the number of edges
    getline(file, num);
    stringstream ss(num);
    int n, m;
    int cnt = 0;
    while (ss >> num)
    {
        if (cnt == 0)
        {
            n = stoi(num);
            cnt++;
        }
        else
        {
            m = stoi(num);
        }
    }
    // to store the directed graph
    vector<pair<int, int>> adj[n + 1];
    // Read line by line and get the index, starting node, ending node and the edge weight
    while (getline(file, num))
    {
        int index, u, v, w;
        stringstream ss1(num);
        int cnt = 0;
        // iterate line
        while (ss1 >> num)
        {
            // get idnex
            if (cnt == 0)
            {
                index = stoi(num);
                cnt++;
            }
            // get sarting node
            else if (cnt == 1)
            {
                u = stoi(num);
                cnt++;
            }
            // get ending node
            else if (cnt == 2)
            {
                v = stoi(num);
                cnt++;
            }
            // get weight
            else
            {
                w = stoi(num);
            }
        }
        // push the edge into adjacency list
        adj[u].push_back({v, w});
    }
    // max-heap to get the minimum distance
    priority_queue<pair<int, int>> pq;
    // visited array to keep tracking on the visited nodes
    vector<bool> visited(n + 1, false);
    // distance array to get the distance from the starting to the ith node
    vector<int> dist(n + 1);
    // get the parent
    vector<int> parent(n + 1);
    // initalize all distances as INT_MAX
    for (int i = 0; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    // source node
    int s = 1;
    // target node
    int destination = 2;
    // source is zero distance from itself
    dist[s] = 0;
    // parent of s is -1
    parent[s] = -1;
    // push it into max-heap
    pq.push({0, s});
    // while not max-heap empty
    while (!pq.empty())
    {
        // get the top element
        int u = pq.top().second;
        pq.pop();
        // check it is visited or not
        if (visited[u])
            continue;
        // else
        else
        {
            // mark as visited
            visited[u] = true;
            // iterate it's neighbours
            for (auto ele : adj[u])
            {
                // get the ending node and weight of that edge
                int v = ele.first, w = ele.second;
                // check if distance of parent + edge is less than to the distace of ending node
                // if yes
                if (dist[u] + w < dist[v])
                {
                    // mark parent of v is u
                    parent[v] = u;
                    // update distance of v is disnce u + w
                    dist[v] = dist[u] + w;
                    // push into the heap
                    pq.push({-dist[v], v});
                }
            }
        }
    }
    // if target node is not visited
    // it means no edge is going from source to target
    if (visited[destination] == false)
    {
        cout << "No such valid path\n";
        return 0;
    }
    // else display Path and Path distance
    cout << "\n Path from " << s << " to " << destination << ": ";
    cout << s << "->";
    pathToDest(parent, destination, destination);
    cout << "\n Dist: " << dist[destination] << endl;
    return 0;
}