#include<iostream>
#include<vector>
using namespace std;


int main()
{
    // In a given graph we have total 9 nodes
    // starting from 0 to 8
    // so for adjacency matrix we need 9x9 matrix
    // and for adjacency list we need 9 size of array list

    int N=9;

    // Represent the adjacecny matrix
    // Initialize with 0
    // means initially no any node is connected
    vector<vector<int>>matrix(N,vector<int>(N,0));

    // According the given graph
    // if  node1 is connected to node2 then add and edge from node1 to node2 i.e. add 1 at matrix[node1][node2]=1
    // if node is not connected then it remains disconnected


    // Basiclly given graph is directed graph

    // 0 and 1 is connected  i.e 0-->1
    matrix[0][1]=1;

    // 1 and 2 is connected  i.e 1--->2
    matrix[1][2]=1;

    // 2 and 4 is connected i.e 2-->4
    matrix[2][4]=1;

    // 0 and 3 is connected i.e 0-->3
    matrix[0][3]=1;

    //3 and 6 is connected i.e 3-->6
    matrix[3][6]=1;

    //6 and 7 is connected i.e 6-->7
    matrix[6][7]=1;

    // 3 and 5 is connected i.e 3-->5
    matrix[3][5]=1;

    // 6 and 8 is connected i.e. 6->8
    matrix[6][8]=1;


    // Now print the adjacency matrix
    // we have 9 nodes
    // 0 represent i and j is disconnected and
    // 1 represent i and j is connected
    cout<<"Adjacency Matrix Representation: "<<endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    // Now create a adjacency list to store the elements
    vector<int>adj[9];

    // 0 and 1 is connected
    adj[0].push_back(1);

    // 1 and 2 is connected  i.e 1--->2
    adj[1].push_back(2);

    // 2 and 4 is connected i.e 2-->4
    adj[2].push_back(4);

    // 0 and 3 is connected i.e 0-->3
    adj[0].push_back(3);

    //3 and 6 is connected i.e 3-->6
    adj[3].push_back(6);

    //6 and 7 is connected i.e 6-->7
    adj[6].push_back(7);

    // 3 and 5 is connected i.e 3-->5
    adj[3].push_back(5);

    // 6 and 8 is connected i.e. 6->8
    adj[6].push_back(8);

    // Now print the adjacency list
    cout<<"\nAdjacency List Representation: "<<endl;
    for(int i=0;i<N;i++)
    {
        // Print all nodes we are adjacent to node i
        cout<<i<<"-> [";
        // Adjacnet nodes of i
        for(auto it:adj[i])
        {
            cout<<it<<",";
        }
        cout<<"]";
        cout<<endl;
    }
}