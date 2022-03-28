#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Adjacency Matrix
    int matrix[5][5]={{0,1,0,1,1},
                      {1,0,0,0,1},
                      {0,0,0,0,0},
                      {1,1,0,0,1},
                      {1,0,0,1,0},
                    };


    // Here we have given the adjacency matrix of a graph
    // while adding edge between two nodes we have to check that
    // both nodes are connected or not (i.e 1-> edge between u and v , 0-> no edge)
    // so while converting from adjacency matrix to adjacency list we will check for every other node
    // if there is a edge between current node to the other node, then we will make it bidirectional.


    // Here we are iterating matrix to check which nodes are conneted 

    // we are considering that, indexing start from 0
    vector<int>adj[5];             // Represent the adjacency list of bidirectional graph
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            // no self loop
            if(i!=j)
            {
                // if there is a edge between node i and node j (i.e matrix[i][j]==1)
                // then add edge between i and j
                if(matrix[i][j]==1)
                {
                    adj[i].push_back(j);                             // edge from node i to j
                }
            }
        }
    }

    // Printing the adjacency list of graph
    for(int i=0;i<5;i++)
    {
        cout<<i<<"--> [";

        // adjacent nodes of current node
        for(auto it:adj[i])
        {
            cout<<it<<",";
        }
        cout<<"]";
        cout<<endl;
    } 
    return 0;
}