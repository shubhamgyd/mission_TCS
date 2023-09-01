#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// DFS algorithm
void DFS(int src, vector<pair<int, int>> graph[], vector<bool> &visited)
{
    // else mark it as visited and explore it
    visited[src] = true;

    // Explore all other non visited vertices
    for (auto node : graph[src])
    {
        if (!visited[node.first])
        {
            // print node and it's weight
            cout << src << " -> " << node.first << " = " << node.second << endl;
            DFS(node.first, graph, visited);
        }
    }
}

int main()
{
    std::string line;
    std::ifstream file("graph.txt");
    int n, m;
    // adjancency list graph representation
    vector<pair<int, int>> graph[1000];

    // If file is exist
    if (file.is_open())
    {
        // Read file line by line
        int start = 0;
        while (std::getline(file, line))
        {
            // If first line
            // Then extract n and m from tha line
            if (start == 0)
            {
                stringstream ss(line);
                string number;
                int ind = 0;
                while (ss >> number)
                {
                    if (ind == 0)
                    {
                        n = stoi(number);
                        ++ind;
                    }
                    else
                    {
                        m = stoi(number);
                    }
                }
                graph->resize(n);
                start++;
            }
            else
            {
                // Extract all source , destination and weight
                stringstream ss(line);
                string number;
                int ind = 0;
                int src, dest, weight;
                while (ss >> number)
                {
                    // Extract source
                    if (ind == 0)
                    {
                        src = stoi(number);
                        ind++;
                    }
                    // Extract destination
                    else if (ind == 1)
                    {
                        dest = stoi(number);
                        ind++;
                    }
                    // Extract weight
                    else
                    {
                        weight = stoi(number);
                    }
                }
                // Push the nodes into the graph
                graph[src].push_back({dest, weight});
                graph[dest].push_back({src, weight});
                if (ind >= 2)
                {
                    ind = 0;
                }
            }
        }
        file.close();
    }
    // else show error msg
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }

    // Now Traverse the graph using DFS Algorithm
    // Here we are going to choose 0 as our starting vertex
    // We will traverse from 0 to all other vertices

    // Make one visited array to track on the visited nodes

    vector<bool> visited(n, false);
    DFS(0, graph, visited);
    return 0;
}