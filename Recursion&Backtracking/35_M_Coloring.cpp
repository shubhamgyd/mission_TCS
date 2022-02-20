/*
Given an undirected graph and a number m, determine if the graph can be coloured with at most m 
colours such that no two adjacent vertices of the graph are colored with the same color. 
Here coloring of a graph means the assignment of colors to all vertices. 
*/

#include<bits/stdc++.h>
using namespace std;


bool isValid(int node,int color[],int graph[101][101],int n,int col)
{
    for(int i=0;i<n;i++)
    {
        if(i!=node && graph[i][node]==1 && color[i]==col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node,int graph[101][101],int color[],int m,int v)
{
    if(node==v)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(isValid(node,color,graph,v,i))
        {
            color[node]=i;
            if(solve(node+1,graph,color,m,v))
            {
                return true;
            }
            color[i]=0;
        }
    }
    return false;
}

bool graphColoring(int graph[101][101],int m,int v)
{
    int color[v]={0};
    if(solve(0,graph,color,m,v))
    {
        return true;
    }
    return false;
}
// Time Complexity:O(n^m)
// Space Complexity:O(n+m)



int main()
{

}