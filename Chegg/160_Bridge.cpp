#include <iostream>
#include <vector>
using namespace std;

// Utility function which get the users from which connection get disconnected
void getTriggerUsers(int node, int parent, vector<int> &visited, vector<int> &timeOfInsertion, vector<int> &lowInserted, int &timer, vector<int> graph[], vector<int> &isArticulationPoint)
{
    // makr the current node as visited
    visited[node] = 1;
    // assign the time to the current node
    timeOfInsertion[node] = timer;
    // also lower of current node is itself
    lowInserted[node] = timer;
    // Increment the timer
    // so that for it's child time will be assign according to their
    // time of insertions
    timer++;
    // keep track on number of childrens of current node
    int children = 0;
    // explore all neighbour nodes of current node
    for (auto it : graph[node])
    {
        // if cycle then continue
        if (it == parent)
        {
            continue;
        }
        // if neighbour node is not visited
        if (!visited[it])
        {
            // Do DFS from that node and explore all nodes from that node
            getTriggerUsers(it, node, visited, timeOfInsertion, lowInserted, timer, graph, isArticulationPoint);
            // update the low of parent and child
            lowInserted[node] = min(lowInserted[node], lowInserted[it]);
            // Increment the children
            children++;
            // if low of child is greater than or equal to the time of insertions of parent
            // and parent is not -1
            // then mark this node as a trigger user
            if (lowInserted[it] >= timeOfInsertion[node] && parent != -1)
            {
                isArticulationPoint[node] = 1;
            }
        }
        // if neighbour is visited
        else
        {
            // update the low of parent
            if (lowInserted[node] < timeOfInsertion[it])
            {
                lowInserted[node] = lowInserted[node];
            }
            else
            {
                lowInserted[node] = timeOfInsertion[it];
            }
        }
    }

    // if current node has greater than 1 children
    // and there is no cycle found
    // then aslo mark this current node as a trigger user
    if (parent == -1 && children > 1)
    {
        isArticulationPoint[node] = 1;
    }
}
int main()
{
    // get number of nodes and the edges
    int n, m;
    cin >> n >> m;
    // make adjacency list graph
    vector<int> graph[n];
    // keep track on time of insertion of nodes
    vector<int> timeOfInsertion(n, -1);
    // keep track on lower inserted node
    vector<int> lowInserted(n, -1);
    // keep track on visited nodes
    vector<int> visited(n, 0);
    // get the triggered users
    vector<int> isArticulationPoint(n, 0);
    // add bidirectional edges into the adjacency list graph
    for (int i = 0; i < m; i++)
    {
        // node1 , node2
        int u, v;
        cin >> u >> v;
        // make 0 based nodes
        u--;
        v--;
        // make direction from node1 to node2
        graph[u].push_back(v);
        // make direction from node2 to node1
        graph[v].push_back(u);
    }
    // keep track on the timer of insertion of nodes
    int timer = 0;
    // iterate from each node
    for (int i = 0; i < n; i++)
    {
        // check node is visited or not
        if (!visited[i])
        {
            // Do DFS from node i and explore all possible nodes
            getTriggerUsers(i, -1, visited, timeOfInsertion, lowInserted, timer, graph, isArticulationPoint);
        }
    }

    // get the count of users
    int triggerUser = 0;
    // Iterate all users
    for (int i = 0; i < n; i++)
    {
        // if user i is remove and connection get disconnected
        // increment the user
        if (isArticulationPoint[i] == 1)
            triggerUser++;
    }
    // Display user
    cout << triggerUser << endl;
    return 0;
}

/*

            1
              \
                2
                 \
                  3
                   \
                    4

*/