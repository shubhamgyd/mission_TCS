#include <iostream>
#include <map>
#include <vector>
using namespace std;

// DFS function which do a dfs traversal from provided vertex
// it goes to the deepest traversable vertex and explore all neighbouring vertices
void DFS(string src, map<string, vector<string>> &adjacentMatrixGraph, map<string, bool> &visited)
{
    // if vertex is already visited, then ignore it
    // and return
    if (visited[src])
    {
        return;
    }
    // else mark it as visited
    visited[src] = true;
    // print it
    cout << src << " ";
    // Explore it's neighbouring vertices
    for (auto it : adjacentMatrixGraph[src])
    {
        // Do DFS for neighbouring vertices
        DFS(it, adjacentMatrixGraph, visited);
    }
}

int main()
{
    // Structure to store graph
    map<string, vector<string>> adjacentMatrixGraph;
    // add each edge into the graph and vertices
    adjacentMatrixGraph["North Cascades"].push_back("Mount Rainer");
    adjacentMatrixGraph["North Cascades"].push_back("Glacier");
    adjacentMatrixGraph["Mount Rainier"].push_back("Crater Lake");
    adjacentMatrixGraph["Mount Rainier"].push_back("Great Basin");
    adjacentMatrixGraph["Crater Lake"].push_back("Red Wood");
    adjacentMatrixGraph["Red Wood"].push_back("Yosemite");
    adjacentMatrixGraph["Yosemite"].push_back("Great Basin");
    adjacentMatrixGraph["Yosemite"].push_back("Sequoia");
    adjacentMatrixGraph["Sequoia"].push_back("Joshua Tree");
    adjacentMatrixGraph["Sequoia"].push_back("Saguaro");
    adjacentMatrixGraph["Joshua Tree"].push_back("Grand Canyon");
    adjacentMatrixGraph["Grand Canyon"].push_back("Saguaro");
    adjacentMatrixGraph["Grand Canyon"].push_back("Saguaro");
    adjacentMatrixGraph["Grand Canyon"].push_back("Petrified Forest");
    adjacentMatrixGraph["Great Basin"].push_back("Grand Canyon");
    adjacentMatrixGraph["Great Basin"].push_back("Canyonlands");
    adjacentMatrixGraph["Petrified Forest"].push_back("Mesa Verde");
    adjacentMatrixGraph["Mesa Verde"].push_back("Great Sand Dunes");
    adjacentMatrixGraph["Canyonlands"].push_back("Great Sand Dunes");
    adjacentMatrixGraph["Canyonlands"].push_back("Rocky Mountain");
    adjacentMatrixGraph["Glacier"].push_back("Yellow Stone");
    adjacentMatrixGraph["Yellow Stone"].push_back("Grand Teton");
    adjacentMatrixGraph["Grand Teton"].push_back("Rocky Mountain");
    adjacentMatrixGraph["Grand Teton"].push_back("Wind Cave");
    adjacentMatrixGraph["Yellow Stone"].push_back("Theodore Roosevelt");
    adjacentMatrixGraph["Theodore Roosevelt"].push_back("Voyaguers");
    adjacentMatrixGraph["Voyaguers"].push_back("Isle Royale");
    adjacentMatrixGraph["Voyaguers"].push_back("Gateway Arc");
    adjacentMatrixGraph["Wind Cave"].push_back("Gateway Arc");
    adjacentMatrixGraph["Great Sand Dunes"].push_back("Hot Springs");
    adjacentMatrixGraph["Saguaro"].push_back("Carlsbad Caverns");
    adjacentMatrixGraph["Carlsbad Caverns"].push_back("Big Bend");
    adjacentMatrixGraph["Big Bend"].push_back("Hot Springs");
    adjacentMatrixGraph["Gateway Arc"].push_back("Hot Springs");
    adjacentMatrixGraph["Isle Royale"].push_back("Indiana Dunes");
    adjacentMatrixGraph["Gateway Arc"].push_back("Indiana Dunes");
    adjacentMatrixGraph["Indiana Dunes"].push_back("Mammoth Cave");
    adjacentMatrixGraph["Hot Springs"].push_back("Mammoth Cave");
    adjacentMatrixGraph["Mammoth Cave"].push_back("Great Smoky Mountains");
    adjacentMatrixGraph["Indiana Dunes"].push_back("Cuyahoga Valley");
    adjacentMatrixGraph["Cuyahoga Valley"].push_back("Acadia");
    adjacentMatrixGraph["Cuyahoga Valley"].push_back("Shenandoah");
    adjacentMatrixGraph["Acadia"].push_back("Shenandoah");
    adjacentMatrixGraph["Shenandoah"].push_back("Great Smoky Mountains");
    adjacentMatrixGraph["Great Smoky Mountains"].push_back("Congaree");
    adjacentMatrixGraph["Congaree"].push_back("Biscayne");

    // keep track on vertex is visited or not
    map<string, bool> visited;
    // Iterate graph
    for (auto it : adjacentMatrixGraph)
    {
        // if vertex is not visited
        // then do DFS from this vertex
        if (!visited[it.first])
        {
            // function call for DFS from non visites vertex
            DFS(it.first, adjacentMatrixGraph, visited);
        }
    }
    return 0;
}