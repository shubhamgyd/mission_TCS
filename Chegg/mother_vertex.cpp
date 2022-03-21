#include <bits/stdc++.h>

using namespace std;

// Utility function do the DFS traversal from the node u and it will mark the nodes,in it's path

void dfs(int u, vector<int> adj[], bool visited[])

{

    if (visited[u])
        return;

    visited[u] = true;

    for (auto v : adj[u])
    {

        if (!visited[v])

        {

            dfs(v, adj, visited);
        }
    }
}

// Utility function do the transpose of a graph and store it into a adjacency list

void getTransposeGraph(vector<int> adj[], vector<int> trans_adj[], int n)

{

    for (int u = 0; u < n; u++)
    {

        for (auto v : adj[u])
        {

            trans_adj[v].push_back(u);
        }
    }
}

// Initializing all elements as a false of visited array

void Memset(bool visited[], int n)

{

    for (int u = 0; u < n; u++)

    {

        visited[u] = false;
    }
}

// Utility function find all the mother vertex , if there is no any other mother vertex then,

// it will return -1

vector<int> findMotherVertices(vector<int> adj[], int nodes)

{

    int n = nodes;

    bool visited[n];

    // Find any mother vertex

    // in given graph, G

    Memset(visited, n);

    int last_dfs_node = -1;

    for (int u = 0; u < n; u++)
    {

        // find the first node which is not visited anymore as a mother vertex

        if (!visited[u])
        {

            dfs(u, adj, visited);

            last_dfs_node = u;
        }
    }

    // check we can reach all other vertices from the last_dfs_node

    Memset(visited, n);

    dfs(last_dfs_node, adj, visited);

    // check all nodes are visited or not from the mother vertex

    // if any node is not visited then, return -1

    for (int u = 0; u < n; u++)
    {

        // Check of the mother vertex

        // exist else return -1

        if (!visited[u])
        {

            vector<int> emptyList;

            emptyList.push_back(-1);

            return emptyList;
        }
    }

    // Now in G_transpose, do DFS

    // from that mother vertex,

    // and we will only reach the

    // other mother vertices of G

    int motherVertex = last_dfs_node;

    // trans_adj is the transpose

    // of the given Graph

    vector<int> trans_adj[n];

    // do transpose of the graph

    getTransposeGraph(adj, trans_adj, n);

    // Do DFS from that mother vertex

    // in the transpose graph and the

    // visited nodes are all the

    // mother vertices of the given

    // graph G

    Memset(visited, n);

    dfs(motherVertex, trans_adj, visited);

    // Vector to store the list

    // of mother vertices

    vector<int> result;

    for (int u = 0; u < n; u++)
    {

        if (visited[u])

        {

            // push the mother vertex into final result

            result.push_back(u);
        }
    }

    // Return the list of all mother vertices

    return result;
}

int main()

{

    int V = 8;

    // Adjacency list represntation

    vector<int> adj[V];

    adj[0].push_back(1);

    adj[1].push_back(2);

    adj[1].push_back(4);

    adj[1].push_back(5);

    adj[2].push_back(3);

    adj[2].push_back(6);

    adj[3].push_back(2);

    adj[3].push_back(7);

    adj[4].push_back(0);

    adj[4].push_back(5);

    adj[5].push_back(6);

    // Function call to find the mother vertices

    vector<int> motherVertices = findMotherVertices(adj, V);

    // if no mother vertex exist

    if (motherVertices[0] == -1)

    {

        cout << "No any mother vertex exists";
    }

    else
    {

        cout << "All Mother vertices of the graph are : ";

        for (int v : motherVertices)

        {

            cout << v << " ";
        }
    }

    return 0;
}