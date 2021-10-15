#include<bits/stdc++.h>
using namespace std;



/*
Algorithm:

What if graph is not complete?
Follow the given procedure :-
STEP 1: Create Adjacency Matrix for the given graph.
STEP 2: Replace all the diagonal elements with the degree of nodes. For eg. element at (1,1) position of adjacency matrix will be replaced by the degree of node 1, element at (2,2) position of adjacency matrix will be replaced by the degree of node 2, and so on.
STEP 3: Replace all non-diagonal 1’s with -1.
STEP 4: Calculate co-factor for any element.
STEP 5: The cofactor that you get is the total number of spanning tree for that graph.
*/


int findDegree(int node,vector<vector<int>>&graph,int n)
{
    int degree=0;
    for(int i=0;i<=n;i++)
    {
        if(graph[node][i]==1)
        {
            degree++;
        }
    }
    return degree;
}

double d=0;
double det(int n, double mat[10][10])
{
    int c, subi, i, j, subj;
    double submat[10][10];  
    if (n == 2) 
    {
        return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {  
        for(c = 1; c <=n; c++)
        {  
            subi = 0;  
            for(i = 2; i <=n; i++)
            {  
                subj = 0;
                for(j = 1; j <=n; j++)
                {    
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
        d = d + (pow(-1 ,c) * mat[1][c] * det(n - 1 ,submat));
        }
    }
    return d;
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    vector<vector<int>>graph(nodes+1,vector<int>(nodes+1,0));
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    for(int i=0;i<=nodes;i++)
    {
        int degree=findDegree(i,graph,nodes);
        // cout<<"Degree of "<<i<<" is "<<degree<<endl;
        graph[i][i]=degree;
    }
    for(int i=0;i<=nodes;i++)
    {
        for(int j=0;j<=nodes;j++)
        {
            if(i!=j && graph[i][j]==1)
            {
                graph[i][j]=-1;
            }
        }
    }
    cout<<endl;
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

}