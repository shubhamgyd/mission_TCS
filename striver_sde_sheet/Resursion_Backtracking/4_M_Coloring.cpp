
#include<bits/stdc++.h>
using namespace std;



bool isSafe(int node,int color[],vector<vector<int>>&graph,int N,int col)
{
    for(int k=0;k<N;k++)                             
    {
        if(k!=N && graph[k][node]==1 && color[k]==col)     
        {                                                  
            return false;          
        }
    }
    return true;                                  
}
bool solve(int src,int color[],vector<vector<int>>&graph,int m,int N)
{
    if(src==N)                     
    {
        return true;
    }
    for(int i=1;i<=m;i++)           
    {
        if(isSafe(src,color,graph,N,i))                  
        {
            color[src]=i;                               
            if(solve(src+1,color,graph,m,N)) return true; 
            color[src]=0;          
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int N=mat.size();
    int color[N+1];
    for(int i=0;i<=N;i++)
    {
        color[i]=0;
    }
    if(solve(0,color,mat,m,N)) return "YES";
    return "NO";
}